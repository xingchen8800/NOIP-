#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    string ID;
    float score;
} a[100001];
int n, k;

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i].ID >> a[i].score;
    
    sort(a, a + n, [&](Node& a, Node& b) {
        return a.score < b.score;
    });

    cout << a[k].ID << " ";
    printf("%g", a[k].score);
    return 0;
}