/*
273. Integer to English Words
Input: 123
Output: "One Hundred Twenty Three"
Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string toWords(int n){
	// vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	// vector<string> tens = {"", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

	if(n == 0) return "Zero";
	if(n>=1000000000)
		return toWords(n/1000000000) + "Billion" + toWords(n%1000000000);
	if(n>=1000000)
		return toWords(n/1000000) + "Million" + toWords(n%1000000);
	if(n>=1000)
		return toWords(n/1000) + "Thousand and" + toWords(n%1000);
	if(n>=100)
		return toWords(n/100) + "Hundred" + toWords(n%100);
	if(n>=20)
		return " " + tens(n/10) + toWords(n%10);
	if(n>=1)
		return " " + ones(n);
	else
		return "";
}

int main()
{
	int num = 123;
	cout << "Number to Words:" << toWords(num).substr(1) << endl;
	int num2 = 1234567;
	cout << "Number to Words:" << toWords(num2).substr(1) << endl;
	return 0;
}