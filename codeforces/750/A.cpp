#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int minLeft = 240 - b, solved = 1;
    while (minLeft >= 0) {
        minLeft -= solved*5;
        solved++;
    }
    cout << min(solved - 2, a);
    return 0;
}
