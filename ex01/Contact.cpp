
#include "Contact.hpp"

Contact::Contact(){};

void Contact::setFirstName(const std::string &fname)
{
	first_name = fname;
}

void Contact::setLastName(const std::string &lname)
{
	last_name = lname;
}

void Contact::setNickname(const std::string &nick)
{
	nickname = nick;
}

void Contact::setPhone(const std::string &phone)
{
	phone_number = phone;
}

void Contact::setSecret(const std::string &secret)
{
	dark_secret = secret;
}

std::string Contact::getFirstName(void) const
{
	return (first_name);
}

std::string Contact::getLastName(void) const
{
	return (last_name);
}

std::string Contact::getNickname(void) const
{
	return (nickname);
}

std::string Contact::getPhone(void) const
{
	return (phone_number);
}

std::string Contact::getSecret(void) const
{
	return(dark_secret);
}