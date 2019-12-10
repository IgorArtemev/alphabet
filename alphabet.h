#ifndef _TABLE_D_H_
#define _TABLE_D_H_
#include <iostream>
namespace Alphabet{
    class alphabet{
    private:;
        int size;
        char *a;
    public:
        alphabet();
        alphabet(char);
        alphabet(int N);
        alphabet(char* str);
        alphabet(const alphabet&);
        alphabet(alphabet&&);
        alphabet& operator =(const alphabet&);
        alphabet& operator =(alphabet&&);
        ~alphabet() {delete[] a;};
        friend std::istream & operator >>(std::istream&, alphabet &);
        friend std::ostream & operator <<(std::ostream&, const alphabet &);
        friend const alphabet operator +(const alphabet& l,const alphabet& r);
        alphabet& operator +=(const alphabet& b);
        alphabet& operator +=(char s);
        int getSZ(){
            return size;
        }
        void cod(char* str,int n) const;
        void decod( char* str,int n) const;
        int operator ()(char a) const;
    };
}
#endif