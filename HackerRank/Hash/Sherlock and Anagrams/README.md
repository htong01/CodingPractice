Two steps basically:
1. Treverse all substrings in the string.
2. Check of any two substrings of same size are anagrams.


A very clever sloution: 
- Find sunstrings by using substr(pos,len), all substrings with the same length in one loop
- Sort substrings. 

```sort(substrings[k].begin(),substrings[k].end());``` Like ```adbc``` to ```abcd```(能想到用sorting真的太聪明了！！！）

- Check if there are totally same substrings

```
int sherlockAndAnagrams(string s) {
    int cnt = 0;
    int diff = 1;
    for(int i=0;i<s.size()-1;i++){
        vector<string> substrings(0);
        for(int j=0;j<s.size()-diff+1;j++)
            substrings.push_back(s.substr(j,diff));
        for(int k=0;k<substrings.size();k++)
            sort(substrings[k].begin(),substrings[k].end());
        for(int x=0;x<substrings.size();x++){
            for(int y=x+1;y<substrings.size();y++){
                if(substrings[x] == substrings[y]) cnt++;
            }
        }
        diff++;
    }
    return cnt;
}
```
