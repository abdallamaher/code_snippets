class Solution {
public:
    // Runtime: 0 ms, faster than 100.00% of C++
    int mySqrt(int x) {
        long long l = 1, r = x;
        while(l < r) {
            long long mid = (l + r + 1) / 2;
            // 1 1 1 1 0 0 searching for last one
            if(mid * mid <= x) l = mid;    // if one , one on left
            else r = mid - 1;
        }
        return r;
    }
};
