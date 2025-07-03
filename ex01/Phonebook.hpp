
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# define GREEN "\033[32m"
# define RESET	"\033[0m"

# include "Contact.hpp"
# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <string>

class PhoneBook
{
	private:
		Contact contacts[8];
		int	count;
		int	index;

	public:
		PhoneBook();
		void addContact();
		void searchContact();
		void printContact(int index);
};

#endif