#ifndef _TABLE_D_H_
#define _TABLE_D_H_
#include <iostream>
namespace Alphabet{
    class alphabet{
    private:
        static const int MAX=100;
        int size;
        char a[MAX];
    public:
        alphabet();
        alphabet(int N);
        alphabet(char str[]);
        alphabet& in();
        std::ostream & print(std::ostream&) const;
        alphabet& total(const alphabet& b);
        alphabet& add(char s);
        int getSZ(){
            return size;
        }
        void cod(char* str,int n) const;
        void decod( char* str,int n) const;
        int entry(char a) const;
    };
}
#endif