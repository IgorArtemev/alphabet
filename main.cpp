#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "alphabet.cpp"
using namespace Alphabet;
using namespace std;
template<class T>
	void print(T a) {
		std::cout << a << std::endl;
	}
int dialog() {
		print("choose what to do");
		print("0 - quit");
		print("1 - print the alphabet");
		print("2 - craete a new alhabet");
		print("3 - add new character in the alphabet");
		print("4 - union the alphabets");
		print("5 - check entry of character in the alphabet");
		print("6 - coding of string");
		print("7 - decoding of string");
		print("8 - adding 'a' and 'qwerty' and 'rtehsd'");
		int d = 0;
		input(d);
		return d;
	}

	int menu(int d, alphabet& a) {
		switch (d) {
		case 0: return 0;
		case 1: {
			cout<<a;
			break;
		}
		case 2: {
			int r;
			print("choose what to do");
			print("0 - defolt constructor");
			print("1 - initialization by number");
			print("2 - initialization by string");
			input(r);
			switch(r){
			case 0:{
				alphabet tmp;
				a=tmp;
				break;	
			}
			case 1:{
				int n;
				input(n);
				try{
					a=n;
				}
				catch(std::exception &ex){
                std::cout<<ex.what()<<std::endl;
            	}
				break;
			}
			case 2:{
				char s[256];
				std::cin.ignore(1);
				cin.getline (s,256);
				try{
				alphabet tmp(s);
				a=tmp;
				}
				catch(std::exception &ex){
                std::cout<<ex.what()<<std::endl;
            	}
				break;
			}
			}
			cout<<a;
			break;
		}
		case 3:{
			char s;
			print("Enter charater:");
			cin>>s;
			try{a+=s;
			}
			 catch(std::exception &ex){
                std::cout<<ex.what()<<std::endl;
            }
			break;
		}
		case 4:{
			alphabet tmp1(0);
			try{
			cin>>tmp1;
			a+=tmp1;
			}
			catch(std::exception &ex){
            std::cout<<ex.what()<<std::endl;
            }
			break;
		}
		case 5:{
			char s;
			print("Enter character:");
			cin>>s;
			if(a(s)!=-1)
				print("This character is in the alphabet");
			else
				print("This character is not in the alphabet");
			break;
		}
		case 6:{
			char s[256];
			char e;
			int n;
			print("Enter the string:");
			std::cin.ignore(1);
			cin.getline (s,256);
			print("Enter the number:");
			input(n);
			try{a.cod(s,n);
			}
			catch(std::exception &ex){
                std::cout<<ex.what()<<std::endl;
            	}
			print(s);
			break;
		}
		case 7:{
			char s[256];
			char e;
			int n;
			print("Enter the string:");
			std::cin.ignore(1);
			cin.getline (s,256);
			print("Enter the number:");
			input(n);
			try{
			a.decod(s,n);
			}
			catch(std::exception &ex){
                std::cout<<ex.what()<<std::endl;
            	}
			print(s);
			break;
		}
		case 8:{
			char ch='a';
			alphabet b("qwerty") ;
			alphabet c("rtehsd");
			alphabet s;
			s=a+ch+b+c;
			cout<<s;
			break;
		}
		default: {
			print("incorrect choice");
		}
		}
		return 1;
	}
	int main(){
	alphabet a("abc");
	char c1('d');
	char c2('k');
	a+=c1;
	cout<<a;
	alphabet b("edfa");
	b=c2+a+b;
	cout<<b;
	int q = 0;
	do {
		int d = dialog();
		q=menu(d, a);
	} while (q);
	return 0;
	}