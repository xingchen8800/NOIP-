#include <iostream>
using namespace std;

const int N = 100001;
int a[N], b[N], n;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    for(int i = 1; i <= n; i++) b[a[i]]++;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < b[i]; j++) cout << i << " ";
    }

    return 0;
}