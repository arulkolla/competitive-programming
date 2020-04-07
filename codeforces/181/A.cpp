#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n, m, x[3], y[3];
    char c;
    int i = 0;
    cin >> n >> m;
    for (int _ = 1; _ <= n; _++) {
        for (int __ = 1; __ <= m; __++) {
            cin >> c;
            if (c == '*') { x[i] = _; y[i] = __; i++;}
        }
    }
    int xh, yh;
//    for (int j = 0; j < 3; j++) {
//        cout << x[j] << " " << y[j] << endl;
//    }
    if (x[0] == x[1]) {xh = x[2];}
    else if (x[1] == x[2]) {xh = x[0];}
    else {xh = x[1];}

    if (y[0] == y[1]) {yh = y[2];}
    else if (y[1] == y[2]) {yh = y[0];}
    else {yh = y[1];}

    cout << xh << " " << yh;
}
