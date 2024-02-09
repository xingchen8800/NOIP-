#include <iostream>
using namespace std;

/*  常量  */
const int bits = 500;
/*  变量  */
string str;
int add1[bits], add2[bits], sum[bits];
size_t add1_len, add2_len, sum_len;

/*  函数申明  */
void input(int *add, int index);   //输入
void add(int *add1, int *add2, int *sum);     //相加
void output(int *sum);  //输出

/*  函数实现  */
int main() {
    input(add1, 0);
    input(add2, 1);
    
    add(add1, add2, sum);
    
    output(sum);
    return 0;
}

void input(int *add, int index) {

    //输入
    cin >> str; 
    if(index == 0) add1_len = str.length();
    else add2_len = str.length();

    //倒序转化为高精度数
    if(!index)
        for(int i = 1; i <= add1_len; i++) {
            add[i] = str[add1_len - i] - '0';
        }
    else
        for(int i = 1; i <= add2_len; i++) add[i] = str[add2_len - i] - '0';

}

void add(int *add1, int *add2, int *sum) {
    sum_len = 1;        //结果的位数
    int carry_bit = 0;  //进位

    //核心
    while(sum_len <= add1_len || sum_len <= add2_len) {
        //相加
        sum[sum_len] = add1[sum_len] + add2[sum_len] + carry_bit;
        //进位
        carry_bit = sum[sum_len] / 10;
        sum[sum_len] %= 10;
        //更新位数
        sum_len++;
    }
    //将最后一次的进位补齐
    sum[sum_len] = carry_bit;

    //删去前导零
    while(sum[sum_len] == 0 && sum_len > 1) 
        sum_len--;

    return;
}

void output(int *sum) {
    for(int i = sum_len; i >= 1; i--) cout << sum[i];
    cout << endl;
}