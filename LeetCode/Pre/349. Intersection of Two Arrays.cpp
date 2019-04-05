在输出的数字不能重复这里稍微卡了一下，后来发现只要在原本建的hashmap中把那个数字删掉就好了

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int > ans;
        unordered_set<int> m(nums1.begin(), nums1.end());
        for(int n:nums2){
            if(m.count(n)){
                ans.push_back(n);
                m.erase(n);
            }
        }
        return ans;
    }
};
-------------------------------------------------------------------------
不删的话只是比较应该会更快
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int > ans;
        unordered_map<int, int> mp;
        for(int n:nums1) mp[n]++;
        for(int n:nums2){
            if(mp[n]>0){
                ans.push_back(n);
                mp[n] = 0;
            }
        }
        return ans;
    }
};
