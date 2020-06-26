// Turtorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Reference to this exercise: http://www.cplusplus.com/articles/o2N36Up4/

#include <iostream>
#include <SFML/Network.hpp>
#include <string>
#include <sstream>
#include <vector>

//Checks if the port at the address is open
//In: Address, port
//Out: true if open, false if anything else
static bool port_is_open(const std::string& address, int port)
{
	return (sf::TcpSocket().connect(address, port) == sf::Socket::Done);
}

//Splits string 
//In: string to split, delimiter to split on, flag to allow 
//Out: List of strings 
static std::vector<std::string> split(const std::string & string, char delimiter = ' ', bool allow_empty = false)
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
static int string_to_int(const std::string & string)
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
static void swaper(T & a, T & b)
{
	T c = a;
	a = b;
	b = c;
}

//
template <typename T>
static std::vector<T> range(T min, T max)
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
static std::vector<int> parse_ports_list(const std::string & list)
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

int main()
{
	std::string address;
	std::string port_list;
	std::vector<int> ports;
	int open_ports_count = 0;
	std::cout << "Address: " << std::flush;
	std::getline(std::cin, address);
	std::cout << "Port: " << std::flush;
	std::getline(std::cin, port_list);
	ports = parse_ports_list(port_list);
	std::cout << "Scanning " << address << "...\n";
	for (int port : ports) {
		std::cout << "Port " << port << " : ";
		if (port_is_open(address, port))
		{
			std::cout << "OPEN\n";
			open_ports_count++;
		}
		else
			std::cout << "CLOSED\n";
	}
	std::cout << open_ports_count << " open ports" << std::flush;
	std::cout << std::flush;
	return 0;
}
