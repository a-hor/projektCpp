#include"defs.h"

int currentId=-1;

vector<Book>books;
vector<User*>users;

vector<User*>* getUsers(){
	return &users;
}

int nextId(){
	return ++currentId;
}

template <class T>
bool removeFrom(const T& m, vector<T>& v){
	try{
		typename vector<T>::iterator it;
		it=v.begin();
		while((!(*it==m))){
			++it;
		}
		v.erase(it);
	}
	catch(const exception& e){
		cout<<"exception: "<<e.what()<<"\n";
		return false;
	}
 return true;
}

	Book::Book(){
		title="";author="";id=nextId();
	}
	Book::Book(string t, string a){
		title=t;
		author=a;
		id=nextId();
	}
	Book::Book(const Book& b) : title(b.title), author(b.author){
		id=nextId();
	}
	int Book::operator==(const Book& b){
		return id==b.id;
	}
	void Book::show(){
		cout<<"id = "<<id<<" title = "<<title<<" author = "<<author<<endl;
	}
	int Book::getId(){
		return id;
	}
	Book::~Book(){
		cout<<"Book deleted\n";
	}

	bool User::oddaj(int bookId){
		for(int i=-1;++i;){
			if(currentBooks[i].getId()==bookId){
				removeFrom(currentBooks[i],currentBooks);
			}
		}
		return true;
	}
	bool User::operator==(const User& u){
		return id==u.id;
	}
	void User::showCurrentBooks(){
		for(auto& b : currentBooks)b.show();
	}
	int User::getId(){
		return id;
	}

	basicUser::basicUser(){
		id=nextId();
		name="";
		cout<<"Basic user created: "<<id<<"\n";
	}
	basicUser::basicUser(string n){
		id=nextId();
		name=n;
		cout<<"Basic user created: "<<id<<" "<<name<<"\n";
	}
	bool basicUser::wypozycz(Book& b){
		if(currentBooks.size()>=limit){
			cout<<"limit for basic user exceeded\n";
			return false;
		}
		currentBooks.push_back(b);
		return true;
	}

	superUser::superUser(){
		id=nextId();
		name="";
		cout<<"Unlimited user created: "<<id<<"\n";
	}
	superUser::superUser(string n){
		id=nextId();
		name=n;
		cout<<"Unlimited user created: "<<id<<" "<<name<<"\n";
	}
	bool superUser::wypozycz(Book& b){
		currentBooks.push_back(b);
		return true;
	}



	User* findUserById(int id){
		for(int j=-1;++j<users.size();){
					if(users[j]->getId()==id)return users[j];
				}
		return users[0];
	}
	Book& findBookById(int id){
		for(int j=-1;++j<books.size();){
					if(books[j].getId()==id)return books[j];
				}
		return books[0];
	}
	bool addBook(string title, string author){
		books.push_back(move (Book(title,author)));
		cout<<"dodano ksiazke ";
		books.back().show();
		return true;
	}
	void addUser(string n){
		users.push_back(new basicUser(n));
	}
	bool wypozycz(int userId,int bookId){
		for(int i=-1;++i<books.size();){
			if(books[i].getId()==bookId){
				return findUserById(userId)->wypozycz(books[i]);
				}

			}
		return false;
	}
	bool oddaj(int userId,int bookId){
		for(int i=-1;++i<users.size();){
			if(users[i]->getId()==userId){
				return users[i]->oddaj(bookId);

			}
		}
		return false;
	}


