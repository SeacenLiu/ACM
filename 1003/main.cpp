//
//  main.cpp
//  1003
//
//  Created by SeacenLiu on 2018/4/10.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 Problem
 Max Sum
 
 Problem Description:
 Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence. For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.
 
 Input:
 The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).
 
 Output:
 For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence. If there are more than one result, output the first one. Output a blank line between two cases.
 
 Sample Input:
 2
 5 6 -1 5 4 -7
 7 0 6 -1 1 -6 7 -5
 
 Sample Output:
 Case 1:
 14 1 4
 
 Case 2:
 7 1 6
 */

// 动态规划通常思路:
// 从结构入手 每次取最优的情况

// 注意:
// max的最小值问题

#include <stdio.h>

int main() {
    int m, n, i, j, k, st, en, sum, max;
    scanf("%d", &m);
    for (i = 1; i <= m; i++) {
        max = -1000;
        sum = st = en = 0;
        k = 1;
        int a[100000] = {0};
        scanf("%d", &n);
        
        for (j = 0; j < n; j++) {
            scanf("%d", &a[j]);
        }
        
        for (j = 0; j < n; j++) {
            sum += a[j];
            
            if (sum > max) {
                max = sum;
                st = k;
                en = j + 1;
            }
            
            if (sum < 0) {
                sum = 0;
                k = j + 2;
            }
        }
        
        printf("Case %d:\n%d %d %d\n", i, max, st, en);
        if (i < m) {
            printf("\n");
        }
    }
    return 0;
}

