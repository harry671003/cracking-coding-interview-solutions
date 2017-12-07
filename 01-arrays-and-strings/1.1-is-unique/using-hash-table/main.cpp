#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>

bool IsUnique(std::string str);

int main() 
{
	auto file = std::ifstream("input.txt");
	std::string str;

	while(std::getline(file, str))
	{
		std::cout 
			<< str << " => " 
			<< (IsUnique(str)? "Unique": "Not Unique.")
			<< std::endl;
	}
}

bool IsUnique(std::string str)
{
	std::unordered_map<char, bool> map;

	for(auto it = str.begin(); it < str.end(); it++)
	{
		if(map.find(*it) != map.end())
		{
			// a repeating occurance
			return false;
		}
		else
		{
			map[*it] = true;
		}
	}

	return true;
}