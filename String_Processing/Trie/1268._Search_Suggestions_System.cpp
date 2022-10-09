// Runtime: 113 ms, faster than 64.31% of C++
string bs;
vector<string> ans;

// create node that contain 26 pointer 
struct trie{
	trie *ch[26];
	int leaf;
    
	trie(){
		for(int i = 0 ; i < 26 ; i++)ch[i] = NULL;
		leaf = 0;
	}
	void add(string &s, int i){
		if(i == (int)s.length())leaf = 1;	// last
		else{
			if(ch[s[i] - 'a'] == NULL)		// check if 
				ch[s[i] - 'a'] = new trie;
			ch[s[i] - 'a']->add(s, i + 1);
		}
	}
	void search(string &s, int i){
        if(ans.size() == 3)return;
		if(i >= (int)s.length()){
            //if(ans.size() > 3)return;
			if(leaf == 1)ans.push_back(bs);

			for(int j = 0 ; j < 26 ; j++){
				if(ch[j] != NULL){
					bs.push_back('a' + j);
					ch[j]->search(s, i + 1);
					bs.pop_back();
				}
			}
		}
		else{
			if(ch[s[i] - 'a'] != NULL) {
                bs.push_back(s[i]);
                ch[s[i] - 'a']->search(s, i + 1);
            }
		}
	}
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(
        vector<string>& products, 
        string searchWord) {
        trie t;
        for(auto&it: products) t.add(it, 0);
        string s;
        vector<vector<string>> res;
        for(const auto&c: searchWord) {
            ans.clear();
            bs.clear();
            s += c;
            //cout << s << endl;
            t.search(s, 0);
            res.push_back(ans);
        }
        return res;
    }
};
