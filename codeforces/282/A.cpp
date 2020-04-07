#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n, x = 0;
    char c1, c2, c3;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c1 >> c2 >> c3;
        if (c2 == '+') {x += 1;}
        else if (c2 == '-') {x -= 1;}
    }
    cout << x;
}
