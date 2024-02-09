#include <iostream>
using namespace std;

const int N = 10001;
int n ,array[N];
int main() {
    int i, j, k;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> array[i];

    for(i = 1; i <= n; i++) {
        k = i;     
        //寻找最小值(i + 1, n)
        for(j = i + 1; j <= n; j++) if(array[j] < array[k]) k =j;
        //交换
        if(k != i) {
            swap(array[i], array[k]);
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}