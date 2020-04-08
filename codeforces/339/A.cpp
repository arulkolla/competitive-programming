#include <unordered_set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    std::string sum;
    cin >> sum;
    int s = sum.size()/2 + 1;
    char nums[s];
    for (int i = 0; i < s; i++) {
        nums[i] = sum[i*2];
    }
    std::sort(nums, nums+s);
    for (int i = 0; i < s-1; i++) {
        cout << nums[i] << '+';
    }
    cout << nums[s-1];
    return 0;
}
