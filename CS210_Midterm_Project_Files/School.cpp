#include <string>

struct School
{
	std::string name;
	std::string address;
	std::string city;
	std::string state;
	std::string county;
	School* next;
};