#include <bits/stdc++.h>

#define pb push_back
using namespace std;
vector<vector<int>> subords;
vector<int> ans;

int calc(int node, int parent) {
    if (subords[node].size() == 1 && node != 0) return 0;
    int retVal = 0;
    for (int sib : subords[node]) {
        if (sib != parent) {
            ans[sib] = calc(sib, node);
            retVal += ans[sib] + 1;
        }
    }
    return retVal;
}

int main() {
    cin.tie(0), cout.sync_with_stdio(0);
    int N;
    cin >> N;
    subords.resize(N);
    ans.resize(N);
    for (int i = 1; i < N; i++) {
        int a; cin >> a; a --;
        subords[a].pb(i); subords[i].pb(a);
    }
    ans[0] = calc(0, -1);
    for (int val: ans) cout << val << " ";
}
