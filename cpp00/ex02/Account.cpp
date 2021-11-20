#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

#ifndef ORIGIN
# define ORIGIN 0
#endif

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _nbDeposits(0), _nbWithdrawals(0)
{
    _accountIndex = _nbAccounts;
    _nbAccounts += 1;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << initial_deposit << ";"
              << "created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount" << _amount << ";"
              << "closed" << std::endl;
}

int Account::getNbAccounts( void )
{
    return (_nbAccounts);
}
int Account::getTotalAmount( void )
{
    return (_totalAmount);
}
int Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}
int Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void Account:: _displayTimestamp(void)
{
    time_t t = time(0);
    const tm* localTime = localtime(&t);
    std::stringstream s;

    s << "20" << localTime->tm_year - 100;
    s << std::setw(2) << std::setfill('0') << localTime->tm_mon + 1;
    s << std::setw(2) << std::setfill('0') << localTime->tm_mday;
    s << "_";
    s << std::setw(2) << std::setfill('0') << localTime->tm_hour;
    s << std::setw(2) << std::setfill('0') << localTime->tm_min;
    s << std::setw(2) << std::setfill('0') << localTime->tm_sec;
    if (ORIGIN)
    {
        std::cout << "[19920104_091532] ";
    }
    else
    {
        std::cout << "[" << s.str() << "] ";
    }
}

void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
              << "total:" << getTotalAmount() << ";"
              << "deposits:" << getNbDeposits() << ";"
              << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    _nbDeposits += 1;
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";"
              << "deposit:" << deposit << ";"
              << "amount:" << _amount + deposit << ";"
              << "nb_deposits:" << _nbDeposits << std::endl;

    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
}

bool Account:: makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";";

    int tmp = _amount;
    _amount -= withdrawal;
    if (checkAmount())
    {
        _nbWithdrawals += 1;
        _totalNbWithdrawals += 1;
        _totalAmount -= withdrawal;
        std::cout << "withdrawal:" << withdrawal << ";";
        std::cout << "amount:" << _amount << ";"
                  << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (true);
    }
    else
    {
        std::cout << "withdrawal:refused" << std::endl;
        _amount = tmp;
        return (false);
    }
}

void Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "deposits:" << _nbDeposits << ";"
              << "withdrawals:" << _nbWithdrawals << std::endl;
}

int Account::checkAmount( void ) const
{
    return (_amount > 0);
}