#pragma once
#include <string>

using namespace std;

class Process
{
	string process_name_;
	int burst_time_, arrival_time_, finish_time_, process_id_, turnaround_time_{};
	double  turnaround_time_on_burst_time_{};

public:
	Process();
	void set_process_name(string);
	string get_process_name() const;
	void set_burst_time(int);
	int get_burst_time() const;
	void set_arrival_time(int);
	int get_arrival_time() const;
	void set_finish_time(int);
	int get_finish_time() const;
	void set_process_id(int);
	int get_process_id() const;
	void set_turnaround_time(int);
	int get_turnaround_time() const;
	void set_turnaround_time_on_burst_time(double);
	double get_turnaround_time_on_burst_time() const;

	void process_id_plus_plus();
};