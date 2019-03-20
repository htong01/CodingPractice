- For initialize a vector<vectot<int> > (在俩"> >"中间要加空格，否则会被认为是cout输出or输入)
  用g++ -std=c++11来运行
  
- c++里sort和reverse分开来写，不知道为什么写成 sort(contests.begin(),contests.end(),greater<int>());会报错
  如果python：contests.sort(reverse=True)


#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int luckBalance(int k, vector<vector<int> > contests) {
    sort(contests.begin(),contests.end());
    reverse(contests.begin(),contests.end());
    int luck = 0;
    int importance = 0;
    for(int i=0;i<contests.size();i++){
        if(contests[i][1]==0) luck += contests[i][0];
        else if(importance < k){
            luck += contests[i][0];
            importance ++;
        }
        else luck -= contests[i][0];
    }
    return luck;
}

int main(){
    int k = 3;
    vector<vector<int> > contests{ { 5, 1 }, 
                                 { 2, 1 }, 
                                 { 1, 1 }, 
                                 { 8, 1 },
                                 { 10, 0 },
                                 { 5, 0 } }; 
    int res = luckBalance(k, contests);
    cout << res << endl;
    return 0;
}
