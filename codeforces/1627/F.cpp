#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eps 1e-8
#define MOD 1000000007

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

// change if necessary
#define MAXN 1000000

using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    vector<vector<int>> h_edge(k + 1, vector<int>(k));
    vector<vector<int>> v_edge(k, vector<int>(k + 1));
    vector<vector<int>> dist(k + 1, vector<int>(k + 1, INF));

    for (int i = 0; i < n; i++) {
        int r1, c1; cin >> r1 >> c1;
        int r2, c2; cin >> r2 >> c2;
        r1--; c1--; r2--; c2--;

        if (r1 == r2) {
            if (c1 > c2) swap(c1, c2);
            v_edge[r1][c2]++;
            v_edge[k - r1 - 1][k - c2]++;
        } else {
            if (r1 > r2) swap(r1, r2);
            h_edge[r2][c1]++;
            h_edge[k - r2][k - c1 - 1]++;
        }
    }

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
    pq.push({0, 0, 0});
    dist[0][0] = 0;

    while (!pq.empty()) {
        auto [d, r, c] = pq.top();
        pq.pop();

        if (d > dist[r][c]) continue;

        if (r > 0 && d + v_edge[r - 1][c] < dist[r - 1][c]) {
            int nd = dist[r - 1][c] = d + v_edge[r - 1][c];
            pq.push({nd, r - 1, c});
        }

        if (r < k && d + v_edge[r][c] < dist[r + 1][c]) {
            int nd = dist[r + 1][c] = d + v_edge[r][c];
            pq.push({nd, r + 1, c});
        }

        if (c > 0 && d + h_edge[r][c - 1] < dist[r][c - 1]) {
            int nd = dist[r][c - 1] = d + h_edge[r][c - 1];
            pq.push({nd, r, c - 1});
        }

        if (c < k && d + h_edge[r][c] < dist[r][c + 1]) {
            int nd = dist[r][c + 1] = d + h_edge[r][c];
            pq.push({nd, r, c + 1});
        }
    }

    cout << n - dist[k / 2][k / 2] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
