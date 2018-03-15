//to code
#include "Jobs.h"
#include "stdafx.h"


Jobs::Jobs()
{
	string JobName = "";
	int ArrivalTime = 0;
	int JobDuration = 0;
}

void Jobs::setJobName(string a)
{
	JobName = a;
}

void Jobs::setArrivalTime(int b)
{
	ArrivalTime = b;
}

void Jobs::setJobDuration(int c)
{
	JobDuration = c;
}

string Jobs::getJobname()
{
	return JobName;
}

int Jobs::getArrvalTime()
{
	return ArrivalTime;
}

int Jobs::getJobDuration()
{
	return JobDuration;
}
