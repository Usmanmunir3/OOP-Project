#include <iostream>
#include "Administration.h"
using namespace std;
int main()
{
	char name[50];
	char school[50];
	Administration sum;
	char con;
	cout << "  LIBRARY MANAGEMENT SYSTEM" << endl;
	cout << "==========================" << endl;
	cout << "MADE BY : TYPE YOUE NAME HERE ";
	cin.getline(name, 50);
	cout << "SCHOOOL: your school name_ ";
	cin.getline(school, 50);
	while (true)
	{
		cout << "   Main menu" << endl;
		cout << "1. Book Issue" << endl;
		cout << "2. Book Deposit" << endl;
		cout << "3. Administration Menu" << endl;
		cout << "4. Exit" << endl;
		cout << "   Please Select Your Option from (1-4): " << endl;
		int c;
		cin >> c;
		cin.ignore();
		switch (c)
		{
		case 1:
		{
				  cout << "  Book Issue" << endl;
				  cout << "==============" << endl;
				  char admission[10];
				  char book[10];
				  cout << "Enter the student admission no: ";
				  cin.getline(admission, 10);
				  cout << "Enter the book no.: ";
				  cin.getline(book, 10);
				  cout << "Book issued " << endl;
				  break;
		}
		case 2:
		{
				  cout << "  Book Depoit" << endl;
				  cout << "=================" << endl;
				  char admission[10];
				  char book[10];
				  int num;
				  cout << "Enter the student admission no: ";
				  cin.getline(admission, 10);
				  cout << "Enter the book no: ";
				  cin.getline(book, 10);
				  cout << "Book deposited in the number of days: ";
				  cin >> num;
				  cout << "Book deposited " << endl;
				  break;
		}
		case 3:
		{
				  cout << "   Administrator Menu" << endl;
				  cout << "==================" << endl;
				  cout << "1 Create Student Record" << endl;
				  cout << "2 Display all student Record" << endl;
				  cout << "3 Display specific student record" << endl;
				  cout << "4 Modify Student Record " << endl;
				  cout << "5 Delete Student Record" << endl;
				  cout << "6 Create book" << endl;
				  cout << "7 Display all books " << endl;
				  cout << "8 Display Specific book" << endl;
				  cout << "9 Modify book reord" << endl;
				  cout << "10 Delete book record" << endl;
				  cout << "11 Back to main menu" << endl;
				  cout << "  Please enter your choice from (1-11): ";

				  int c;
				  cin >> c;
				  cin.ignore();
				  switch (c)
				  {
				  case 1:
					  sum.addStudent();
					  break;
				  case 2:
					  sum.displaystudents();
					  break;
				  case 3:
					  sum.displaystudent();
					  break;
				  case 4:
					  sum.modifystudent();
					  break;
				  case 5:
					  sum.deletestudent();
					  break;
				  case 6:
					  sum.Books();
					  break;
				  case 7:
					  sum.displayBook();
					  break;
				  case 8:
					  sum.displayspecificBook();
					  break;
				  case 9:
					  sum.modifyBook();
					  break;
				  case 10:
					  sum.deleteBook();
					  break;
				  case 11:
					  break;
				  default:
					  cout << "Invalid choice. please try again" << endl;
				  }
				  break;
		}
		case 4:
			cout << "  Thank you for using the library management system Sir Umer" << endl;
			return 0;
		default:
			cout << "Invalid choice please try again." << endl;
		}
		cout << endl;
		cout << "Do you want to continue (y/n)? ";
		cin >> con;
		cin.ignore();

	} while (con == 'y' || con == 'Y');

	return 0;
}