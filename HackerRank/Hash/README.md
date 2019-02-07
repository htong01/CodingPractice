# Hash Tables: Ransom Note

最直接最笨方法：
  在note中的单词是否和magazine中任一单词重复，都不重复的话返回false（有几个test case没有通过，不知道为什么，而且懒得去想了）
```
void checkMagazine(vector<string> magazine, vector<string> note) {

    int n = note.size();
    for(int i=0;i<n;i++){
        int m = magazine.size();
        int cnt = 0;
        for(int j=0;j<m;j++){
            if(note[i] != magazine[j]) cnt++;
            else{
                magazine.erase(magazine.begin()+j);           // avoid duplicate words
            }
        }
        if(cnt == m) {printf("No");return;} 
    }
    
    printf("Yes");
}
```
-------------------------------------------------------------------------------------------------------
聪明的方法：HashMap

unordered_map is an associated container that stores elements formed by combination of key value and a mapped value.
[unordered_map instruction](https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/)
```
void checkMagazine(vector<string> magazine, vector<string> note) {

    unordered_map <string,int> words;
    for(auto &it : magazine) words[it]++;
    for(auto &it : note){
        if(words[it]> 0) words[it]--;
        else{printf("No"); return;}
    }

    printf("Yes");

}
```


# Two Strings

