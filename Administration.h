class Book {
private:
	char bookn[10];
	char bookname[50];
	char author[50];
	bool num;

public:
	void setbdetail(const char* bookn, const char* bookname, const char* author);
	void displayb() const;
	bool match(const char* bookn) const;
	bool issue() const;
	void setissue(bool s);
};
class Student {
private:
	char admission[10];
	char student[50];

public:
	void setdetail(const char* admission, const char* student);
	void displays() const;
	bool match(const char* admission) const;
};

class Administration {
private:
	Book book[100];
	int count;
	Student stu[100];
	int st;

public:
	Administration();
	void Books();
	void displayBook() const;
	void displayspecificBook() const;
	void issueBook(const char* admission, const char* bookn);
	void modifyBook();
	void deleteBook();
	void addStudent();
	void displaystudents() const;
	void displaystudent() const;
	void modifystudent();
	void deletestudent();
};