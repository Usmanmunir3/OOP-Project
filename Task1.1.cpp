#include <iostream>
#include "Administration.h"
using namespace std;
void Book::setbdetail(const char* bookn, const char* bookname, const char* author)
{
    int i = 0;
	while (bookn[i] != '\0' && i < 10) 
	{
		this->bookn[i] = bookn[i];
		i++;
	}
	this->bookn[i] = '\0';
	i = 0;
	while (bookname[i] != '\0' && i < 50)
	{
		this->bookname[i] = bookname[i];
		i++;
	}
	this->bookname[i] = '\0';
	i = 0;
	while (author[i] != '\0' && i < 50)
	{
		this->author[i] = author[i];
		i++;
	}
	this->author[i] = '\0';


}

void Book::displayb() const
{
	cout << "Book no.: " << bookn << endl;
	cout << "Book name: " << bookname << endl;
	cout << "Author name: " << author << endl;
}

bool Book::match(const char* bookn) const
{
	int i = 0;
	while (this->bookn[i] != '\0' && bookn[i] != '\0')
	{
		if (this->bookn[i] != bookn[i])
		{
			return false;
		}
		i++;
	}
	return (this->bookn[i] == '\0' && bookn[i] == '\0');
}

void Book::setissue(bool s)
{
	num = s;
}
void Student::setdetail(const char* admission, const char* student)
{
	int i = 0;
	while (admission[i] != '\0' && i < 10)
	{
		this->admission[i] = admission[i];
		i++;
	}
	this->admission[i] = '\0';
	i = 0;
	while (student[i] != '\0' && i < 50) {

		this->student[i] = student[i];
		i++;
	}
	this->student[i] = '\0';
}
void Student::displays() const 
{
	cout << "Admission no: " << admission << endl;
	cout << "Student name: " << student << endl;
}

bool Student::match(const char* admissionNo) const
{
	int i = 0;
	while (this->admission[i] != '\0' && admission[i] != '\0')
	{
		if (this->admission[i] != admission[i])
		{
			return false;
		}
		i++;
	}
	return (this->admission[i] == '\0' && admission[i] == '\0');
}
Administration::Administration() 
{
	count = 0;
	st = 0;
}

void Administration::Books()
{
	if (count < 100) 
	{
		char bookn[10];
		char bookname[50];
		char author[50];
		cout << "  Add book" << endl;
		cout << "=============" << endl;
		cout << "Enter the book no: ";
		cin.getline(bookn, 10);
		cout << "Enter the name of the book: ";
		cin.getline(bookname, 50);
		cout << "Enter the author name: ";
		cin.getline(author, 50);
		book[count].setbdetail(bookn, bookname, author);
		count++;
		cout << "Book added " << endl;
	}
	else 
	{
		cout << "Book Limit Exceede" << endl;
	}
}

void Administration::displayBook() const
{
	cout << "  Display all books" << endl;
	cout << "=========================================" << std::endl;

	if (count > 0) 
	{
		for (int i = 0; i < count; i++)
		{
			cout << "Book " << i + 1 << ":" << endl;
			book[i].displayb();
			cout << endl;
		}
	}
	else 
	{
		cout << "No Book found." << endl;
	}
}

void Administration::displayspecificBook() const
{
	cout << "   Display specific Book" << endl;
	cout << "=========================================" << std::endl;

	char bookn[10];
	cout << "Enter the book no: ";
	cin.getline(bookn, 10);

	for (int i = 0; i < count; i++)
	{
		if (book[i].match(bookn))
		{
			book[i].displayb();
			return;
		}
	}

	cout << "Book not found." << endl;
}

void Administration::modifyBook() 
{
	cout << "  Modify Book" << endl;
	cout << "============================================" << endl;

	char bookn[10];
	cout << "Enter the book no: ";
	cin.getline(bookn, 10);
	for (int i = 0; i < count; i++)
	{
		if (book[i].match(bookn)) 
		{
			char bookn[50];
			char author[50];
			cout << "Enter new name of teh book: ";
			cin.getline(bookn, 50);
			cout << "Enter New Author's Name: ";
			cin.getline(author, 50);
			book[i].setbdetail(bookn, bookn, author);
			cout << "Book Modified." << endl;
			return;
		}
	}

	cout << "Book not found." << endl;
}

void Administration::deleteBook() 
{
	cout << "  Delete Book" << endl;
	cout << "==========================" << endl;
	char bookn[10];
	cout << "Enter the book no: ";
	cin.getline(bookn, 10);

	for (int i = 0; i < count; i++) 
	{
		if (book[i].match(bookn))
		{
			for (int j = i; j < count - 1; j++)
			{
				book[j] = book[j + 1];
			}
			count--;
			cout << "Book deleted" << endl;
			return;
		}
	}

	cout << "book not found." << endl;
}

void Administration::addStudent() 
{
	if (st < 100) 
	{
		char admission[10];
		char student[50];

		cout << "  add Student" << endl;
		cout << "==========================================================" << endl;
		cout << "Enter the admission no: ";
		cin.getline(admission, 10);
		cout << "Enter the name of student: ";
		cin.getline(student, 50);
		stu[st].setdetail(admission, student);
		st++;

		cout << "Student record created." << endl;
	}
	else 
	{
		cout << "Student limit Exceeded" << endl;
	}
}

void Administration::displaystudents() const 
{
	cout << "   Display all students" << endl;
	cout << "===================================================" << endl;

	if (st > 0)
	{
		for (int i = 0; i < st; i++) 
		{
			cout << "Student " << i + 1 << ":" << endl;
			stu[i].displays();
			cout << endl;
		}
	}
	else 
	{
		cout << "No students found." << endl;
	}
}

void Administration::displaystudent() const
{
	cout << "  Display Specific student" << endl;
    cout << "========================================" << endl;
	char admission[10];
	cout << "Enter the admission no: ";
	cin.getline(admission, 10);
	for (int i = 0; i < st; i++) 
	{
		if (stu[i].match(admission))
		{
			stu[i].displays();
			return;
		}
	}

	cout << "Student not found." << endl;
}

void Administration::modifystudent()
{
	cout << "   Modify Student" << endl;
	cout << "==========================================" << endl;
    char admission[10];
	cout << "Enter admission no: ";
	cin.getline(admission, 10);

	for (int i = 0; i < st; i++)
	{
		if (stu[i].match(admission)) 
		{
			char student[50];

			cout << "Enter new name of student: ";
			cin.getline(student, 50);
			stu[i].setdetail(admission, student);
			cout << "Student record modified" <<endl;
			return;
		}
	}

	cout << "Student not found." << endl;
}

void Administration::issueBook(const char* admission, const char* bookn)
{
	cout << "   Booo Issue" << endl;
	cout << "=====================================" << endl;
	cout << "Enter the student admission no: " << admission << endl;
	cout << "Enter the book no: " << bookn << endl;
	cout << "Book issued " << endl;
}

void Administration::deletestudent() 
{
	cout << "  Delete Student" << endl;
	cout << "================================================" << endl;

	char admission[10];
	cout << "Enter the admission no: ";
	cin.getline(admission, 10);
	for (int i = 0; i < st; i++)
	{
		if (stu[i].match(admission))
		{
			for (int j = i; j < st - 1; j++) 
			{
				stu[j] = stu[j + 1];
			}
			st--;
		cout << "Student record deleted " << endl;
			return;
		}
	}

	cout << "Student not found." << endl;
}