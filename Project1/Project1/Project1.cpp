#include <iomanip>
#include <iostream>
#include <chrono>
#include <ctime>
#include <format>
#include <print>

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

using namespace std;
//Using voids requires them to be placed OUTSIDE of the int main. Otherwise you'll have a failure to compile. Also they should never have values!


//int main just functions as a function to execute all the defined statements inside of it. Execution order is vital for other statements. Most shouldn't be worried about execution order.
//Unlike SwiftUI
int main() //Note to self always, always, have variables defined INSIDE of int main or other int's. 
{
	//Time Functionality begins here
	auto start = chrono::system_clock::now(); //Basically tells the CMD line to time the runtime. Acts like a stopwatch. In PROD env's doesn't really matter. 
	int funnynum;
	funnynum = 5;
	int anothernum{ 45 };
	int inputx{};
	int inputy{};


	//Begin writing clock function
	time_t now = time(0); 

	char* dt = ctime(&now);

	cout << "The local date and time is " << dt << endl;

	tm* gmtm = gmtime(&now);
	dt = asctime(gmtm); 
	cout << "The UTC date and time are currently" << dt << endl;
	//Note does order of how things are outputted and stored matter?
	//Note to self. No, no it does not matter.
	cout << "This process is timed" << endl;
	cout << "Hello World!\n";
	cout << "This combines a string and a variable. So anothernumber is equal to: " << anothernum << endl;
	cout << "The funny number of the day is: " << funnynum << endl;
	cout << "Please enter a number on the next line and also on the on after." << endl;
	cin >> inputx >> inputy;
	cout << "You've entered: " << inputx << " and also : " << inputy << endl;
	
	//Begin Listing operator and their size
	cout <<  "All this does is list out what bytes are in a operator." << endl;
	cout << "Since all machines are different. All your bytes will vary." << endl;
	cout << left;
	cout << setw(16) << "bool" << sizeof(bool) << "bytes\n";
	cout << setw(16) << "char" << sizeof(char) << "bytes\n";
	cout << setw(16) << "short" << sizeof(short) << "bytes\n";
	cout << setw(16) << "int" << sizeof(int) << "bytes\n";
	cout << setw(16) << "long" << sizeof(long) << "bytes\n";
	cout << setw(16) << "long long" << sizeof(long long) << "bytes\n";
	cout << setw(16) << "float" << sizeof(float) << "bytes\n";
	cout << setw(16) << "double" << sizeof(double) << "bytes\n";
	cout << setw(16) << "long double" << sizeof(long double) << "bytes\n";
	//End listing operator and their byte size


	auto end = chrono::system_clock::now(); // Tells the stopwatch to stop and outputs it at the end of execution. 
	//Below just tells the machine to display time with date and how long the code ran.

	chrono::duration<double> elapsed_seconds = end - start;
	time_t end_time = chrono::system_clock::to_time_t(end);

	struct tm timeinfo;
	if (localtime_s(&timeinfo, &end_time) == 0)
	{
		char buffer[26];
		if (asctime_s(buffer, sizeof(buffer), &timeinfo) == 0)
		{
			cout << "finished process at " << buffer
				<< "elapsed time: " << elapsed_seconds.count() << "s"
				<< endl;
		}
	}
	// End Time functionality
	
}
