class Solution {
    int find_row(vector<vector<int>>& matrix, int target) {
        int st = 0, en = matrix.size() - 1; // sure there an anwser
        while(st < en) {
            int mid = (st + en + 1) /2;
            // 1 1 1 0 0
            if(target >= matrix[mid].front())st = mid;
            else en = mid - 1;
        }
        return en;
    }
    bool lower_bound(vector<int>& rw, int target) {
        // 0 0 0 1 1 1
        int st = 0, en = rw.size() - 0;
        while(st < en) {
            int mid = (st + en + 0) / 2;
            if(rw[mid] == target) return true;
            if(rw[mid] > target) en = mid;
            else st = mid + 1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = find_row(matrix, target);
        //cout << r << endl;
        return lower_bound(matrix[r], target);
    }
};
