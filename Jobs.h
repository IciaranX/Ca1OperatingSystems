#pragma once

#include <string>
using std::string;

class Jobs
{
 private:
  string JobName;
  int ArrivalTime;
  int JobDuration;

 public:
  Jobs();
  void setJobName(String A);
  void setArrivalTime(int b);
  void setJobDuration(int c);

  string getJobname();
  int getArrivalTime();
  int getJobDuration();
  
  ~Jobs();
};
