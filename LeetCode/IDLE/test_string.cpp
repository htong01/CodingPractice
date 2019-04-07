#include "Solution1.h"
#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	// test constructor
	String s1("Hello");
	String s2("World");
	String s3;
	cout << "s1 is: "<< s1 << endl;
	cout << "s2 is: "<< s2 << endl;

	// test comparation
	cout << "s2==s1 yields: "<<(s2 == s1) << endl
		<<"s2!=s1 yields: "<<(s2 != s1) << endl
		<<"s2>s1 yields: "<<(s2 > s1) << endl;

	// test copy constructor 
	s3 = s1;
	cout << "test copy constructor, s3 is: " << s3 << endl;

	cout <<"take substring from s1(2): "<< s1(2) << endl;

	// test assignment operator
	String *s4 = new String(s1);
	cout << "test assignment operator, s4 is: "<< *s4 << endl;

	// test destructor
	delete s4;

	// test subscript operator to access rvalue
	cout << "rvalue of s1[0] is: " << s1[0] << endl;
	// test if out of range
	cout << "Error: " << s1[20] << endl;

	return 0;
}