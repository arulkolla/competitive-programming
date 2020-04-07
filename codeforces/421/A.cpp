#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    int q;
    cin >> n >> a >> b;
    int whole[n];
    for (int _ = 0; _ < n; _++) {whole[_] = 2;}
    for (int _ = 0; _ < a; _++) {
        cin >> q;
        whole[q-1] = 1;
    }
    for (int _ = 0; _ < b; _++){cin >> q;}
    for (int _ = 0; _ < n; _++) {
        cout << whole[_] << " ";
    }
}
