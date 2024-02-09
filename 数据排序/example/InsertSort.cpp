#include <iostream>
using namespace std;

const int N = 10001;

int main() {
    int n, i, j, k;
    int a[N];
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(i = 1; i <= n; i++) {
        //[1, i] 有序区
        for(j = i - 1; j >= 1; j--) {
            if(a[j] <= a[i]) break; //找到比a[i]小的位置就将a[i]插入到那个位置
            //空位为j，a[j]移到a[j + 1]
        }
        if(j != i - 1) {
            int temp = a[i];
            //[j, i - 1] 后移
            for(k = i - 1; k > j; k--) {
                a[k + 1] = a[k];
            }
            a[k + 1] = temp;
        }
    }
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}