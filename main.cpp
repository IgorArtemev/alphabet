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
		int d = 0;
		input(d);
		return d;
	}

	int menu(int d, alphabet& a) {
		switch (d) {
		case 0: return 0;
		case 1: {
			a.print(std::cout);
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
			a.print(std::cout);
			break;
		}
		case 3:{
			char s;
			print("Enter charater:");
			cin>>s;
			try{a.add(s);
			}
			 catch(std::exception &ex){
                std::cout<<ex.what()<<std::endl;
            }
			break;
		}
		case 4:{
			alphabet tmp1(0);
			try{
			tmp1.in();
			a.total(tmp1);
			}
			catch(std::exception &ex){
            std::cout<<ex.what()<<std::endl;
            }
			break;
		}
		case 5:{
			char s;
			print("Enter charater:");
			cin>>s;
			if(a.entry(s)!=-1)
				print("This characteк is in the alphabet");
			else
				print("This characteк is not in the alphabet");
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
			print(s);
			}
			catch(std::exception &ex){
                std::cout<<ex.what()<<std::endl;
            	}
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
			print(s);
			}
			catch(std::exception &ex){
                std::cout<<ex.what()<<std::endl;
            	}
			break;
		}
		default: {
			print("incorrect choice");
		}
		}
		return 1;
	}
	int main(){
	alphabet a;
	int q = 0;
	a.print(std::cout);
	do {
		int d = dialog();
		q=menu(d, a);
	} while (q);
	return 0;
	}