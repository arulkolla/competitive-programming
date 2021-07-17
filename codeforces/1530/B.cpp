#include <bits/stdc++.h>

using namespace std;

const int MAX = 200007;
const int MOD = 1000000007;

void solve() {
	int n, m;
	cin >> n >> m;
	if (n % 2 == 1 && m % 2 == 1) {
	    for (int i = 0; i < n; i++) {
    	    for (int j = 0; j < m; j++) {
    	        if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && (i % 2 == 0 && j % 2 == 0)) {
    	            cout << 1;
    	        }
    	        else {
    	            cout << 0;
    	        }
    	    }
    	    cout << endl;
    	}   
	}
	else if (n % 2 == 0 && m % 2 == 0) {
	    for (int i = 0; i < n; i++) {
    	    for (int j = 0; j < m; j++) {
    	        if (i == 0) {
    	            if (j % 2 == 1 && j != m - 1) {cout << 1;}
    	            else {cout << 0;}
    	        }
    	        else if (i == n - 1) {
    	            if (j % 2 == 0 && j != 0) {cout << 1;}
    	            else {cout << 0;}
    	        }
    	        else if (j == 0) {
    	            if (i % 2 == 0 && i != 0) {cout << 1;}
    	            else {cout << 0;}
    	        }
    	        else if (j == m - 1) {
    	            if (i % 2 == 1 && i != n - 1) {cout << 1;}
    	            else {cout << 0;}
    	        }
    	        else {
    	            cout << 0;
    	        }
    	    }
    	    cout << endl;
    	}
	}
	else if (n % 2 == 1 && m % 2 == 0) {
	    for (int i = 0; i < n; i++) {
    	    for (int j = 0; j < m; j++) {
    	        if (i == 0) {
    	            if (j % 2 == 1) {cout << 1;}
    	            else {cout << 0;}
    	        }
    	        else if (i == n - 1) {
    	            if (j % 2 == 0) {cout << 1;}
    	            else {cout << 0;}
    	        }
    	        else if (j == 0) {
    	            if (i % 2 == 0 && i != 0) {cout << 1;}
    	            else {cout << 0;}
    	        }
    	        else if (j == m - 1) {
    	            if (i % 2 == 0 && i != n - 1) {cout << 1;}
    	            else {cout << 0;}
    	        }
    	        else {
    	            cout << 0;
    	        }
    	    }
    	    cout << endl;
    	}
	}
	else if (n % 2 == 0 && m % 2 == 1) {
	    for (int i = 0; i < n; i++) {
    	    for (int j = 0; j < m; j++) {
    	        if (j == 0) {
    	            if (i % 2 == 1) {cout << 1;}
    	            else {cout << 0;}
    	        }
    	        else if (j == m - 1) {
    	            if (i % 2 == 0) {cout << 1;}
    	            else {cout << 0;}
    	        }
    	        else if (i == 0) {
    	            if (j % 2 == 0 && j != 0) {cout << 1;}
    	            else {cout << 0;}
    	        }
    	        else if (i == n - 1) {
    	            if (j % 2 == 0 && j != m - 1) {cout << 1;}
    	            else {cout << 0;}
    	        }
    	        else {
    	            cout << 0;
    	        }
    	    }
    	    cout << endl;
    	}
	}
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
    // solve();
}