#include "Account.h"
#pragma once

/*
 Class Name: child class Bank inherite from the account class
 Purpose   : This is derived class used for open user account, balance enquiry , deposit and withraw 
			as well as close user account, show all user account.
*/

class Bank :public Account
{
private:
	map<long, Account> accounts; //map store account number and whole Account class 
public:
	Bank();//non-perameterize constructor - when program starts 
	//this function takes all data from the file and store in accounts(map)

	Account OpenAccount(string fname, string lname, float b);//Open user account and store in file
	Account BalanceEnquiry(long accountNumber);//give user account detail
	Account Deposite(long accountNumber, float b);//take account number and call parent class deposit function 
	Account Withraw(long accountNumber, float b);//take account number and call parent class withraw function
	void Close(long accountNumber);//close user account detail
	void ShowAllAccountInAsce();//show all user information in increasing account number order
	void ShowAllAccountInDesc();//show all user information in decreasing account number order
	~Bank();//Destructor
};


Bank::Bank()
{
	ifstream infile;
	Account account;
	infile.open("data.txt");

	if (!infile)
	{
		ofstream os("data.txt");
		os.close();
	}
	while (!infile.eof())
	{
		infile >> account;
		accounts.insert(pair<long, Account>(account.getAccountNumber(), account));
	}

	setLasttac(account.getAccountNumber());
	infile.close();
}

Account Bank::OpenAccount(string fname, string lname, float b)
{
	ofstream outfile;
	Account account(fname, lname, b);
	accounts.insert(pair<long, Account>(account.getAccountNumber(), account));
	outfile.open("data.txt", ios::trunc);

	map<long, Account>::iterator itr = accounts.begin();
	accounts.erase(0);
	for (itr = accounts.begin(); itr != accounts.end(); itr++)
	{
		outfile << itr->second;
	}
	outfile.close();
	return account;
}

Account Bank::BalanceEnquiry(long accoutNumber)
{
	map<long, Account>::iterator itr = accounts.find(accoutNumber);
	return itr->second;
}

Account Bank::Deposite(long accountNumber, float b)
{
	map<long, Account>::iterator itr = accounts.find(accountNumber);
	itr->second.deposite(b);
	return itr->second;
}

Account Bank::Withraw(long accountNumber, float b)
{
	map<long, Account>::iterator itr = accounts.find(accountNumber);
	itr->second.withdraw(b);
	return itr->second;
}

void Bank::Close(long accountNumber)
{
	map<long, Account>::iterator itr = accounts.find(accountNumber);
	cout << "Deleted Account Detail: " << itr->second;
	accounts.erase(accountNumber);

	ofstream out("xyz.txt");
	for (itr = accounts.begin(); itr != accounts.end(); itr++)
	{
		out << itr->second;
	}

	remove("data.txt");

	int result;
	char oldname[] = "xyz.txt";
	char newname[] = "data.txt";
	result = rename(oldname, newname);
	if (result == 0)
		puts("File successfully renamed");
	else
		perror("Error renaming file");
}

void Bank::ShowAllAccountInAsce()
{
	map<long, Account>::iterator itr;
	for (itr = accounts.begin(); itr != accounts.end(); itr++)
	{
		cout << "Account " << itr->first << endl << itr->second << endl;
	}
}

void Bank::ShowAllAccountInDesc()
{
	map<long, Account>::reverse_iterator itr;
	for (itr = accounts.rbegin(); itr != accounts.rend(); itr++)
	{
		cout << "Account " << itr->first << endl << itr->second << endl;
	}

}

Bank::~Bank()
{
	ofstream outfile("data.txt");
	map<long, Account>::iterator itr;

	for (itr = accounts.begin(); itr != accounts.end(); itr++)
	{
		outfile << itr->second;
	}
	outfile.close();
}