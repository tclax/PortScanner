// Reference to this exercise: http://www.cplusplus.com/articles/o2N36Up4/

#include <iostream>
#include <SFML/Network.hpp>
#include <string>
#include <sstream>
#include <vector>
#include "PortScanner.h"

int main()
{
	PortScanner portScanner;
	std::string address;
	std::string port_list;
	std::vector<int> ports;

	int open_ports_count = 0;
	std::cout << "Address: " << std::flush;
	std::getline(std::cin, address);
	std::cout << "Port: " << std::flush;
	std::getline(std::cin, port_list);
	ports = portScanner.parse_ports_list(port_list);
	std::cout << "Scanning " << address << "...\n";
	for (int port : ports) {
		std::cout << "Port " << port << " : ";
		if (portScanner.port_is_open(address, port))
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
