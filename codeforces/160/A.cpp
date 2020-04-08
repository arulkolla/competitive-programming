#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, leftSum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        leftSum += a[i];
    }
    std::sort(a, a+n, greater<>());
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        leftSum -= a[i];
        if (sum > leftSum) {cout << i+1; return 0;}
    }
    cout << -1;
    return 0;
}
