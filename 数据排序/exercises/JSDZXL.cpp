#include <bits/stdc++.h>
using namespace std;

int a[1001], n;
vector<int> b;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] % 2 != 0) b.push_back(a[i]);
    }
    sort(b.begin(), b.end());

    for(int i = 0; i < b.size(); i++) if(i != b.size() - 1) cout << b[i] << ','; else cout << b[i];
    return 0;
}