#include <iostream>
#include <iomanip>

void name = [];


int main()
{
	std::cin >> name >> std::endl;
	std::cout << name << "All this does is list out what bytes are in a operator."<< std::endl;
	std::cout << "Since all machines are different. Everything will vary." << std::endl;
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
		return 0;
}

