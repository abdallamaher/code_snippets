class Solution {
public:
    int lower_bound(vector<int>& arr, int st, int en, int x) {
        while (st < en) {
            int mid = (st + en) / 2;
            if (arr[mid] >= x)en = mid;
            else st = mid + 1;
        }
        return en;
    }

    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int Break = n;
        int st = 0, en = n - 1, mid;
        while (st < en) {
            mid = (st + en) / 2;
            if (arr[mid] < arr[0]) Break = mid, en = mid;
            else st = mid + 1;
        }

        int pos = lower_bound(arr, 0, Break - 1, target);
        if (arr[pos] == target)return pos;
        pos = lower_bound(arr, Break, n - 1, target);
        if (arr[pos] == target)return pos;
        return -1;

    }
};