#include<string>
#include<vector>
#include<iostream>
using namespace std;

int nextId();

template <class T>
bool removeFrom(const T& m, vector<T>& v);

class Book{
	protected:
	string title;
	string author;
	int id;
	public:
	Book();
	Book(string t, string a);
	Book(const Book& b);
	int operator==(const Book& b);
	void show();
	int getId();
	~Book();
};

class User{
	protected:
	int id;
	string name;
	public:
	vector<Book>currentBooks;
	virtual bool wypozycz(Book& b){return true;}
	bool oddaj(int bookId);
	bool operator==(const User& u);
	void showCurrentBooks();
	int getId();
};

class basicUser : public User{
	protected:
	static const int limit = 5;
	public:
	basicUser();
	basicUser(string n);
	bool wypozycz(Book& b);
};

class superUser : public User{
	public:
	superUser();
	superUser(string n);
	bool wypozycz(Book& b);
};


	User* findUserById(int id);
	Book& findBookById(int id);
	bool addBook(string title, string author);
	void addUser(string n);
	bool wypozycz(int userId,int bookId);
	bool oddaj(int userId,int bookId);

vector<User*>* getUsers();
