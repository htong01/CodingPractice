/*
67. Add Binary
Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.

Example :

Input: a = "11", b = "1"
Output: "100"
Input: a = "1010", b = "1011"
Output: "10101"

Follow-up: if base is 2~16
*/
#include <iostream>
#include <string>
using namespace std;


string addHex(string a, string b)
{
	string res = "";
	int carry = 0;
	int i = a.length() - 1;
	int j = b.length() - 1;
	while(i>=0 || j>=0 || carry==1){
		if(i>=0) carry += a[i]>='A' ? a[i--]-'A'+10 : a[i--]-'0';
		if(j>=0) carry += b[j]>='A' ? b[j--]-'A'+10 : b[j--]-'0';

		if(carry%16 > 9) res = char(carry%16 -10 + 'A') + res;
		else res = char(carry%16 + '0') + res;
		carry /= 16;
	}
	return res;
}
string addBinary(string a, string b)
{
	string res = "";
	int carry = 0;
	int i = a.length() - 1;
	int j = b.length() - 1;
	while(i>=0 || j>=0 || carry==1){
		carry += (i>=0 ? a[i--]-'0':0);
		carry += (j>=0 ? b[j--]-'0':0);
		res = char(carry%2 + '0') + res;
		carry /= 2;
	}
	return res;
}

int main()
{
	string a = "11";
	string b = "1";
	cout << "Result: " << addBinary(a,b) << endl;
	string c = "1A";
	string d = "AA";
	cout << "Result: " << addHex(c,d) << endl;
	return 0;
}