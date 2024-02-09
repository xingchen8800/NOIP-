/*
快速排序：
    通过一趟排序将待待排记录分割成独立的两部分，
    其中一部分记录的关键字均比另一部分记录的关键字小，
    则可分别对这两部分记录继续进行排序，
    以达到整个序列有序。

    一趟的具体做法：l = 1, r = n
                 i = l, j = r, mid = (l + r) / 2;
                 if(i <= j)
                    a ∈ [0, j], a < mid;
                    b ∈ [i, n], b > mid
                    swap(a, b)
                 //未到边界
                 if(l < j) s(l, j) //排序[l, j]
                 if(i < r) s(i, r) //排序[a, r]
*/
#include <iostream>
using namespace std;

void qsort(int s, int e);
int n, a[10001];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    qsort(1, n);
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}

void qsort(int s, int e) {
    int i, j, mid;
    //i取左边界, j取右边界，mid取a[s, e]的中简值
    i = s, j = e, mid = a[(s + e) / 2];
    /*
    1:
         i    mid     j
        [5 4]  3  [2 1]
    2:
           i  mid  j
        [5 4]  3  [2 1]
    3:        mid(i, j)
        [5 4]  3  [2 1]
    4:     j  mid  i
        [5 4]  3  [2  1]
        注:4 > 3; break;
           2 < 3; break;
           j = 1, i = 3
           i > j 不交换
    */
    /*
    1:
         i    mid    j
        [1 2]  3  [4 5]
        注:1 < 3; break;
           5 > 3; break;
           i < j 交换
           i++; i = 1;
           j--; j = 3;
    */
    do {
        while(a[i] < mid) i++;  //在[i, mid]中找<=mid的数
        while(a[j] > mid) j--;  //在[mid, j]中找>=mid的数
        if(i <= j) {    //找到一组与排序目标不一致的数对
            swap(a[i], a[j]);   //交换
            i++, j--;           //继续搜索
        }
    } while(i <= j);
    //j不越界
    if(s < j) qsort(s, j);
    //i不越界
    if(i < e) qsort(i, e);
}