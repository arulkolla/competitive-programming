#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

int merge(int a[], int temp[], int left, int mid, int right) {
   int i, j, k;
   int count = 0;
   i = left;
   j = mid;
   k = left;
   while ((i <= mid - 1) && (j <= right)) {
      if (a[i] <= a[j]){
      temp[k++] = a[i++];
      } else {
         temp[k++] = a[j++];
         count += (mid - i);
      }
   }
   while (i <= mid - 1)
      temp[k++] = a[i++];
   while (j <= right)
      temp[k++] = a[j++];
   for (i=left; i <= right; i++)
      a[i] = temp[i];
   return count;
}
int mergeSort(int a[], int temp[], int left, int right){
   int mid, count = 0;
   if (right > left) {
      mid = (right + left)/2;
      count = mergeSort(a, temp, left, mid);
      count += mergeSort(a, temp, mid+1, right);
      count += merge(a, temp, left, mid+1, right);
   }
   return count;
}
int aInversion(int a[], int n) {
   int temp[n];
   return mergeSort(a, temp, 0, n - 1);
}

void solve() {
	int n, m;
	cin >> n >> m;
	pair<int, int> a[m + 7];
	for (int i = 0; i < m; i++) {
		cin >> a[i].first;
		a[i].second = m - i;
	}
	sort(a, a + m);
	int res[m + 7];
	for (int i = 0; i < m; i++) {
		res[m - a[i].second] = i + 1;
	}
	cout << (m * (m - 1) / 2) - aInversion(res, m) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}