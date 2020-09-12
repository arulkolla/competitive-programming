
// Problem : C. Link Cut Centroids
// Contest : Codeforces - Codeforces Round #670 (Div. 2)
// URL : https://codeforces.com/contest/1406/problem/C
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX = 100007;
const int MOD = 1000000007;

vector<int> Centroid(const vector<vector<int>> &g) {
    int gsize = g.size();
    vector<int> centroid;
    vector<int> sz(gsize);
    function<void (int, int)> dfs = [&](int u, int prev) {
        sz[u] = 1;
        bool is_centroid = true;
        for (auto v : g[u]) {
            if (v != prev) {
                dfs(v, u);
                sz[u] += sz[v];
                if (sz[v] > gsize / 2) {
                    is_centroid = false;
                }
            }
        }
        if (gsize - sz[u] > gsize / 2) {
            is_centroid = false;
        }
        if (is_centroid) {
            centroid.push_back(u);
        }
    };
    dfs(0, -1);
    return centroid;
}

void solve() {
    int n;
	cin >> n;
    vector<vector<int>> graph(n);
	int u, v;
	pair<int, int> og;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		if (i == 0) {
		    og.first = u; og.second = v;
		}
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> cent = Centroid(graph);
	if (cent.size() == 1) {
	    cout << og.first << " " << og.second << endl;
        cout << og.first << " " << og.second << endl;
	}
	else {
	    if (graph[cent[0]][0] != cent[1]) {
            cout << cent[0] + 1 << " " << graph[cent[0]][0] + 1 << endl;
            cout << cent[1] + 1 << " " << graph[cent[0]][0] + 1 << endl;
	    }
	    else {
            cout << cent[0] + 1 << " " << graph[cent[0]][1] + 1 << endl;
            cout << cent[1] + 1 << " " << graph[cent[0]][1] + 1 << endl;
	    }
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.in", "r", stdin); freopen("out.out", "w", stdout);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    //solve();
}