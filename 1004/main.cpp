//
//  main.cpp
//  1004
//
//  Created by SeacenLiu on 2018/4/10.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 Problem
 Let the Balloon Rise
 
 Problem Description:
 Contest time again! How excited it is to see balloons floating around. But to tell you a secret, the judges' favorite time is guessing the most popular problem. When the contest is over, they will count the balloons of each color and find the result.
 
 This year, they decide to leave this lovely job to you.
 
 Input:
 Input contains multiple test cases. Each test case starts with a number N (0 < N <= 1000) -- the total number of balloons distributed. The next N lines contain one color each. The color of a balloon is a string of up to 15 lower-case letters.
 
 A test case with N = 0 terminates the input and this test case is not to be processed.
 
 Output:
 For each case, print the color of balloon for the most popular problem on a single line. It is guaranteed that there is a unique solution for each test case.
 
 Sample Input:
 5
 green
 red
 blue
 red
 red
 3
 pink
 orange
 pink
 0
 
 Sample Output:
 red
 pink
 */

// Tip:
// 注意 sum 和 max 的配合使用
// char的二维数组
// 当前只想到类似冒泡的写法

#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, k, sum, max;
    char a[1000][16];
    while (~scanf("%d", &n) && n) {
        max = -1;
        k = 0;
        for (i = 0; i < n; i++) {
            scanf("%s", a[i]);
        }
        for (i = 0; i < n; i++) {
            sum = 0;
            for (j = i + 1; j < n; j++) {
                if (!strcmp(a[i], a[j])) {
                    sum++;
                }
                if (sum > max) {
                    max = sum;
                    k = i;
                }
            }
        }
        printf("%s\n", a[k]);
    }
    
    return 0;
}
