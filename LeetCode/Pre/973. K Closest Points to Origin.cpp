上一次用的是priority queue做的，min heap里只放k个东西
可以用partial sort，代码更简洁

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        partial_sort(points.begin(), points.begin()+K, points.end(), [](vector<int>& a, vector<int>& b){
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        });
        return vector<vector<int> > (points.begin(), points.begin()+K);
    }
};
