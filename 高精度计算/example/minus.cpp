#include <iostream>
using namespace std;

/*  常量  */
const int bits = 500;
/*  变量  */
string str;
int num1[bits], num2[bits], sum[bits];
size_t num1_len, num2_len, sum_len;

/*  函数申明  */
void input(int *num, int index);   //输入
void _minus(int *num1, int *num2, int *sum);     //相减
void output(int *sum);  //输出

/*  函数实现  */
int main() {
    input(num1, 0);
    input(num2, 1);
    
    _minus(num1, num2, sum);
    
    output(sum);
    return 0;
}

void input(int *num, int index) {

    //输入
    cin >> str; 
    if(index == 0) num1_len = str.length();
    else num2_len = str.length();

    //倒序转化为高精度数
    if(!index)
        for(int i = 1; i <= num1_len; i++) {
            num[i] = str[num1_len - i] - '0';
        }
    else
        for(int i = 1; i <= num2_len; i++) num[i] = str[num2_len - i] - '0';

}

void _minus(int *num1, int *num2, int *sum) {
    sum_len = 1;        //结果的位数
    int carry_bit = 0;  //进位

    //核心
    while(sum_len <= num1_len || sum_len <= num2_len) {
        //相加
        sum[sum_len] = num1[sum_len] + num2[sum_len] + carry_bit;
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