#include "Jobs.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;
using std::string;
using namespace std;

using namespace std;

void readFile(vector<Jobs>&);
void printFileVector(vector<Jobs>&);
void printFOFO(vector<Jobs>&);

bool sortArrival(Jobs &j1, Jobs &j2) { return j1.getArrivedTime() < j2.getArrivedTime(); }
bool sortDuration(Jobs &j1, Jobs &j2) { return j1.getjobduration() < j2.getjobduration(); }

int main() {
  vector<Jobs> jobs;
  vector<Jobs> sorted_jobs;
  readFile(jobs);
  cout << "unsorted job list" << endl;
   printFileVector(jobs);
   cout << "Fifo sorted jobs" << endl;
   printFOFO(jobs);

  return 0;
}

void readFile(vector<Jobs>& newJobVector) {
  ifstream inFile("jobs.txt", ios::in);
  string line;
  int i = 0;

  string job_name;
  int arr_time, run_time;

  
  
  
  if (inFile.is_open()) {
    getline(inFile, line);
    inFile >> job_name >> arr_time >> run_time;

    Jobs newJob1;
    newJob1.setjobName(job_name);
    newJob1.setArrivedTime(arr_time);
    newJob1.setjobDuration(run_time);

    newJobVector.push_back(newJob1);
    i++;
    while (inFile.good() && !inFile.eof()) {
      getline(inFile, line);

      inFile >> job_name >> arr_time >> run_time;
      if (inFile.eof()) return; //Returns if the file is repeated.

      Jobs newJob;
      newJob.setjobName(job_name);
      newJob.setArrivedTime(arr_time);
      newJob.setjobDuration(run_time);
      newJobVector.push_back(newJob);
      i++;
      
    }
  }
  else {
    cout << "Problem opening file" << endl;
  }



  inFile.close();
}

void printFileVector(vector<Jobs>& myVector) {
  
  cout << "--------------------------------------------" << endl;
  cout << "JOB_NAME\tARRIVAL_TIME\tDURATION" << endl;
  cout << "--------------------------------------------" << endl;
  unsigned int size = myVector.size();
  for (unsigned int i = 0; i < size; i++){
    cout << myVector[i].getjobName() << "\t\t" << myVector[i].getArrivedTime() << "\t\t" << myVector[i].getjobduration() << endl;
  }
}
void printFOFO(vector<Jobs>& jobs) {
  int totalTime = 0;
  int count = 0;
  int index = 0;
  sort(jobs.begin(), jobs.end(), sortArrival);
  
  for (int i = 0; i < jobs.size(); ++i)
    {
      totalTime += jobs[i].getjobduration();
    }
  vector<string> FIFO;
  for (int j = 0; j < totalTime; j++)
    {
      int duration = jobs[index].getjobduration();
      if (count == jobs[count].getArrivedTime())
	{
	  FIFO.push_back(jobs[index].getjobName());
	  count++;
	  if (count == duration)
	    {
	      index++;
	      count = 0;

	      
	    }
	}
    }

  printFileVector(jobs);
}
