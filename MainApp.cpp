#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <vector>
#include "jobs.cpp"

using namespace std;

void readFile(vector<Jobs>&);
void printFileVector(const vector<Jobs>&);
void printOutput(const vector<Jobs>&);

bool sortArrival(Jobs &j1, Jobs &j2) { return j1.getArrvalTime() < j2.getArrvalTime(); }
bool sortDuration(Jobs &j1, Jobs &j2) { return j1.getJobDuration() < j2.getJobDuration(); }

int main() {
	vector<Jobs> jobs;
	vector<Jobs> sorted_jobs;
	readFile(jobs);
	sort(jobs.begin(), jobs.end(), sortArrival);

	// printFileVector(jobs);
	printOutput(jobs);

	return 0;
}

void readFile(vector<Jobs>& newJobVector) {
	std::ifstream inFile("jobs.txt", ios::in);
	std::string line;
	int i = 0;

	string job_name;
	int arr_time, run_time;

	if (inFile.is_open()) {
		getline(inFile, line);
		inFile >> job_name >> arr_time >> run_time;

		Jobs newJob1;
		newJob1.setJobName(job_name);
		newJob1.setArrivalTime(arr_time);
		newJob1.setJobDuration(run_time);

		newJobVector.push_back(newJob1);
		i++;
		while (inFile.good() && !inFile.eof()) {
			getline(inFile, line);

			inFile >> job_name >> arr_time >> run_time;
			if (inFile.eof()) return; //Returns if the file is repeated.

			Jobs newJob;
			newJob.setJobName(job_name);
			newJob.setArrivalTime(arr_time);
			newJob.setJobDuration(run_time);
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
	cout << "Print file vector" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "JOB_NAME\tARRIVAL_TIME\tDURATION" << endl;
	cout << "--------------------------------------------" << endl;
	unsigned int size = myVector.size();
	for (unsigned int i = 0; i < size; i++){
		cout << myVector[i].getJobname() << "\t\t" << myVector[i].getArrvalTime() << "\t\t" << myVector[i].getJobDuration() << endl;
	}
}

void printOutput(vector<Jobs>& jobs) {
	int list_size = jobs.size();
	int total_dur = 0;
	int loopme = 0;
	//fifo variables
	int count = 0, index = 0;
	//sjf variables
	int sjf_count = 0, sjf_index = 0;
	//stcf variables
	//rr1 variables
	int rr1_count = 0, rr1_index = 0, rr1_remainder = 0;

	vector<Jobs>sjf_job;
	vector<Jobs> rr1_job;
	vector<Jobs> rr2_job;
	for (int m = 0; m < list_size; m++){
		Jobs jm;
		jm.setJobName(jobs[m].getJobname());
		jm.setArrivalTime(jobs[m].getArrvalTime());
		jm.setJobDuration(jobs[m].getJobDuration());
		sjf_job.push_back(jm);
		rr1_job.push_back(jm);
		rr2_job.push_back(jm);
	}
	sort(sjf_job.begin(), sjf_job.end(), sortDuration);

	for (int i = 0; i < list_size; i++) {
		total_dur += jobs[i].getJobDuration();
	}

	cout << "T\tFIFO\tSJF\tSTCF\tRR1\tRR2" << endl;
	for (int j = 1; j <= total_dur; j++){
		if (j == jobs[loopme].getArrvalTime()) {
			cout << "* ARRIVED: " << jobs[loopme].getJobname() << endl;
			loopme++;
		}

		string fifo, sjf, rr1;

		//fifo
		int dur_size = jobs[index].getJobDuration();
		if (count < jobs[index].getJobDuration()){
			fifo = jobs[index].getJobname();
			count++;
			if (count == (dur_size)) {
				index++;
				count = 0;
			}
		}

		//sjf
		int sjf_dur_size = sjf_job[sjf_index].getJobDuration();
		if (sjf_count < sjf_job[sjf_index].getJobDuration()){
			sjf = sjf_job[sjf_index].getJobname();
			sjf_count++;
			if (sjf_count == sjf_dur_size){
				sjf_index++;
				sjf_count = 0;
			}
		}

		//stcf

		//rr1
		// if(j == rr1_job[rr1_index].getArr){
		//   rr1 = rr1_job[rr1_index].getJobName();
		//   Job rj;
		//   rj.setJobName(rr1_job[rr1_index].getJobName());
		//   rj.setArr(rr1_job[rr1_index].getArr());
		//   rj.setRun(rr1_job[rr1_index].getRun()-1);
		//   rr1_job.push_back(rj);
		// }

		//rr2

		cout << j << "\t" << fifo << "\t" << sjf << endl;

	}

	cout << "= SIMULATION COMPLETE" << endl;
}
