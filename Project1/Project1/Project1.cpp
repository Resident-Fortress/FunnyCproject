#include <iomanip>
#include <iostream>
#include <chrono>
#include <ctime>

//Using voids requires them to be placed OUTSIDE of the int main. Otherwise you'll have a failure to compile.


//int main just functions as a function to execute all the defined statements inside of it. Execution order is vital for other statements. Most shouldn't be worried about execution order.
//Unlike SwiftUI
int main() //Note to self always, always, have variables defined INSIDE of int main or other int's. 
{
	auto start = std::chrono::system_clock::now(); //Basically tells the CMD line to time the runtime. Acts like a stopwatch. In PROD env's doesn't really matter. 
	int funnynum;
	funnynum = 5;
	int anothernum{ 45 };
	int inputx{};
	int inputy{};

	//Note does order of how things are outputted and stored matter?
	//Note to self. No, no it does not matter.
	std::cout << "This process is timed" << std::endl;
	std::cout << "Hello World!\n";
	std::cout << "This combines a string and a variable. So anothernumber is equal to: " << anothernum << std::endl;
	std::cout << "The funny number of the day is: " << funnynum << std::endl;
	std::cout << "Please enter a number on the next line and also on the on after." << std::endl;
	std::cin >> inputx >> inputy;
	std::cout << "You've entered: " << inputx << " and also : " << inputy << std::endl;
	
	std::cout <<  "All this does is list out what bytes are in a operator." << std::endl;
	std::cout << "Since all machines are different. All your bytes will vary." << std::endl;
	std::cout << std::left;
	std::cout << std::setw(16) << "bool" << sizeof(bool) << "bytes\n";
	std::cout << std::setw(16) << "char" << sizeof(char) << "bytes\n";
	std::cout << std::setw(16) << "short" << sizeof(short) << "bytes\n";
	std::cout << std::setw(16) << "int" << sizeof(int) << "bytes\n";
	std::cout << std::setw(16) << "long" << sizeof(long) << "bytes\n";
	std::cout << std::setw(16) << "long long" << sizeof(long long) << "bytes\n";
	std::cout << std::setw(16) << "float" << sizeof(float) << "bytes\n";
	std::cout << std::setw(16) << "double" << sizeof(double) << "bytes\n";
	std::cout << std::setw(16) << "long double" << sizeof(long double) << "bytes\n";

	auto end = std::chrono::system_clock::now(); // Tells the stopwatch to stop and outputs it at the end of execution. 
	//Below just tells the machine to display time with date and how long the code ran.

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	struct tm timeinfo;
	if (localtime_s(&timeinfo, &end_time) == 0)
	{
		char buffer[26];
		if (asctime_s(buffer, sizeof(buffer), &timeinfo) == 0)
		{
			std::cout << "finished process at " << buffer
				<< "elapsed time: " << elapsed_seconds.count() << "s"
				<< std::endl;
		}
	}
	
}
