//
//  main.cpp
//  1076
//
//  Created by SeacenLiu on 2018/4/19.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 Problem
 An Easy Task
 
 Problem Description:
 Ignatius was born in a leap year, so he want to know when he could hold his birthday party. Can you tell him?
 
 Given a positive integers Y which indicate the start year, and a positive integer N, your task is to tell the Nth leap year from year Y.
 
 Note: if year Y is a leap year, then the 1st leap year is year Y.
 
 Input:
 The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.
 Each test case contains two positive integers Y and N(1<=N<=10000).
 
 Output:
 For each test case, you should output the Nth leap year from year Y.
 
 Sample Input:
 3
 2005 25
 1855 12
 2004 10000
 
 Sample Output:
 2108
 1904
 43236

 Hint
 We call year Y a leap year only if (Y%4==0 && Y%100!=0) or Y%400==0.
 */

#include <iostream>
using namespace std;

int isLeapY(int y) {
    return ((y%4 == 0 && y%100 != 0) || y%400 == 0) ? 1 : 0;
}

int main(int argc, const char * argv[]) {
    int m, i, y, n;
    cin >> m;
    for (i = 0; i < m; i++) {
        cin >> y >> n;
        while (n) {
            n -= isLeapY(y++);
        }
        cout << --y << endl;
    }
    return 0;
}
