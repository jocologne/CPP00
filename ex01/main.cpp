
#include "Phonebook.hpp"
#include <iostream>
#include <string>

int main(void)
{
	PhoneBook phonebook;
	std::string command;
	while (true)
	{
		std::cout << "Enter a command (ADD, SERCH, EXIT): ";
		std::getline(std::cin, command);
		if(command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Unknown command."  << std::endl;
	}
}