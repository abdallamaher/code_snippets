// Runtime: 7 ms, faster than 59.07% of C++
class Solution {
private: 
    int lower_bound(int l, int r,int target, vector<int>& nums) {
        while(l < r) {
            int mid = (l + r + 0) / 2;
            // searching for first one. 0 0 0 1 1
            if(nums[mid] >= target) r = mid; // if one and one in right
            else l = mid + 1; // if zero
        }
        return nums[r] == target ? r : -1;
    }
    int peak(vector<int>& nums) {
        int n = nums.size() - 1;
        int l = 0, r = n;
        while(l < r) {
            int mid = (l + r + 1) / 2;
            // searching for last one   1 1 1 0 0 
            if(nums[mid] >= nums[0]) l = mid;     // if one and one in left
            else r = mid - 1;  // if zero
        }
        return r;
    }
public:
    int search(vector<int>& nums, int target) {
        int p = peak(nums);

        int n = nums.size() - 1;
        
        // lower_bound(first_pointer, last_pointer + 1)
        int res = max(
                      lower_bound(0, p, target, nums), 
                      lower_bound(p+1, n, target, nums)
                      );
        return res;
    }
};

/* 
input
-----
unique
sorted
N len
ll

output
-----
sure exist
*/
