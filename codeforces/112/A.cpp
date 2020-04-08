#include <iostream>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
    std::string p, q;
    cin >> p >> q;
    int i = 0;
    for (i = 0; i < p.size(); i++) {
        if ((int)tolower(p[i]) > (int)tolower(q[i])) {cout << 1; return 0;}
        else if ((int)tolower(p[i]) < (int)tolower(q[i])) {cout << -1; return 0;}
    }
    cout << 0;
    return 0;
}
