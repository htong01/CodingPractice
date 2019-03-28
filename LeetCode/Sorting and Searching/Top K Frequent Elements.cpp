// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

// Priotrity queue (top k) + hash map (cooresponding key and value)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        // for(int num:nums) map[num]++;
        
        vector<int> res;
        priority_queue<pair<int, int> > pq;
        for(auto it=map.begin();it!=map.end();it++){
            pq.push(make_pair(it->second, it->first)); // first is freq, second is num
            if(pq.size() > map.size()-k){
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
        
    }
};
