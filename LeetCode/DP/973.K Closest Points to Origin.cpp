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
--------------------------------本地运行时环境设置--------------------------------
  
#include <iostream>
#include <string>
#include <vector>
#include <utility>  // for pair
using namespace std;
vector<pair<int,int> > Kclosest(int** points, int k){
    cout << "hi";
    vector<pair<int,int> > result(1,pair<int,int>(points[0][0],points[0][1]));
    cout<<result.size();
    return result;
}
int main()
{
  int** pts;
  pts = new int*[2];
  for(int i = 0; i<2; i++)
    pts[i] = new int[2];              // malloc memory for the matrix
  pts[0][0] = 1;
  pts[0][1] = 2;
  pts[1][0] = 3;
  pts[1][1] = 4;

  // std::cout << "hi";
  vector<pair<int,int> > result = Kclosest(pts, 1);
  
  cout << result[0].first;
  return 0;
}
