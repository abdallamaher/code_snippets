#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node {
    int total_sum,
        best_sum,
        best_left_sum,
        best_right_sum;
    void Merge(node& A, node& B) {
        total_sum = A.total_sum + B.total_sum;
        best_left_sum = max(A.best_left_sum, A.total_sum + B.best_left_sum);
        best_right_sum = max(A.best_right_sum + B.total_sum, B.best_right_sum);
        best_sum = max(
            max(A.best_sum, B.best_sum),
            A.best_right_sum + B.best_left_sum
        );
    }
    void CreateLeaf(int val) {
        total_sum = best_left_sum = best_right_sum = best_sum = val;
    }
};
const int N = 2e5 + 5;
int A[N];
node T[N];

void build(int idx, int l, int r) {
    if (l == r) {
        T[idx].CreateLeaf(A[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    T[idx].Merge(T[2 * idx], T[2 * idx + 1]);
}

void get(node& result, int idx, int l, int r, int a, int b) {
    if (a == l && b == r) {
        result = T[idx];
        return;
    }

    int mid = (l + r) / 2;
    if (b <= mid) {
        get(result, 2 * idx, l, mid, a, b);
    }
    else if (mid < a) {
        get(result, 2 * idx + 1, mid + 1, r, a, b);
    }
    else {
        node left, right;
        get(left, 2 * idx, l, mid, a, mid);
        get(right, 2 * idx + 1, mid + 1, r, mid + 1, b);
        result.Merge(left, right);
    }
}


int main() {
    int n; cin >> n;
    for (int i = 0;i < n;i++)
        scanf("%d", &A[i]);

    build(1, 0, n - 1);

    int t; cin >> t;
    node Ans;
    while (t--) {
        int x, y;scanf("%d %d", &x, &y);
        get(Ans, 1, 0, n - 1, x - 1, y - 1);
        cout << Ans.best_sum << "\n";
    }
    return 0;
}