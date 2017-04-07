#include <stdlib.h>
#include <ctime>
using namespace std;

int main()
{
	system("sudo modprobe bcm2835-v412");
	system("./FaceDetect");
	while(1)
	{
		time_t t=time(0);
		struct tm * now = localtime(&t);
		if(now->tm_hour == 0 && now->tm_min == 0 && now-> tm_sec == 0)
		{
			system("killall FaceDetect");
			system("./FaceDetect");
		} 
	}
}