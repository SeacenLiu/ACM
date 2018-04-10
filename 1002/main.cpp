//
//  main.cpp
//  1002
//
//  Created by SeacenLiu on 2018/4/9.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 Problem
 A + B Problem II
 
 Problem Description:
 I have a very simple problem for you. Given two integers A and B, your job is to calculate the Sum of A + B.
 
 Input:
 The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line consists of two positive integers, A and B. Notice that the integers are very large, that means you should not process them by using 32-bit integer. You may assume the length of each integer will not exceed 1000.
 
 Output:
 For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line is the an equation "A + B = Sum", Sum means the result of A + B. Note there are some spaces int the equation. Output a blank line between two test cases.
 
 Sample Input:
 2
 1 2
 112233445566778899 998877665544332211
 
 Sample Output:
 Case 1:
 1 + 2 = 3
 
 Case 2:
 112233445566778899 + 998877665544332211 = 1111111111111111110
 */

#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, k, l;
    scanf("%d", &n);
    char a[1001] = {0}, b[1001] = {0};
    int la, lb, len;
    for (i = 1; i <= n; i++) {
        len = 0;
        int c[1001] = {0};
        scanf("%s %s", a, b);
        printf("Case %d:\n%s + %s = ",i,a,b);
        la = strlen(a);
        lb = strlen(b);
        
        for (j = la - 1, k = lb - 1; j >= 0 && k >= 0; --j, --k) {
            c[len] += a[j] - '0' + b[k] - '0';
            if (c[len] > 9) {
                c[len] -= 10;
                c[len + 1]++;
            }
            len++;
        }

        if (j > 0) {
            for ( ; j >= 0; --j) {
                c[len++] += a[j] - '0';
            }
        } else if (k > 0) {
            for ( ; k >= 0; --k) {
                c[len++] += b[k] - '0';
            }
        }
        
        if (c[len]) {
            len++;
        }

        for (l = len - 1; l >= 0; --l) {
            printf("%d", c[l]);
        }

        printf("\n");
        if (i < n) {
            printf("\n");
        }
    }

    return 0;
}



