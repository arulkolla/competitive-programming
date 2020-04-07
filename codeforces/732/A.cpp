#include <iostream>

using namespace std;

int main() {
    int k, r;
    cin >> k >> r;
    int n = 1, sh = k;
    while ((sh % 10 != 0) && (sh % 10 != r)) {
        n += 1;
        sh += k;
    }
    cout << n;
    return 0;
}
