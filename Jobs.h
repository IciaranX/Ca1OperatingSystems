#pragma once
#include<iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Jobs
{
 private:
  String JobName;
  int ArrivalTime;
  int JobDuration;
 public:
  Jobs();
  void setJobName(String A);
  void setArrivalTime(int b);
  void setJobDuration(int c);

  String getJobname();
  int getArrivalTime();
  int getJobDuration();
  
  ~Jobs();
}
