#include <iostream>
using namespace std;

const int N = 100001;
int n, i, j, a[N];

int main() {
    cin >> n;
    for(i = 1; i <= n; i++) cin >> a[i];
    
    bool flag;
    //i表示范围[1, i]
    for(i = n; i > 1; i--) {
        flag = true;
        //j ∈ [1, i]
        for(j = 1; j < i; j++) {
            //将第j个和第j + 1个比较
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                flag = false;
            }
        }
        //没有交换就退出
        if(flag) break;
    }

    for(i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}