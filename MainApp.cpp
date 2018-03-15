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
//void printFileVector(const vector<Jobs>&);
//void printOutput(const vector<Jobs>&);

bool sortArrival(Jobs &j1, Jobs &j2) { return j1.getArrivedTime() < j2.getArrivedTime(); }
bool sortDuration(Jobs &j1, Jobs &j2) { return j1.getjobduration() < j2.getjobduration(); }

int main() {
  vector<Jobs> jobs;
  vector<Jobs> sorted_jobs;
  readFile(jobs);
  sort(jobs.begin(), jobs.end(), sortArrival);

  // printFileVector(jobs);
  //  printOutput(jobs);

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
      cout << "Job found!" << endl;
    }
  }
  else {
    cout << "Problem opening file" << endl;
  }



  inFile.close();
}

