#include "Header.h"

void cal()
{
	ifstream in("data.txt");
	ofstream out;
	out.open("state.txt",fstream::app);
	vector<int> store;
	int x;
	int zero_flag = 0;
	while (!in.fail())
	{
		in >> x;
		if(x>0)
			zero_flag++;
		store.push_back(x);
	}
	//---cal start here
	double average = accumulate(store.begin(), store.end(), 0.0) / store.size();
	double stdev = calculateSD(store);

	float compare = (average - 30) / (stdev / sqrt(store.size()));
	float compare1 = (average - 2) / (stdev / sqrt(store.size()));
	if (compare >= 1.644854) //full
	{
		out << "full" << endl;
	}
	else if (compare1 >= 1.644854) //half-full
	{
		out << "half-full" << endl;
	}
	else if(zero_flag <= 2)     //empty
	{
		out << "empty" << endl;
	}
	else
	{
		out << "a few people" << endl;
	}
	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );
    	out << (now->tm_year + 1900) << '-' 
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
	 << '-'
	 << now-> tm_hour
	 << '-'
         << now-> tm_min
	 << '-'
	 << now-> tm_sec
	 << endl;
	out.close();
}

float calculateSD(vector<int> data)
{
	float sum = 0.0, mean, standardDeviation = 0.0;

	int i;

	for (i = 0; i < data.size(); ++i)
	{
		sum += data[i];
	}

	mean = sum / (data.size());

	for (i = 0; i < data.size(); ++i)
		standardDeviation += pow(data[i] - mean, 2);

	return sqrt(standardDeviation / (data.size()-1));
}
