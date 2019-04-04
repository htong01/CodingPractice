好久之前做过一遍的题，一点印象都没有，大脑空空
Related topic: binary search（是提示了

写的时候想起来怎么做了，但犯了第一遍做时候一样的错误
mid =  start+(end-start)/2; ！！！！！！ but not ❌mid = (start+end)) / 2;❌！！！！！
when start and end are all about INT_MAX , then (start+end) of course will be overflow !


// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        int mid;
        while(l < r){
            mid = l + (r - l) / 2;
            if(isBadVersion(mid) == false) l = mid+1;
            else r = mid;
        }
        return l;
    }
};
