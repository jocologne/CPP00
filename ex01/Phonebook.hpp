
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

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