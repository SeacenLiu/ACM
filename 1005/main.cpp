//
//  main.cpp
//  1005
//
//  Created by SeacenLiu on 2018/4/11.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 Problem
 Number Sequence
 
 Problem Description:
 A number sequence is defined as follows:
 
 f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
 
 Given A, B, and n, you are to calculate the value of f(n).
 
 Input:
 The input consists of multiple test cases. Each test case contains 3 integers A, B and n on a single line (1 <= A, B <= 1000, 1 <= n <= 100,000,000). Three zeros signal the end of input and this test case is not to be processed.
 
 Output:
 For each test case, print the value of f(n) on a single line.
 
 Sample Input:
 1 1 3
 1 2 10
 0 0 0
 
 Sample Output:
 2
 5
 */

// Tip:
// 递归是十分消耗内存的，慎用
// 学会寻找规律
//  mod 7 说明 f(n) 的值的范围只有 0 ~ 6
// 所以，在A和B固定的前提下，A * f(n - 1) + B * f(n - 2)的组合有 7×7 种情况
// 最重要是找出循环体 求出循环体使用 mod 来取出答案
// 最大循环只有 49 ，和 100,000,000 差远了！！！

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int a, b, n, i;
    int re[49] = {0};
    re[1] = 1;
    re[2] = 1;
    while (cin >> a >> b >> n && a && b && n) {
        for (i = 3; i < 49; i++) {
            re[i] = (a * re[i - 1] + b * re[i - 2]) % 7;
        }
        cout << re[n % 49] << endl;
    }
    return 0;
}
