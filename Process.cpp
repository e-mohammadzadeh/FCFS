#include "Process.h"


Process::Process()
{
	process_name_ = "";
	burst_time_ = NULL;
	arrival_time_ = NULL;
	finish_time_ = NULL;
	process_id_ = NULL;
}


void Process::set_process_name(const string process_name)
{
	process_name_ = process_name;
}


string Process::get_process_name() const
{
	return process_name_;
}


void Process::set_burst_time(const int burst_time)
{
	if (burst_time >= 0)
	{
		burst_time_ = burst_time;
	}
}


int Process::get_burst_time() const
{
	return burst_time_;
}


void Process::set_arrival_time(const int arrival_time)
{
	if (arrival_time >= 0)
	{
		arrival_time_ = arrival_time;
	}
}


int Process::get_arrival_time() const
{
	return arrival_time_;
}


void Process::set_finish_time(const int finish_time)
{
	if (finish_time >= 0)
	{
		finish_time_ = finish_time;
	}
}


int Process::get_finish_time() const
{
	return finish_time_;
}


void Process::set_process_id(const int process_id)
{
	process_id_ = process_id;
}


int Process::get_process_id() const
{
	return process_id_;
}


void Process::set_turnaround_time(const int turnaround_time)
{
	turnaround_time_ = turnaround_time;
}


int Process::get_turnaround_time() const
{
	return turnaround_time_;
}


void Process::set_turnaround_time_on_burst_time(const double turnaround_time_on_burst_time)
{
	turnaround_time_on_burst_time_ = turnaround_time_on_burst_time;
}


double Process::get_turnaround_time_on_burst_time() const
{
	return turnaround_time_on_burst_time_;
}


void Process::process_id_plus_plus()
{
	set_process_id(get_process_id() + 1);
}