#pragma once
#include<iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Jobs
{
private:
	string JobName;
	int ArrivalTime;
	int JobDuration;
public:
	Jobs();
	void setJobName(string A);
	void setArrivalTime(int b);
	void setJobDuration(int c);

	string getJobname();
	int getArrvalTime();
	int getJobDuration();

	~Jobs();
};
