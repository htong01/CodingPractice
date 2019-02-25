// https://www.geeksforgeeks.org/count-number-of-substrings-with-exactly-k-distinct-characters/

// The problem can be solved in O(n*n). Idea is to maintain a hash table while generating substring and checking the number of unique characters using that hash table.
// The implementation below assume that the input string contains only characters from ‘a’ to ‘z’.

// #include<bits/stdc++.h> 
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int countkDist(string str, int k) {
	int n = str.length();
	int res = 0;
	int cnt[26];
	for(int i=0;i<n;i++){
		int dist_cnt = 0;

		memset(cnt, 0, sizeof(cnt)); // initialize each time

		for(int j=i;j<n;j++){
			if(cnt[str[j]-'a']==0) dist_cnt++;
			cnt[str[j]-'a']++;
			if(dist_cnt == k) res++;
			if(dist_cnt>k) break;
		}
	}
	return res;
}

int main(){
	string str = "abcbaa"; 
    int k = 3; 
    cout << "Total substrings with exactly "
         << k <<" distinct characters :"
         << countkDist(str, k) << endl; 
    return 0; 
}
