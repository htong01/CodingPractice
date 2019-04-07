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