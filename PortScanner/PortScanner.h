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

		bool port_is_open(const std::string& address, int port);
		std::vector<std::string> split(const std::string& string, char delimiter = ' ', bool allow_empty = false);
		int string_to_int(const std::string& string);
		template <typename T>
		void swaper(T& a, T& b);		
		template <typename T>
		std::vector<T> range(T min, T max);
		std::vector<int> parse_ports_list(const std::string& list);
		
};


#endif
