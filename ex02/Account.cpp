
#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
}

int	Account::getNbAccounts( void )	
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::_displayTimestamp( void )
{
	std::time_t current_time = std::time(NULL);
	std::tm *local_time = std::localtime(&current_time);
	std::cout << "["
		<< (local_time->tm_year + 1900)
		<< std::setfill('0') << std::setw(2)
		<< (local_time->tm_mon + 1)
		<< std::setfill('0') << std::setw(2)
		<< local_time->tm_mday
		<< "_"
		<< std::setfill('0') << std::setw(2)
		<< local_time->tm_hour
		<< std::setfill('0') << std::setw(2)
		<< local_time->tm_min
		<< std::setfill('0') << std::setw(2)
		<< local_time->tm_sec
		<< "]";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
		<<"p_amount:" << _amount << ";"
		<<"deposit:" << deposit << ";";
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "amount:" << _amount << ";"
		<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
		<<"p_amount:" << _amount << ";"
		<<"withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal << ";";
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << "amount:" << _amount << ";"
		<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int	Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals << std::endl;
}