/*
Project		: Bank System
Developer	: Dev Patel
Date		: 
*/


#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <fstream>
#include <stdlib.h>
#include<Windows.h>

using namespace std;

#include "Account.h"
#include "Bank.h"


int main()
{
	Bank b;//Object of derived class 
	Account acc;//Object of base class 

	int choice;
	string fname, lname;
	long accountNumber;
	float balance;
	float amount;
	system("color 0A");
	cout << "***Banking System***" << endl;
	do
	{
		//MENU
		cout << "\n\t\t\t----------------------------------------------\t\t\t";
		cout << "\n\t\t\tSelect one option below\t\t\t\n ";
		cout << "\n\t\t\t1 Open an Account\t\t\t\n";
		cout << "\n\t\t\t2 Balance Enquiry\t\t\t\n";
		cout << "\n\t\t\t3 Deposit\t\t\t\n";
		cout << "\n\t\t\t4 Withdrawal\t\t\t\n";
		cout << "\n\t\t\t5 Close an Account\t\t\t\n";
		cout << "\n\t\t\t6 Show All Accounts in ascending order\t\t\t\n";
		cout << "\n\t\t\t7 Show All Accounts in descending order\t\t\t\n";
		cout << "\n\t\t\t8 Quit\t\t\t\n";
		cout << "\t\t\t----------------------------------------------\t\t\t\n";
		cout << "Enter your choice: ";
		cin >> choice;
		system("CLS");
		switch (choice)
		{
		case 1:
			
			cout << "Enter First Name: ";cin >> fname;
			cout << "Enter Last Name: ";cin >> lname;
			cout << "Enter initil Balance (minimum balance must be 1500): ";cin >> balance;
			acc = b.OpenAccount(fname, lname, balance);
			cout << endl << "Congratulation Account is Created" << endl;
			cout << acc;
			cout << "\n\t\t\tPlease wait for 5 sec";
			Sleep(5000);
			system("CLS");
			break;
		case 2:
			cout << "Enter Account Number:";
			cin >> accountNumber;
			acc = b.BalanceEnquiry(accountNumber);
			cout << endl << "Your Account Details" << endl;
			cout << acc;
			cout << "\n\t\t\tPlease wait for 5 sec";
			Sleep(5000);
			system("CLS");
			break;
		case 3:
			cout << "Enter Account Number:";
			cin >> accountNumber;
			cout << "your account balance right now : " << acc.getBalance() << endl;
			cout << "Enter Balance:";
			cin >> amount;
			acc = b.Deposite(accountNumber, amount);
			cout << endl << "Amount is Deposited" << endl;
			cout << acc;
			cout << "\n\t\t\tPlease wait for 5 sec";
			Sleep(5000);
			system("CLS");
			break;
		case 4:
			cout << "Enter Account Number:";
			cin >> accountNumber;
			cout << "your account balance right now : " << acc.getBalance() << endl;
			cout << "Enter Balance:";
			cin >> amount;
			acc = b.Withraw(accountNumber, amount);
			cout << endl << "Amount Withdrawn" << endl;
			cout << acc;
			cout << "\n\t\t\tPlease wait for 5 sec";
			Sleep(5000);
			system("CLS");
			break;
		case 5:
			cout << "Enter Account Number:";
			cin >> accountNumber;
			b.Close(accountNumber);
			cout << endl << "Account is Closed\n\n" << endl;
			cout << "\n\t\t\tPlease wait for 5 sec";
			Sleep(50000);
			system("CLS");
			break;
		case 6:
			b.ShowAllAccountInAsce();
			cout << "\n\t\t\tPlease wait for 10 sec";
			Sleep(10000);
			system("CLS");
			break;
		case 7:
			b.ShowAllAccountInDesc();
			cout << "\n\t\t\tPlease wait for 10 sec";
			Sleep(10000);
			system("CLS");
			break;
		case 8: break;
		default:cout << "\nEnter corret choice";
			exit(0);
		}
		
	} while (choice != 8);
	return 0;
}
