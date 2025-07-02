#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact {
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	dark_secret;

public:
	//Constructor
	Contact();

	//Set values
	void setFirstName(const std::string &fname);
	void setLastName(const std::string &lname);
	void setNickname(const std::string &nick);
	void setPhone(const std::string &phone);
	void setSecret(const std::string &secret);

	//Get values
	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
	std::string getPhone(void) const;
	std::string getSecret(void) const;
};

#endif