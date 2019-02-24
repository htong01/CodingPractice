/*
Calculating each distance first
The rest part of this problem equals to finding the K smallest elements.
  - Sorting O(nlogn)
  - Max Heap O(k+(n-k)logk)
  Constract a heap with only K element, and if the next element is smaller than the current largest number in the heap(heap.top()), then replace the largest number.
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue< vector<int>,vector<vector<int>>, compare > pq;
        for(auto p:points){
            pq.push(p);
            if(pq.size()>K) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
private:
    struct compare{
        bool operator()(const vector<int>& p, const vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };
};
