#include <bits/stdc++.h>
#ifdef DEBUG
#include "./../Algorithms/competitive_programming/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define ll long long

int n;
const int N = 2e5 + 10;

inline void solve() {
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i].first >> a[i].second;
        if(a[i].first > a[i].second) swap(a[i].first, a[i].second);
    }
    sort(a.begin(), a.end());

    set<int> st;
    for(auto &it: a) {
        auto it2 = st.lower_bound(it.first);
        if(it2 != st.end() && *it2 < it.second) {
            cout << "Yes\n";
            return;
        }
        st.insert(it.second);
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}

namespace lib {
    namespace Sorting {
        namespace bubble_sorting {
            vector<int> bubble_sorting(vector<int>& arr) {
                int len = arr.size();
                for (int mx = 0; mx < len; mx++) {
                    for (int i = 0; i < len - mx - 1; i++) {
                        if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
                    }
                }
                return arr;
            }
        }

    } // namespace sorting
    namespace Binary_Search {
        int lower_bound(vector<int>& nums, int target) {
            // find first element that >= than target
            int l = 0, r = nums.size();
            while (l < r) {
                // 0 0 0 1 1 1 
                int mid = (l + r + 0) / 2;
                if (nums[mid] >= target) r = mid;   // r is moving
                else l = mid + 1;
            }
            // if (l == nums.size()) return -1; // not found element >= than target
            // if(nums[l] != target) return -1; // not found element == target
            return r;
        }
    } // namespace binary_search
    namespace String {

        namespace Trie {
            // each node is 26 Pointer + isLeaf
            // struct TrieNode {
            //     vector<Trie*> nextNodes;
            //     bool isLeaf;
            //     TrieNode() {
            //         nextNodes.resize(26, NULL);
            //         isLeaf = false;
            //     }

            //     void insert(string word, int i = 0) {
            //         if (i == (int)word.size()) {
            //             isLeaf = true;
            //             return;
            //         }
            //         auto& nextNode = nextNodes[word[i] - 'a'];
            //         if (nextNode == NULL) nextNode = new Trie;
            //         return nextNode->insert(word, i + 1);
            //     }

            //     bool search(string word, int i = 0) {
            //         if (i == (int)word.size()) return isLeaf;
            //         auto& nextNode = nextNodes[word[i] - 'a'];
            //         if (nextNode == NULL) return false;
            //         return nextNode->search(word, i + 1);
            //     }

            //     bool startsWith(string prefix, int i = 0) {
            //         if (i == (int)prefix.size()) return true;
            //         auto& nextNode = nextNodes[prefix[i] - 'a'];
            //         if (nextNode == NULL) return false;
            //         return nextNode->startsWith(prefix, i + 1);

            //     }
            // };

            // int main() {
            //     TrieNode t;
            //     string s = "abcd";
            //     t.add(s);
            //     string f1 = "x";
            //     cout << t.search(f1) << ' ' << t.search(s);

            //     return 0;
            // }

            // ///////////////////// Trie /////////////////// 
            // vector<vector<int> > v;
            // vector<bool> e;
            // void insert(string& s) {
            //     int cur = 0;
            //     for (int i = 0; i < s.size(); ++i) {
            //         char c = s[i] - 'a';
            //         if (v[cur][c] == -1) {
            //             v[cur][c] = v.size();
            //             v.push_back(vector<int>(26, -1));
            //             e.push_back(false);
            //         }
            //         cur = v[cur][c];
            //     }
            //     e[cur] = true;
            // }
            // bool find(string& s) {
            //     int cur = 0;
            //     for (int i = 0; i < s.size(); ++i) {
            //         char c = s[i] - 'a';
            //         if (v[cur][c] == -1) {
            //             return false;
            //         }
            //         cur = v[cur][c];
            //     }
            //     return e[cur];
            // }
            // int main2() {
            //     int n;
            //     cin >> n;
            //     v.resize(1);
            //     v[0].resize(26, -1);
            //     e.push_back(false);
            //     for (int i = 0; i < n; ++i) {
            //         string s;
            //         cin >> s;
            //         insert(s);
            //     }
            //     int q;
            //     cin >> q;
            //     for (int i = 0; i < q; ++i) {
            //         string s;
            //         cin >> s;
            //         if (find(s))
            //             cout << "Yes" << endl;
            //         else
            //             cout << "No" << endl;
            //     }
            //     return 0;
            // }


        }


        namespace KMP {
            ////////////////////////////// KMP ////////////////
            string s, t;
            int f[100];
            void search() {
                int len = 0;
                for (int i = 0; i < s.size(); ++i) {
                    while (len > 0 && s[i] != t[len])	//decrease 
                        len = f[len - 1];
                    if (s[i] == t[len])				// increase
                        ++len;
                    if (len == t.size()) {			// equal
                        cout << i - len + 1 << endl;
                        len = f[len - 1];
                        // len = 0; No overlab
                        // return; one ocarrance
                    }
                }
            }

            void build() {
                int len = 0;
                f[0] = 0;
                for (int i = 1; i < t.size(); ++i) {
                    while (len > 0 && t[i] != t[len])	//decrease
                        len = f[len - 1];
                    if (t[i] == t[len])				// increase
                        ++len;
                    f[i] = len;						// equal
                }
            }

            int main2() {
                //   01234567890123456789012345
                s = "carcarcarcarcardcarcardcar";
                t = "carcard";
                build();
                search();
                return 0;
            }

        }
    }
    namespace Graph {
        // namespace Graph_Theory {
        //     //     DFS_mat
        //     //     DFS_List
        //     //     DFS_comp
        //     //     DFS_cycle
        //     //     DFS_topSort

        //     // ------------------------------

        //     const int N = 1e3 + 5, NN = 1e6 + 5;

        //     int adjMat[N][N], n, m, vis[NN], comp;
        //     vector<int> adjList[NN];

        //     void DFS_mat(int u) {
        //         vis[u] = 1;
        //         for (int i = 1; i <= n; i++)
        //             if (adj[u][i] && !vis[i])
        //                 DFS(i);
        //     }

        //     void DFS_List(int u) {
        //         vis[u] = 1;
        //         for (int v : adjList[u])
        //             if (!vis[v])
        //                 DFS_List(v);
        //     }

        //     void DFS_comp(int u) {
        //         vis[u] = comp;
        //         for (int v : adjList[u])
        //             if (!vis[v])
        //                 DFS_comp(v);
        //     }

        //     bool cycle;

        //     void DFS_cycle(int u, int p = -1) {
        //         vis[u] = 1;
        //         for (int v : adjList[u]) {
        //             if (vis[v] && v != p)
        //                 cycle = 1;
        //             if (!vis[v])
        //                 DFS_cycle(v, u);
        //         }
        //     }

        //     vector<int> top_sort;


        //     void DFS_topSort(int u) {
        //         vis[u] = 1;
        //         for (int v : adjList[u])
        //             if (!vis[v])
        //                 DFS_topSort(v);
        //         top_sort.push_back(u);
        //     }

        //     int main()
        //     {
        //         scanf("%d %d", &n, &m);
        //         for (int i = 0; i < m; i++) {
        //             int u, v;
        //             scanf("%d %d", &u, &v);
        //             adjMat[u][v] = adjMat[v][u] = 1;
        //             adjList[u].push_back(v);
        //             adjList[v].push_back(u);
        //         }
        //         for (int i = 1; i <= n; i++) {
        //             if (!vis[i]) {
        //                 DFS_topSort(i);
        //                 ++comp;
        //                 DFS_comp(i);
        //             }
        //         }
        //         return 0;

        //     }








        //     //      DFS_Floodfill
        //     //      BFS

        //     // ----------------------------

        //     const int N = 1e3 + 5;

        //     int n, m, dr[] = { 0, 0, 1, -1 }, dc[] = { -1, 1, 0, 0 }, vis[N][N], dis[N * N];
        //     char grid[N][N];

        //     bool ok(int r, int c) {
        //         return r < n && c < m && r >= 0 && c >= 0 && grid[r][c] != '#' && !vis[r][c];
        //     }

        //     void DFS_Floodfill(int r, int c) {
        //         vis[r][c] = 1;
        //         for (int i = 0; i < 4; i++) {
        //             int nr = r + dr[i], nc = c + dc[i];
        //             if (ok(nr, nc))
        //                 DFS_Floodfill(nr, nc);
        //         }
        //     }

        //     vector<int> adj[N * N];

        //     void BFS(int u) {
        //         dis[u] = 0;
        //         queue<int> q;
        //         q.push(u);
        //         while (q.size()) {
        //             u = q.front();
        //             q.pop();
        //             for (int v : adj[u]) {
        //                 if (dis[v] == -1) {
        //                     dis[v] = dis[u] + 1;
        //                     q.push(v);
        //                 }
        //             }
        //         }
        //     }

        //     int main2()
        //     {
        //         memset(dis, -1, sizeof dis);
        //         return 0;
        //     }
        // }

        // namespace Dijkstra {
        //     const int N = 1e5 + 5;

        //     long long T, n, m, st, en, dis[N];
        //     vector<pair<int, int>> adj[N];

        //     void init() {
        //         memset(dis, -1, sizeof dis);
        //         for (int i = 0; i <= N; i++)
        //             adj[i].clear();
        //     }

        //     void dij() {
        //         priority_queue<pair<long long, int>> q;
        //         q.push({ 0, st });
        //         dis[st] = 0;
        //         while (q.size()) {
        //             int u = q.top().second;
        //             int d = -q.top().first;
        //             q.pop();
        //             for (auto e : adj[u]) {
        //                 int v = e.second;
        //                 if (dis[v] == -1 || dis[v] > d + e.first) {
        //                     dis[v] = d + e.first;
        //                     q.push({ -dis[v], v });
        //                 }
        //             }
        //         }

        //     }

        //     int main()
        //     {
        //         scanf("%d", &T);
        //         while (T--) {
        //             init();
        //             scanf("%d %d %d %d", &n, &m, &st, &en);
        //             for (int i = 0; i < m; i++) {
        //                 int u, v, w;
        //                 scanf("%d %d %d", &u, &v, &w);
        //                 adj[u].push_back({ w, v });
        //                 adj[v].push_back({ w, u });
        //             }
        //             dij();
        //             if (~dis[en])
        //                 printf("%d\n", dis[en]);
        //             else
        //                 puts("NONE");
        //         }
        //         return 0;
        //     }


        //     // ------------------------------ -
        //     //     Grads_Dijkstra
        //     //     ------------------------------ -

        //     const int N = 1e5 + 5;

        //     int n, m, dis[N];
        //     vector<pair<int, int>> adj[N];

        //     void Dijkstra(int src) {
        //         dis[src] = 0;
        //         priority_queue<pair<int, int>> q;
        //         q.push({ 0, src });
        //         while (q.size()) {
        //             int u = q.top().second;
        //             int d = -q.top().first;
        //             q.pop();
        //             for (pair<int, int> i : adj[u]) {
        //                 int v = i.second;
        //                 int c = i.first;
        //                 if (dis[v] == -1 || dis[v] > d + c) {
        //                     dis[v] = d + c;
        //                     q.push({ -(d + c), v });
        //                 }
        //             }
        //         }
        //     }

        //     int main()
        //     {
        //         scanf("%d %d", &n, &m);
        //         memset(dis, -1, sizeof dis);
        //         for (int i = 0; i < m; i++) {
        //             int u, v, c;
        //             scanf("%d %d %d", &u, &v, &c);
        //             adj[u].push_back({ c, v });
        //             adj[v].push_back({ c, u });
        //         }
        //         Dijkstra(1);
        //         for (int i = 1; i <= n; i++)
        //             cout << i << ": " << dis[i] << "\n";
        //         return 0;
        //     }

        // }

//         namespace DSU_Disjoint_Sets {
//             // Simple Union_Find
// // Find_By_PathCompression
// // Union_By_Rank


// /////////////////////
// // Simple Union_Find

//             int find_parent(int n) {
//                 while (1) {
//                     if (p[n] == n)return n;
//                     n = p[n];
//                 }
//             }

//             void Union(int u, int v) {   // if init() p[i] = i;
//                 u = find_parent(u);
//                 v = find_parent(v);
//                 p[u] = v;
//             }
//             void Union(int u, int v) {   // if init() p[i] = -1;   have graph_component_size in negative
//                 u = find_parent(u);
//                 v = find_parent(v);
//                 p[u] += p[v];
//                 p[v] = u;
//             }


//             /////////////////////
//             // Find_By_PathCompression && Union_By_Rank

//             int find_parent(int n) {    // Find_By_PathCompression
//                 vector<int> v;
//                 while (p[n] > 0) {
//                     v.push_back(n);
//                     n = p[n];
//                 }
//                 for (int i = 0; i < v.size(); i++)p[v[i]] = n;
//                 return n;
//             }


//             void Union(int u, int v) {  // Union_By_Rank
//                 u = findparent(u);
//                 v = findparent(v);
//                 if (u == v) return;
//                 if (Rank[v] > Rank[u]) swap(u, v);   // u big 
//                 p[v] = u;   // u father
//                 Rank[u] += (Rank[u] == Rank[v]);
//             }






//             /////////////////////////////////
//             using namespace std;
//             const int N = 1e6 + 5;
//             int p[N], Rank[N];
//             int n, q, trees;

//             int init() {
//                 trees = n;  // number of components
//                 for (int i = 1; i <= n; i++) {
//                     p[i] = i;
//                     Rank[i] = 0;
//                 }
//             }

//             int findparent(int x) {
//                 if (p[x] == x) return x;
//                 return p[x] = findparent(p[x]);
//             }

//             void Link(int u, int v) {
//                 u = findparent(u);
//                 v = findparent(v);
//                 if (u == v) return;
//                 if (Rank[u] > Rank[v]) swap(u, v);   // u is the parent with small (rank/ height) 
//                 p[u] = v;   // add small height to big height
//                 Rank[u] += Rank[u] == Rank[v];  // 0 0  1 1
//                 --trees;
//             }

//             bool connected(int u, int v) {
//                 return findparent(u) == findparent(v);
//             }

//             int n, q;

//             int main()
//             {
//                 scanf("%d %d", &n, &q);
//                 init();
//                 while (q--) {
//                     int t, u, v;
//                     scanf("%d %d %d", &t, &u, &v);
//                     if (t == 1)
//                         Link(u, v);
//                     else
//                         puts(connected(u, v) ? "YES" : "NO");
//                 }
//                 return 0;
//             }
//             /*
//             6       nodes
//             10      queries 1 link, 2 question
//             1 1 2
//             1 2 1
//             2 3 4
//             N0
//             1 1 3
//             2 3 1
//             YES
//             1 4 5
//             1 5 1
//             2 1 4
//             YES
//             2 2 5
//             YES
//             */











//             /////////////////////////////////
//             // Union_Find_By_PathCompression

//             int find_parent(int n) {    // path_compression
//                 vector<int> v;
//                 while (p[n] > 0) {
//                     v.push_back(p[n]);
//                     n = p[n];
//                 }

//                 for (int i = 0; i < v.size(); i++)
//                     p[v[i]] = n;

//                 return n;
//             }


//             void Union(int u, int v) {   // if init() p[i] = -1;   have sub_graph size in negative
//                 u = find_parent(u);
//                 v = find_parent(v);
//                 p[u] += p[v];
//                 p[v] = u;
//             }









//             //////////////////////////////////
//             // Union_Find_By_Rank

//             int find_parent(int n) {
//                 while (1) {
//                     if (p[n] == n)return n;
//                     n = p[n];
//                 }
//             }

//             void Union(int u, int v) {  // for better time
//                 u = findparent(u);
//                 v = findparent(v);
//                 if (u == v) return;
//                 if (Rank[v] > Rank[u]) swap(u, v);   // u big 
//                 p[v] = u;   // u father
//                 Rank[u] += (Rank[u] == Rank[v]);
//             }
//         }

//         namespace MST_minimum_spanning_tree_kruskal {

//             const int N = 1e6 + 5;

//             int n, trees, p[N], Rank[N];

//             void init() {
//                 trees = n;
//                 for (int i = 0; i < n; i++) {
//                     p[i] = i;
//                     Rank[i] = 0;
//                 }
//             }

//             int getRoot(int u) {
//                 if (u == p[u]) return u;
//                 return p[u] = getRoot(p[u]);
//             }

//             bool Link(int u, int v) {
//                 u = getRoot(u);
//                 v = getRoot(v);
//                 if (u == v)
//                     return 0;
//                 if (Rank[u] > Rank[v]) swap(u, v);
//                 p[u] = v;
//                 Rank[v] += Rank[u] == Rank[v];
//                 --trees;
//                 return 1;
//             }

//             bool sameSet(int u, int v) {
//                 return getRoot(u) == getRoot(v);
//             }

//             int m, u[N], v[N], c[N], eid[N], T;

//             bool cmp(int i, int j) {
//                 return c[i] < c[j];
//             }

//             int main()
//             {
//                 scanf("%d", &T);
//                 while (T--) {
//                     scanf("%d %d", &n, &m);
//                     init();
//                     for (int i = 0; i < m; i++) {
//                         scanf("%d %d %d", u + i, v + i, c + i);
//                         eid[i] = i;
//                     }
//                     int ans = accumulate(c, c + m, 0);
//                     sort(eid, eid + m, cmp);
//                     for (int a = 0; a < m && trees > 1; a++) {
//                         int i = eid[a];
//                         if (Link(u[i], v[i]))
//                             ans -= c[i];
//                     }
//                     printf("%d\n", ans);
//                 }
//                 return 0;
//             }

//         }

    }
    namespace Tree {
        namespace segment_tree
        {
            struct segment_tree
            {
                int n;
                vector<int> ar, seg;

                segment_tree(vector<int>& v) {
                    n = v.size();
                    ar = v;
                    seg.resize(4 * n);
                }

                //node{idx, l, r}
                void build(int idx, int l, int r) {
                    //base case
                    if (l == r) {
                        seg[idx] = ar[l];
                        return;
                    }

                    int mid = (l + r) / 2;
                    build(idx * 2, l, mid);              // branching left
                    build(idx * 2 + 1, mid + 1, r);     // branching right

                    // backtrack
                    seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
                }

                // node{idx, l, r}     update_query{key_idx, val}  
                void update(int idx, int l, int r, int key, int val) {
                    // base case
                    if (l == r) {
                        seg[idx] = ar[key] = val;
                        return;
                    }
                    // l mid r - branching
                    int mid = (l + r) / 2;
                    if (key <= mid)                         // you could remove this condition but time will be O(N)
                        update(idx * 2, l, mid, key, val);
                    else
                        update(idx * 2 + 1, mid + 1, r, key, val);
                    // backtrack
                    seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
                }

                // node{idx, l, r}     get_query{a, b}
                int get(int idx, int l, int r, int a, int b) {
                    // node(l, r) complete in query(a, b)
                    if (a <= l && r <= b)   //al rb     //mn<=mn || mx<=mx
                        return seg[idx];
                    // node(l, r) complete out query(a, b)
                    if (r < a || l > b)     //mx<mn || mn>mx
                        return 0;
                    // partial          // l mid r
                    int mid = (l + r) / 2;
                    return get(idx * 2, l, mid, a, b)
                        + get(idx * 2 + 1, mid + 1, r, a, b);
                }


            };

            int main() {
                int n; cin >> n;
                vector<int> ar(n);
                for (int i = 0; i < n; ++i)
                    cin >> ar[i];
                segment_tree obj = segment_tree(ar);
                //build
                obj.build(1, 0, n - 1);

                int q; cin >> q;
                while (q--) {
                    int t, a, b; cin >> t >> a >> b;
                    if (t == 0) {
                        --a, --b;
                        // get
                        printf("%d\n", obj.get(1, 0, n - 1, a, b));  // node{idx, l, r}   query{a, b}
                    }
                    else {
                        --a;
                        // update
                        obj.update(1, 0, n - 1, a, b);  // node{idx, l, r}   query{idx, val}
                    }
                }
                return 0;
            }

        } // namespace segment_tree

    }

    namespace Math {
        namespace Algebra {
            namespace Interval_Intersection {

                #define pl pair<ll, ll>
                #define f first
                #define s second

                pl get_intersect(pl A, pl B) {
                    if (A.s < B.f || B.s < A.f)return { -1, -1 };
                    return { max(A.f, B.f), min(A.s, B.s) };
                }

                pl p1 = {2, 3}, p2  = { 1, 5 };

            }

            namespace Quadratic_Equation {

            }
        }
        namespace Number_Theory {
            namespace Primes {

            }
        }

    }
    namespace Debug {
        void __print(int x) { cerr << x; }
        void __print(long x) { cerr << x; }
        void __print(long long x) { cerr << x; }
        void __print(unsigned x) { cerr << x; }
        void __print(unsigned long x) { cerr << x; }
        void __print(unsigned long long x) { cerr << x; }
        void __print(float x) { cerr << x; }
        void __print(double x) { cerr << x; }
        void __print(long double x) { cerr << x; }
        void __print(char x) { cerr << '\'' << x << '\''; }
        void __print(const char* x) { cerr << '\"' << x << '\"'; }
        void __print(const string& x) { cerr << '\"' << x << '\"'; }
        void __print(bool x) { cerr << (x ? "true" : "false"); }

        template<typename T, typename V>
        void __print(const pair<T, V>& x) { cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}'; }
        template<typename T>
        void __print(const T& x) { int f = 0; cerr << '{'; for (auto& i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}"; }
        void _print() { cerr << "]\n"; }
        template <typename T, typename... V>
        void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }
        #ifndef ONLINE_JUDGE
        #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
        #else
        #define debug(x...)
        #endif
    } // namespace Debug

}
