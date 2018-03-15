#include "Jobs.h"
#include <iostream>

using std::cout;
using std::endl;

Jobs::Jobs()
{
  jobName = "";
  arrivedTime = 0;
  jobDuration = 0;
}

void Jobs::setjobName(string a)
{
  jobName = a;
}
void Jobs::setArrivedTime(int b)
{
  arrivedTime = b;
}
void Jobs::setjobDuration(int c)
{
  jobDuration = c;
}

string Jobs::getjobName()
{
  return jobName;
}

int Jobs::getArrivedTime()
{
  return arrivedTime;
}

int Jobs::getjobduration()
{
  return jobDuration;
}

Jobs::~Jobs()
{
}
