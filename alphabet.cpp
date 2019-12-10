#include <iostream>
#include <stdio.h>
#include <string.h>
#include "alphabet.h"
using namespace Alphabet;
using namespace std;
namespace Alphabet{
     char* getstr() {
		char* ptr = (char*)malloc(1);
		char buf[256];
		int len = 0;
        std::cin.ignore(1);
		cin.getline (buf,256);
		len += strlen(buf);
		ptr = (char*)realloc(ptr, len + 1);
		strcat(ptr, buf);
        ptr[len+1]='\0';
		return ptr;
	}
    template <class T>
	int input(T& number) {
    int res, err_flag = 0;
	do {
		err_flag = 0;
		std::cin >> number;
        if (std::cin.eof()){
            std::cin.clear();
            std::cin.ignore(256, '\n');
            return 0;
        }
		if (std::cin.good()) {
			res = 1;
		}
		else {
            std::cin.clear();
            std::cin.ignore(256, '\n');
			res=-1;
		}

		if (res < 0) {
			err_flag = 1;
			std::cout << "You are wrong" << std::endl;
		}
		if (err_flag) {
			std::cout << "Try again -->";
		}
	} while (err_flag);
    return res;
	};
    alphabet::alphabet(){
        size=95;
        for(int i=0; i<95;++i){
            a[i]=i+32;
        }
    };
    alphabet::alphabet(char s){
        size=1;
        a[0]=s;
    }
    alphabet::alphabet(int N){
        if (N<0 || N>256 || N>MAX){
            throw std::runtime_error("Incorect size");
        }
        size=N;
        for(int i=0;i<N;++i){
            a[i]=i;
        }
    };
    alphabet::alphabet(char* str){
        int j=0;
        alphabet tmp(0);
        for(int i=0;i<strlen(str);++i){
            if (tmp(str[i])==-1){
                if (j==MAX||j>255){
                    throw std::runtime_error("Incorect size");
                }
                tmp+=str[i];
                a[j]=str[i];
                ++j;   
            }
        }
        size=j;
    };
    std::istream & operator >>(std::istream& i, alphabet& a){
       char* str=getstr();
       if (i.fail()) {
			i.setstate(std::ios::failbit);
		}
        a=str;
        return i;
    };
    std::ostream & operator <<(std::ostream& s, const alphabet & a){
        for(int i=0;i<a.size;++i)
            s<<a.a[i]<<' ';
        s<<endl;
        return s;
    };
    const alphabet operator +(const alphabet& l, const alphabet& r){
        alphabet tmp;
        tmp=l;
        tmp+=r;
        return tmp;
    }
    alphabet& alphabet::operator +=(const alphabet& s){
        int k=size;
        for (int i=0;i<s.size;++i){
            if (k==MAX)
                    throw std::runtime_error("Too many symbols");
            if (((*this)(s.a[i])==-1)){
                a[k]=s.a[i];
                ++k;
            }
        }
        size=k;
        return *this;
    }
    alphabet& alphabet::operator +=(char s){
        if(((*this)(s)!=-1))
          throw  runtime_error("This  character is already written in the alphabet");
        if(size==MAX)
          throw  runtime_error("The aphabet is full");
        a[size]=s;
        ++size;
        return *this;
    }
    void alphabet::cod(char* str,int n) const{
        int k;
        if (n>0){
        for (int i=0; i<strlen(str); ++i){
            k=(*this)(str[i]);
            if(k==-1){
              throw  runtime_error("No one or more character in the alphabet");
            }
            else{
                str[i]=a[(k+n)%size];
            }
        }
        }
        else{
            for (int i=0; i<strlen(str); ++i){
            k=(*this)(str[i]);
            if(k==-1){
              throw  runtime_error("No one or more character in the alphabet");
            }
            else{
                str[i]=a[(k-(-n)%size+size)%size];
            }
        }
        }
    }
    void alphabet::decod(char* str,int n) const{
        int k;
        if (n<0){
        for (int i=0; i<strlen(str); ++i){
            k=(*this)(str[i]);
            if(k==-1){
              throw  runtime_error("No one or more character in the alphabet");
            }
            else{
                str[i]=a[(k-(-n)%size+size)%size];
            }
        }
        }
        else{
            for (int i=0; i<strlen(str); ++i){
            k=(*this)(str[i]);
            if(k==-1){
              throw  runtime_error("No one or more character in the alphabet");
            }
            else{
                str[i]=a[(k-(size-n%size)+size)%size];
            }
        }
        }
    };
    int alphabet::operator ()(char s) const{
        for (int i=0; i<size; ++i){
            if (a[i]==s){
                return i;
            }
        }
        return -1;
    };
}
