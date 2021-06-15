#include"defs.h"
int main(){
	std::cout<<"Program biblioteczny\n";
	bool q=true;
	int w,id0,id1;
	string s0,s1;
	do{
		std::cout<<"Wybierz działanie:\n";
		std::cout<<"0. Zakończ program\n1. Wypożycz (podaj id ksiazki i id uzytkownika) \n2. Oddaj (podaj id ksiazki i id uzytkownika)\n3. Dodaj książkę (podaj tytul i autora)\n4. Dodaj zwyklego użytkownika (podaj nazwe)\n5. Pokaz ksiazki uzytkownika (podaj id)\n";
		std::cin>>w;
		switch(w){
			case 0:{ q=false;break;}
			case 1: {
				cin>>id0>>id1;
				wypozycz(id0,id1);
				break;}
			case 2: {
				cin>>id0>>id1;
				oddaj(id0,id1);
				break;}
			case 3: {
				cin>>s0>>s1;
				addBook(s0,s1);
				break;}
			case 4: {
				cin>>s0;
				basicUser bu(s0);
				getUsers()->push_back(move(&bu));
				break;
			}
			case 5: {
				cin>>id0;
				findUserById(id0)->showCurrentBooks();
			break;}
		}

	}while(q);
}