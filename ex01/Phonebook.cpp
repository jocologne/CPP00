
#include "Phonebook.hpp"

PhoneBook::PhoneBook()
{
	count = 0;
	index = 0;
}

static std::string getInput(const std::string &prompt)
{
	std::string input;
	while (input.empty())
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
	}
	return input;
}

static std::string trunc(const std::string &str)
{
	if(str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

/*void PhoneBook::printContact(int index)
{
	Contact &c = contacts[index];
}*/

void PhoneBook::addContact()
{
	Contact c;
	c.setFirstName(getInput("First Name: "));
	c.setLastName(getInput("Last Name: "));
	c.setNickname(getInput("Nickname: "));
	c.setPhone(getInput("Phone Number: "));
	c.setSecret(getInput("Secret: "));
	contacts[index] = c;
	if (count < 8)
		count++;
	index = (index + 1) % 8;
	std::cout << "Contact added sucessfully!" << std::endl; 
}

void PhoneBook::searchContact()
{
	if (count == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|"
   << std::setw(10) << "Name" << "|"
   << std::setw(10) << "Last" << "|"
   << std::setw(10) << "Nickname" << "\n";
   for (int i = 0; i < count; i++)
	{
   	std::cout << std::setw(10) << i + 1 << "|"
      << std::setw(10) << trunc(contacts[i].getFirstName()) << "|"
      << std::setw(10) << trunc(contacts[i].getLastName()) << "|"
      << std::setw(10) << trunc(contacts[i].getNickname()) << "\n";
   }
	std::cout << "Enter index for contact info: ";
	std::string input;
	std::getline(std::cin, input);
	if (input.empty() || !std::isdigit(input[0]))
	{
		std::cout << "Invalid input" << std::endl;
		return;
	}
	int index = std::atoi(input.c_str()) - 1;
	if (index < 0 || index > count)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << contacts[index].getPhone() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].getSecret() << std::endl;
}