#pragma once

/*
 Class Name: Account
 Purpose   : This is base class is used for user details such as first name, last name and account balance
*/

class Account
{
private:
	long accountNumber;
	string firstname;
	string lastname;
	float balance;
	static long nextac;
public:
	Account() {	accountNumber = 00;balance = 00;}//non-perameterize constructor
	Account(string fname, string lname, float b);//perameterize constructor
	long getAccountNumber() { return accountNumber; }//get account number
	void setFitsname(string fn) { firstname = fn; }//set the first name
	string getFirstname() { return firstname; }//get the first name
	void setLastname(string ln) { lastname = ln; }//set the last name
	string getLastName() { return lastname; }//get the last name
	void setBalance(float b);//set account balance
	float getBalance() { return balance; }//get the account balance


	static void setLasttac(long accountNumber);//set the last account number whatever number last in file
	static long getLastAc();//get the last account number

	void deposite(float b) { balance = balance + b; }//deposit money in the amount
	void withdraw(float b) { balance = balance - b; }//withraw money from the account


	friend ofstream& operator<<(ofstream& ofs, Account& a);//overload ofstream operator
	friend ifstream& operator>>(ifstream& ifs, Account& a);//overload ifstream operator
	friend ostream& operator<<(ostream& out, Account& a);//overload cout operator
};
long Account::nextac = 0;//static variable initialize 0 


Account::Account(string fname, string lname, float b)
{
	nextac++;
	accountNumber = nextac;
	setFitsname(fname);
	setLastname(lname);
	setBalance(b);
}

void Account::setBalance(float b)
{
	
	if (b > 1500)
		balance = b;
	else
	{
		cout << "Minimum Balance must be 1500";
		cout << "please enter amount again: ";
		cin >> b;
		setBalance(b);
	}
}

void Account::setLasttac(long accountNumber)
{
	nextac = accountNumber;
}

long Account::getLastAc()
{
	return nextac;
}

ofstream& operator<<(ofstream& ofs, Account& a)
{
	ofs  << a.accountNumber << endl;
	ofs  << a.firstname << endl;
	ofs  << a.lastname << endl;
	ofs << a.balance << endl;
	return ofs;
}

ifstream& operator>>(ifstream& ifs, Account& a)
{
	ifs >> a.accountNumber;
	ifs >> a.firstname;
	ifs >> a.lastname;
	ifs >> a.balance;
	return ifs;
}

ostream& operator<<(ostream& out, Account& a)
{
	cout << "Account Number: " << a.accountNumber << endl;
	cout << "First Name: " << a.firstname << endl;
	cout << "Lirst Name: " << a.lastname << endl;
	cout << "Account Balance: " << a.balance << endl;
	return out;
}