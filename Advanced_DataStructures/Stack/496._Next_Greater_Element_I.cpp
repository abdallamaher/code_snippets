class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& q, vector<int>& ar) {
        map<int, int> mp;
        stack<int> st;
        
        // map
        int n = ar.size();
        for(int i=0; i<n; i++) {
            while(st.size() && ar[i] > st.top()) {
                int t = st.top(); st.pop();
                mp[t] = ar[i];
            }
            st.push(ar[i]);
        }
        
        // query
        n = q.size();
        vector<int> ans(n);
        for(int i=0; i<q.size(); i++) {
            ans[i] = mp[q[i]] ? mp[q[i]] : -1;
        }
        
        return ans;
    }
};
