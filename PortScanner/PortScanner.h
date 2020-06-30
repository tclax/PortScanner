#ifndef PORTSCANNER_H
#define PORTSCANNER_H

#include <SFML/Network.hpp>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

class PortScanner
{
	public:
		//Checks if the port at the address is open
		//In: Address, port
		//Out: true if open, false if anything else
		static bool port_is_open(const std::string& address, int port);

		//Splits string 
		//In: string to split, delimiter to split on, flag to allow 
		//Out: List of strings 
		static std::vector<std::string> split(const std::string& string, char delimiter = ' ', bool allow_empty = false);

		//Converts string to int
		//In: string numerical value
		//Out: converted integer
		static int string_to_int(const std::string& string);

		//Swaps values of two values
		//In: objects A and B
		//Out: objects B and A
		template <typename T>
		static void swaper(T& a, T& b);
		
		template <typename T>
		static std::vector<T> range(T min, T max);

		//Sorts port list in ascending order
		//In: delimited string to be split and ordered
		//Out: list of integers representing ports
		static std::vector<int> parse_ports_list(const std::string& list);
		
};


#endif
