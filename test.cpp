z#include <gtest/gtest.h>
#include "alphabet.cpp"
using namespace Alphabet;
TEST(alphabetConst,DefConst){
	alphabet a;
	ASSERT_EQ(95,a.getSZ());
}
TEST(alphabetConst,NumConst){
	int n1=0;
	alphabet a1(n1);
	ASSERT_EQ(n1,a1.getSZ());
	int n2=1;
	alphabet a2(n2);
	ASSERT_EQ(n2,a2.getSZ());
	int n3=10;
	alphabet a3(n3);
	ASSERT_EQ(n3,a3.getSZ());
	int n4=20;
	alphabet a4(n4);
	ASSERT_EQ(n4,a4.getSZ());
	int n5=40;
	alphabet a5(n5);
	ASSERT_EQ(n5,a5.getSZ());
	int n6=100;
	alphabet a6(n6);
	ASSERT_EQ(n6,a6.getSZ());
}
TEST(alphabetConst,StrConst){
	char s1[]="";
	alphabet a1(s1);
	ASSERT_EQ(0,a1.getSZ());
	char s2[]="abc";
	alphabet a2(s2);
	ASSERT_EQ(3,a2.getSZ());
	char s3[]="aaaaa";
	alphabet a3(s3);
	ASSERT_EQ(1,a3.getSZ());
	char s4[]=" ad";
	alphabet a4(s4);
	ASSERT_EQ(3,a4.getSZ());
	char s5[]="	12345670";
	alphabet a5(s5);
	ASSERT_EQ(9,a5.getSZ());
	char s6[]="ASDFG";
	alphabet a6(s6);
	ASSERT_EQ(5,a6.getSZ());
}
TEST(alphabetMethods,methods){
	char s[]="abcd";
	alphabet a(s);
	a.add('	');
	ASSERT_EQ(5,a.getSZ());
	a.add('3');
	ASSERT_EQ(6,a.getSZ());
	a.add(' ');
	ASSERT_EQ(7,a.getSZ());
	a.add('9');
	ASSERT_EQ(8,a.getSZ());
	char s1[]="alphabet";
	char s2[]="abdr";
	alphabet a2(s1);
	alphabet a3(s2);
	a2.total(a3);
	ASSERT_EQ(9,a2.getSZ());
	char s3[]="alphabet";
	char s4[]="alph";
	alphabet a4(s3);
	alphabet a5(s4);
	a4.total(a5);
	ASSERT_EQ(9,a2.getSZ());
}
TEST(alphabetConst,TestExc){
    ASSERT_ANY_THROW(alphabet a1(-10));
    ASSERT_ANY_THROW(alphabet a2(101));
    ASSERT_ANY_THROW(alphabet a3(256)); 
	char s[]="alphabetd";
    alphabet a4(s);
	char s2[]="alphabetd32";
	ASSERT_ANY_THROW(a4.add('a'));
	ASSERT_ANY_THROW(a4.add('d'));
	ASSERT_ANY_THROW(a4.cod(s2,1));
	ASSERT_ANY_THROW(a4.decod(s2,1));
}
int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}