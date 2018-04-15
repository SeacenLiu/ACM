//
//  main.cpp
//  1028
//
//  Created by SeacenLiu on 2018/4/15.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 Problem
 Ignatius and the Princess III
 
 Problem Description:
 "Well, it seems the first problem is too easy. I will let you know how foolish you are later." feng5166 says.
 
 "The second problem is, given an positive integer N, we define an equation like this:
 N=a[1]+a[2]+a[3]+...+a[m];
 a[i]>0,1<=m<=N;
 My question is how many different equations you can find for a given N.
 For example, assume N is 4, we can find:
 4 = 4;
 4 = 3 + 1;
 4 = 2 + 2;
 4 = 2 + 1 + 1;
 4 = 1 + 1 + 1 + 1;
 so the result is 5 when N is 4. Note that "4 = 3 + 1" and "4 = 1 + 3" is the same in this problem. Now, you do it!"
 
 Input:
 The input contains several test cases. Each test case contains a positive integer N(1<=N<=120) which is mentioned above. The input is terminated by the end of file.
 
 Output:
 For each test case, you have to output a line contains an integer P which indicate the different equations you have found.
 
 Sample Input:
 4
 10
 20
 
 Sample Output:
 5
 42
 627
 */

// Tip:
// 递推
// 用数组存储

#include <iostream>
using namespace std;

int a[121][121] = {0};

int depart(int x, int y) {
    if (a[x][y] != 0)
        return a[x][y];
    if (y == 1)
        a[x][y] = 1;
    else if (x == y)
        a[x][y] = depart(x, y-1) + 1;
    else if (x < y)
        a[x][y] = depart(x, x);
    else if (x > y)
        a[x][y] = depart(x, y-1) + depart(x-y, y);
    return a[x][y];
}

int main() {
    int n;
    while (cin >> n) {
        cout << depart(n, n) << endl;
    }
    return 0;
}

