// Runtime: 46 ms, faster than 95.30% of C++
class Solution {
    int check(vector<int>& piles, int h, int k) {
        int hours =0;
        for(auto& it: piles) {
            hours += (it + k - 1) / k;
        }
        return hours <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1, en = 1e9;
        while(st < en) {
            // 0 0 0 1 1 1
            int mid = (st + en + 0) / 2;
            if(check(piles, h, mid))en = mid;
            else st = mid + 1;
        }
        return en;
    }
};
