// FCFS Scheduling Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
	 /******************************/
	/*	                          */
   /*	Erfan Mohammadzadeh      */
  /*		9622473147		    */
 /*	                           */
/******************************/

#include <iostream>
#include "Process.h"
#include <Windows.h>
#include <vector>
#include <iomanip>


using namespace std;


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()
const int color_codes[39] = {32, 33, 34, 35, 36, 31, 91, 92, 93, 94, 95, 96, 97, 32, 33, 34, 35, 36, 31, 91, 92, 93, 94, 95, 96, 97 ,32, 33, 34, 35, 36, 31, 91, 92, 93, 94, 95, 96, 97,};   // Codes for colors
#define CLEAR (system("cls"));


void get_process_information(vector<Process>&, int);
void sort_processes_based_on_arrival_time(vector<Process>&, int);
void calculate_process_finish_time(vector<Process>&, int);
void calculate_process_turnaround_time(vector<Process>&, int);
void calculate_turnaround_time_on_burst_time(vector<Process>&, int);
double calculate_turnaround_time_mean(vector<Process>, int);
double calculate_turnaround_time_on_burst_time_mean(vector<Process>, int);
void show_process_info_table(vector<Process>, int);
void show_process_timetable(vector<Process>, int);

int main()
{
	system("color 74");
	int number_of_processes;
	vector <Process> process;
	const Process pro;

	cout << "Please Enter number of Processes : ";
	cin >> number_of_processes;
	CLEAR
		for (int index = 0; index < number_of_processes; index++)
		{
			process.push_back(pro);
			get_process_information(process, index);
		}
	CLEAR;
	sort_processes_based_on_arrival_time(process, number_of_processes);
	show_process_info_table(process, number_of_processes);
	show_process_timetable(process, number_of_processes);
	cin.get();
	cin.get();
}


void get_process_information(vector<Process>& process, const int index)
{
	string process_name;
	int burst_time, arrival_time;

	cin.get();
	cout << "# Please Enter Process Name : ";
	getline(cin, process_name);
	process[index].set_process_name(process_name);
	cout << "\n# Please Enter Arrival Time : ";
	cin >> arrival_time;
	process[index].set_arrival_time(arrival_time);
	cout << "\n# Please Enter Burst Time : ";
	cin >> burst_time;
	process[index].set_burst_time(burst_time);
	process[index].set_process_id(index + 1);
	cout << "\n================================================\n\n\a";
}


void sort_processes_based_on_arrival_time(vector<Process>& process, const int number_of_processes)
{
	Process empty_process;
	int id;
	for (int index = 0; index < number_of_processes - 1; index++)
	{
		if (process[index].get_arrival_time() > process[index + 1].get_arrival_time())
		{
			empty_process = process[index];
			process[index] = process[index + 1];
			process[index + 1] = empty_process;

			id = process[index + 1].get_process_id();
			process[index + 1].set_process_id(process[index].get_process_id());
			process[index].set_process_id(id);
		}
	}
	calculate_process_finish_time(process, number_of_processes);
}


void calculate_process_finish_time(vector<Process>& process, const int number_of_processes)
{
	int waiting_time;
	for (int index_1 = 0; index_1 < number_of_processes; index_1++)
	{
		int before_processes, sum_of_finish_times = 0;
		before_processes = process[index_1].get_process_id() - 1;
		if (before_processes == 0)
		{
			process[index_1].set_finish_time(process[index_1].get_arrival_time() + process[index_1].get_burst_time());
		}
		else
		{
			if (process[index_1 - 1].get_finish_time() - process[index_1].get_arrival_time() < 0)
			{
				waiting_time = -1 * (process[index_1 - 1].get_finish_time() - process[index_1].get_arrival_time());
				process[index_1].set_finish_time(process[index_1 - 1].get_finish_time() + process[index_1].get_burst_time() + waiting_time);

			}
			else
			{
				process[index_1].set_finish_time(process[index_1 - 1].get_finish_time() + process[index_1].get_burst_time());
			}
		}
	}
	calculate_process_turnaround_time(process, number_of_processes);
}


void calculate_process_turnaround_time(vector<Process>& process, const int number_of_processes)
{
	for (int index = 0; index < number_of_processes; index++)
	{
		process[index].set_turnaround_time(process[index].get_finish_time() - process[index].get_arrival_time());
	}
	calculate_turnaround_time_on_burst_time(process, number_of_processes);
}


void calculate_turnaround_time_on_burst_time(vector<Process>& process, const int number_of_processes)
{
	for (int index = 0; index < number_of_processes; index++)
	{
		process[index].set_turnaround_time_on_burst_time(static_cast <double>(process[index].get_turnaround_time()) / process[index].get_burst_time());
	}
}


double calculate_turnaround_time_mean(vector<Process> process, const int number_of_processes)
{
	double turnaround_time_mean, sum = 0;
	for (int index = 0; index < number_of_processes; index++)
	{
		sum += process[index].get_turnaround_time();
	}
	turnaround_time_mean = static_cast <double>(sum) / number_of_processes;
	return turnaround_time_mean;
}


double calculate_turnaround_time_on_burst_time_mean(vector<Process> process, const int number_of_processes)
{
	double turnaround_time_on_burst_time_mean, sum = 0;
	for (int index = 0; index < number_of_processes; index++)
	{
		sum += process[index].get_turnaround_time_on_burst_time();
	}
	turnaround_time_on_burst_time_mean = static_cast <double>(sum) / number_of_processes;
	return turnaround_time_on_burst_time_mean;
}


void show_process_info_table(vector<Process> process, const int number_of_processes)
{
	// Print first longitudinal lint and first row in the information table
	printf("\t%c", 218);
	for (int index = 0; index < 5; index++)
	{
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 194);
	}
	printf("%c%c%c%c%c%c%c%c%c%c\n\t%c  \033[30mProcess Name \x1b[31m %c \033[30m Arrival Time \x1b[31m %c \033[30m   Burst Time \x1b[31m %c \033[30m Finish Time \x1b[31m  %c\033[30mTurnaround Time\x1b[31m %c \033[30m Tr/Ts \x1b[31m %c\n", 196, 196, 196, 196, 196, 196, 196, 196, 196, 191, 179, 179, 179, 179, 179, 179, 179);



	// Print information of processes in the table rows
	for (int row_index = 0; row_index < number_of_processes; row_index++)
	{
		printf("\t%c", 195);
		for (int index = 0; index < 5; index++)
		{
			{
				printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 197);
			}
		}
		printf("%c%c%c%c%c%c%c%c%c%c\n\t%c", 196, 196, 196, 196, 196, 196, 196, 196, 196, 180, 179);
		printf("\x1b[%dm%-16s\x1b[31m%c", color_codes[row_index], process[row_index].get_process_name().c_str(), 179);
		printf("\x1b[%dm        %-8d\x1b[31m%c", color_codes[row_index], process[row_index].get_arrival_time(), 179);
		printf("\x1b[%dm        %-8d\x1b[31m%c", color_codes[row_index], process[row_index].get_burst_time(), 179);
		printf("\x1b[%dm        %-8d\x1b[31m%c", color_codes[row_index], process[row_index].get_finish_time(), 179);
		printf("\x1b[%dm        %-8d\x1b[31m%c", color_codes[row_index], process[row_index].get_turnaround_time(), 179);
		printf("\x1b[%dm   %-6.2f\x1b[31m%c\n", color_codes[row_index], process[row_index].get_turnaround_time_on_burst_time(), 179);
	}


	// Print last row (mean row) in the information table
	printf("\t%c", 195);
	for (int index = 0; index < 5; index++)
	{
		{
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 197);
		}
	}
	printf("%c%c%c%c%c%c%c%c%c%c\n\t", 196, 196, 196, 196, 196, 196, 196, 196, 196, 180);
	printf("%c     \033[30m Mean \x1b[31m     %c", 179, 179);
	for (int index = 0; index < 3; index++)
	{
		printf("                %c", 179);
	}
	printf("\033[30m     %-8.3f   \x1b[31m%c", calculate_turnaround_time_mean(process, number_of_processes), 179);
	printf("\033[30m  %-3.3f  \x1b[31m%c", calculate_turnaround_time_on_burst_time_mean(process, number_of_processes), 179);


	// Print last longitudinal line in the information table
	printf("\n\t%c", 192);
	for (int index = 0; index < 5; index++)
	{
		{
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 193);
		}
	}
	printf("%c%c%c%c%c%c%c%c%c%c\n\n", 196, 196, 196, 196, 196, 196, 196, 196, 196, 217);
}


void show_process_timetable(vector<Process> process, const int number_of_processes)
{
	const int remaining = process.back().get_finish_time() % 5;
	const int length_of_table = process.back().get_finish_time() - remaining + 5;


	// Calculate and print numbers of above the timetable
	for (int index = 0; index <= length_of_table; index += 5)
	{
		index >= 10 ? cout << "       " << index << "      " : cout << "        " << index << "      ";
	}
	cout << endl;


	//Print first longitudinal line in the timetable
	printf("\t\033[30m%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 216, 205, 205, 216, 205, 205, 216, 205, 205, 216, 205, 205, 206);
	for (int index = 1; index < length_of_table / 5; index++)
	{
		printf("\033[30m%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 216, 205, 205, 216, 205, 205, 216, 205, 205, 216, 205, 205, 206);
		if (index == length_of_table - 1)
		{
			printf("\033[30m%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 216, 205, 205, 216, 205, 205, 216, 205, 205, 216, 205, 205, 185);
		}
	}
	cout << endl;


	// Print squares in the timetable
	for (int index = 0; index < number_of_processes; index++)
	{
		printf("\x1b[%dm", color_codes[index]);
		cout << setw(8) << left << process[index].get_process_name();
		printf("\x1b[31m\033[30m%c", 186);
		if (index != 0 && process[index].get_arrival_time() > process[index - 1].get_finish_time())
		{
			const int waiting_time = process[index].get_arrival_time() - process[index - 1].get_finish_time();
			for (int first_process_space = 0; first_process_space < waiting_time; first_process_space++)
			{
				cout << " \033[30m |";
			}
		}
		else if (index == 0)
		{
			for (int first_process_space = 0; first_process_space < process[index].get_arrival_time(); first_process_space++)
			{
				cout << " \033[30m |";
			}
		}
		for (int number_of_space = 0; index != 0 && number_of_space < process[index - 1].get_finish_time(); number_of_space++)
		{
			cout << " \033[30m |";

		}
		for (int number_of_squares = 0; number_of_squares < process[index].get_burst_time(); number_of_squares++)
		{
			printf("\x1b[%dm%c%c\x1b[31m\033[30m|", color_codes[index], 219, 219);
		}
		for (int complete_table = process[index].get_finish_time(); complete_table < length_of_table - 1; complete_table++)
		{
			cout << "  |";
		}
		printf("  \033[30m%c", 186);
		cout << endl;
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file