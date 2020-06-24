#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAX = 100007;
const int MOD = 1000000007;

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    string arr[MAX];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    char ans[MAX];
    for (int i = 1; i <= n; i++) {
        if (arr[i] == "AB") {
            if (a == 0 && b == 0) {
                cout << "No";
                return;
            }
            if (a == 1 && b == 1 && c == 0 && i != n && arr[i + 1] == "AC") {
                ans[i] = 'A';
                a++;
                b--;
                continue;
            }
            if (a == 1 && b == 1 && c == 0 && i != n && arr[i + 1] == "BC") {
                ans[i] = 'B';
                b++;
                a--;
                continue;
            }
            if (a > b) {
                ans[i] = 'B';
                b++;
                a--;
            }
            else {
                ans[i] = 'A';
                a++;
                b--;
            }
        }
        if (arr[i] == "AC") {
            if (a == 0 && c == 0) {
                cout << "No";
                return;
            }
            if (a == 1 && b == 0 && c == 1 && i != n && arr[i + 1] == "AB") {
                ans[i] = 'A';
                a++;
                c--;
                continue;
            }
            if (a == 1 && b == 0 && c == 1 && i != n && arr[i + 1] == "BC") {
                ans[i] = 'C';
                c++;
                a--;
                continue;
            }
            if (a > c) {
                ans[i] = 'C';
                c++;
                a--;
            }
            else {
                ans[i] = 'A';
                a++;
                c--;
            }
        }
        if (arr[i] == "BC") {
            if (b == 0 && c == 0) {
                cout << "No";
                return;
            }
            if (a == 0 && b == 1 && c == 1 && i != n && arr[i + 1] == "AB") {
                ans[i] = 'B';
                b++;
                c--;
                continue;
            }
            if (a == 0 && b == 1 && c == 1 && i != n && arr[i + 1] == "AC") {
                ans[i] = 'C';
                c++;
                b--;
                continue;
            }
            if (b > c) {
                ans[i] = 'C';
                c++;
                b--;
            }
            else {
                ans[i] = 'B';
                b++;
                c--;
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++) {cout << ans[i] << endl;}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve(); cout << endl;}
    solve();
}