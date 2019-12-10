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
        *ptr='\0';
        std::cin.ignore(1);
		cin.getline (buf,256);
		len += strlen(buf);
		ptr = (char*)realloc(ptr, len + 1);
		strcat(ptr, buf);
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
        a=new char[95];
        size=95;
        for(int i=0; i<95;++i){
            a[i]=i+32;
        }
    };
     alphabet::alphabet(char s){
         size=1;
         a=new char[1];
         a[0]=s;
    };
    alphabet::alphabet(int N){
        if (N<0 || N>256){
            throw std::runtime_error("Incorect size");
        }
        size=N;
        a=new char[N];
        for(int i=0;i<N;++i){
            a[i]=i;
        }
    };
    alphabet::alphabet(const alphabet& s){
        size=s.size;
        a=new char[size];
        for(int i=0;i<size;++i){
            a[i]=s.a[i];
        }
    };
    alphabet::alphabet(alphabet &&b){
        size=b.size;
        a=b.a;
        b.a=nullptr;
    };

    alphabet& alphabet::operator =(const alphabet &b){
        if (this!=&b){
            size=b.size;
            delete[] a;
            a=new char[size];
            for(int i=0;i<size;++i){
                a[i]= b.a[i];
            } 
        }
        return *this;
    };
    alphabet& alphabet::operator =(alphabet&& b){
        int tmp=size;
        size=b.size;
        b.size=tmp;
        char *t=a;
        a=b.a;
        b.a=t;
        return *this;
    };
    alphabet::alphabet(char* str){
        int j=0;
        alphabet tmp(0);
        for(int i=0;i<strlen(str);++i){
            if (tmp(str[i])==-1){
                if (j>255){
                    throw std::runtime_error("Incorect size");
                }
                tmp+=str[i];
                ++j;   
            }
        }
        size=j;
        a=new char[size];
        for(int i=0;i<j;++i){
            a[i]=tmp.a[i];
        }
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
    alphabet& alphabet::operator +=(const alphabet& s){
        for (int i=0;i<s.size;++i){
            if (((*this)(s.a[i])==-1)){
                *this+=s.a[i];
            }
        }
        return *this;
    }
    alphabet& alphabet::operator +=(char s){
        if(((*this)(s)!=-1))
          throw  runtime_error("This  character is already written in the alphabet");
        char *old;
        size++;
        old=a;
        a=new char[size];
        for(int i=0;i<size-1;++i)
            a[i]=old[i];
        a[size-1]=s;
        delete[] old;
        return *this;
    }
    const alphabet operator +(const alphabet& l, const alphabet& r){
        alphabet tmp;
        tmp=l;
        tmp+=r;
        return tmp;
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
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
namespace Processor{
    class operation{
        public:
            virtual int operator()(int,int)=0;
    };
    class add:public operation{
        public:
            int operator()(int,int);
    };
    class sub:public operation{
        public:
            int operator()(int,int);
    };
    class mul:public operation{
        public:
            int operator()(int,int);
    };
    class div:public operation{
        public:
            int operator()(int,int);
    };
    class inc:public operation{
        public:
            int operator()(int);
    };
    class dec:public operation{
        public:
            int operator()(int);
    };
    class jmp:public operation{
        public:
            int operator()(string&);
    };
    class operand_descriptor;
    class move:public  operation{
        public:
            int operator()(operand_descriptor*,operand_descriptor*);
    };
    class hlt:public operation{
        public:
            int operator()();
    };
    class nop:public  operation{
        public:
            void operator()();
    };
    class command{                                               
        protected:          
            operation* op;     
        public:
            operation* getOP();
            virtual void show()=0;
            virtual void modify();
    };
    class operand_descriptor{
        protected:
            int type;                           //0-direct,1-register,2-memory
        public:
            int getT();
            virtual int get()=0;
    };
    class registers;
    class reg_operand:public  operand_descriptor{
        private:
            int reg;
        public:
            int getR();
            reg_operand();
            reg_operand(int);
            int get(registers&);
    };
    class data_memory;
    class id_operand:public  operand_descriptor{
        private:
            string str;
        public:
            string getStr();
            id_operand();
            id_operand(string&);
            int get(data_memory&);
    };
    class direct_operand:public  operand_descriptor{
        private:
            int number;
        public:
            direct_operand();
            direct_operand(int);
            int get();
    };
    class unary_command:public command{
        private:
            string mark;
            operand_descriptor* operand; 
        public:
            string getM();
            operand_descriptor* getOp();
            unary_command();
            unary_command(string&,operand_descriptor*);
            void show();
            void modify();   
    };
    class binary_command:public virtual command{
        private:
            string mark;
            operand_descriptor* first;
            operand_descriptor* second;
        public:
            string getM();
            operand_descriptor* getF();
            operand_descriptor* getS();
            binary_command();
            binary_command(string&,operand_descriptor*,operand_descriptor*);
            void show();
            void modify();   
    };  
    class transition_command: public command{
        private:
            string mark;
        public:
            string getM();
            transition_command();
            transition_command(string&);
            void show();
            void modify();
    } ;
    class move_command:public command{
        private:
            operand_descriptor* first;
            operand_descriptor* second;
        public:
            operand_descriptor* getF();
            operand_descriptor* getS();
            move_command();
            move_command(operand_descriptor*,operand_descriptor*);
            void show();
            void modify(); 
    };
    struct cell{
        int a;
        bool free;
    };
    class registers{
        private:
            int N;
            vector<cell> rg;
        public:
            registers();
            registers(int);
            int insert(int);
            int get(int);
            void block(int);
    };
    class actuator{
        private:
            bool empty;
            int time;
            vector<operation*> set;
        public:
            actuator(int,vector<operation*>&);
            bool getEmpty();
            vector<operation*>& getOp();
            int execution(command&);
            ~actuator();
    };
    class control_device{
        public:
            control_device();
            actuator* selection(command&,vector<actuator>&);
            void transition(command&);
    };
    class program_memory{
        private:
            int ip;
            vector<command> arr;
            map<string,int> marks;
        public:
            program_memory();
            command& getCommand();
            void show();
            program_memory& setIP(int);
            program_memory& modify();
            ~program_memory();
    };
    class data_memory{
        private:
            int size;
            map<string,int> arr;
        public:
            data_memory();
            data_memory(int);
            int get(string&);
            void block(string&);
            void add(string&,int);
            ~data_memory();
    };
    class processor{
        private:
            string name;
            control_device cd;
            registers reg;
            int n_act;
            vector<actuator> act;
            program_memory pr_m;
            data_memory data_m;
        public:
            processor();
            processor& modify();
            int execution(vector<command>&); 
            ~processor();         
    };
}