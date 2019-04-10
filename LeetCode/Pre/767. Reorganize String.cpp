和621.task schedule有点像的题
Time: O(nlogA) = O(n) n为string长，A为字母表长度（26
Space: O(A) = O(1)

class Solution {
public:
    string reorganizeString(string S) {
        string s = ""; // answer
        map<char, int> mp;
        for(int i=0;i<S.length();++i)
            mp[S[i]]++;
        priority_queue<pair<int, char> > pq;
        for(auto p:mp){
            if(p.second > (S.length()+1)/2)
                return "";
            pq.emplace(p.second, p.first);
        }
        pair<int, char> prev(0, ' ');
        while(!pq.empty()){
            pair<int, char> curr = pq.top();
            pq.pop();
            s = curr.second + s;
            curr.first -= 1;
            if(prev.first > 0)
                pq.emplace(prev);
            prev = curr;
        }
        return s;
    }
};
