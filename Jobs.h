#include <string>

using std::string;

class Jobs
{
 private:
  string jobName;
  int arrivedTime;
  int jobDuration;
 public:
  Jobs();
  void setjobName(string a);
  void setArrivedTime(int b);
  void setjobDuration(int c);

  string getjobName();
  int getArrivedTime();
  int getjobduration();

  ~Jobs();
};
