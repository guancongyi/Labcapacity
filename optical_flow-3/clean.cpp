#include "Header.h"

void clean()
{
	time_t t=time(0);
	struct tm * now = localtime(&t);
	if(now->tm_hour == 0 && now->tm_min == 0 && now-> tm_sec == 0)
	{
		ofstream out("state.txt");
		out.open("state.txt");
	 }
}