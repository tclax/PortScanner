// Turtorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Reference to this exercise: http://www.cplusplus.com/articles/o2N36Up4/

#include <iostream>
#include <SFML/Network.hpp>
#include <string>
#include <sstream>
#include <vector>
#include "PortScanner.h"

//Checks if the port at the address is open
//In: Address, port
//Out: true if open, false if anything else
bool PortScanner::port_is_open(const std::string& address, int port)
{
	return (sf::TcpSocket().connect(address, port) == sf::Socket::Done);
}

//Splits string 
//In: string to split, delimiter to split on, flag to allow 
//Out: List of strings 
std::vector<std::string> PortScanner::split(const std::string & string, char delimiter, bool allow_empty)
{
	std::vector<std::string> tokens;
	std::stringstream sstream(string);
	std::string token;
	while (std::getline(sstream, token, delimiter)) {
		if (allow_empty || token.size() > 0)
			tokens.push_back(token);
	}

	return tokens;
}

//Converts string to int
//In: string numerical value
//Out: converted integer
int PortScanner::string_to_int(const std::string & string)
{
	std::stringstream sstream(string);
	int i;
	sstream >> i;
	return i;
}

//Swaps values of two values
//In: objects A and B
//Out: objects B and A
template <typename T>
void PortScanner::swaper(T & a, T & b)
{
	T c = a;
	a = b;
	b = c;
}

//
template <typename T>
std::vector<T> PortScanner::range(T min, T max)
{
	if (min > max)
		swaper(min, max);
	if (min == max)
		return std::vector<T>(1, min);
	std::vector<T> values;
	for (; min <= max; ++min)
		values.push_back(min);
	return values;
}


//Sorts port list in ascending order
//In: delimited string to be split and ordered
//Out: list of integers representing ports
std::vector<int> PortScanner::parse_ports_list(const std::string & list)
{
	std::vector<int> ports;
	for (const std::string& token : split(list, ',')) {
		std::vector<std::string> strrange = split(token, '-');
		switch (strrange.size()) {
		case 0:
			ports.push_back(string_to_int(token));
			break;
		case 1:
			ports.push_back(string_to_int(strrange[0]));
			break;
		case 2:
		{
			int min = string_to_int(strrange[0]),
				max = string_to_int(strrange[1]);
			for (int port : range(min, max))
				ports.push_back(port);
			break;
		}
		default:
			break;
		}
	}
	return ports;
}
