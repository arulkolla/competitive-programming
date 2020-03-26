#include <iostream>
using namespace std;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int result = 0;
    if (((a < b) && (a%2 != b%2)) || ((a > b) && (a%2 == b%2))) {result = 1;}
    else if (((a > b) && (a%2 != b%2)) || ((a < b) && (a%2 == b%2))) {result = 2;}
    cout << result << "\n";
  }
}