// Runtime: 1189 ms
class NumArray {
    
    vector<int> tree;
    int n;
    
    void _build(int tree_node,int left,int right, vector<int>& nums) {
        if(left == right) {
            tree[tree_node] = nums[left];
            return;
        }
        
        int mid = (left + right) / 2;
        _build(tree_node * 2,     left,    mid, nums);
        _build(tree_node * 2 + 1, mid + 1, right, nums);
        
        tree[tree_node] = tree[tree_node * 2] + tree[tree_node * 2 + 1];
    }
    
    void _update(int tree_node,int left,int right, int array_index, int value) {
        if(left == array_index && right == array_index) {
            tree[tree_node] = value;
            return;
        }
        
        int mid = (left + right) / 2;
        if(array_index <= mid)
            _update(tree_node * 2,     left,   mid, array_index, value);
        else 
            _update(tree_node * 2 + 1, mid + 1, right, array_index, value);
        
        tree[tree_node] = tree[tree_node * 2] + tree[tree_node * 2 + 1];
    }
    
    int _get(int tree_node, int left, int right, int a, int b) {
        // node(l, r) complete in query(a, b)
        if(min(a, b) <= min(left, right) && max(left, right) <= max(a, b)) {
            return tree[tree_node];
        }
        // node complete out query
        if(max(left, right) < min(a, b) || max(a, b) < min(left, right)) {
            return 0;
        }
        // partial
        int mid = (left + right) / 2;
        return _get(tree_node * 2, left, mid, a, b) + _get(tree_node * 2 + 1, mid + 1, right, a, b);
    }
public:
    NumArray(vector<int>& nums) {
        if(nums.size()) {
            n = nums.size();
            tree.resize(5 * n + 5, 0);
            _build(1, 0, n - 1, nums); // index, left, right
        }
    }
    
    void update(int index, int val) {
        _update(1, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
        return _get(1, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
