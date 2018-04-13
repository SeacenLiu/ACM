//
//  main.cpp
//  1009
//
//  Created by SeacenLiu on 2018/4/13.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 Problem
 FatMouse' Trade
 
 Problem Description:
 FatMouse prepared M pounds of cat food, ready to trade with the cats guarding the warehouse containing his favorite food, JavaBean.
 The warehouse has N rooms. The i-th room contains J[i] pounds of JavaBeans and requires F[i] pounds of cat food. FatMouse does not have to trade for all the JavaBeans in the room, instead, he may get J[i]* a% pounds of JavaBeans if he pays F[i]* a% pounds of cat food. Here a is a real number. Now he is assigning this homework to you: tell him the maximum amount of JavaBeans he can obtain.
 
 Input:
 The input consists of multiple test cases. Each test case begins with a line containing two non-negative integers M and N. Then N lines follow, each contains two non-negative integers J[i] and F[i] respectively. The last test case is followed by two -1's. All integers are not greater than 1000.
 
 Output:
 For each test case, print in a single line a real number accurate up to 3 decimal places, which is the maximum amount of JavaBeans that FatMouse can obtain.
 
 Sample Input:
 5 3
 7 2
 4 3
 5 2
 20 3
 25 18
 24 15
 15 10
 -1 -1
 
 Sample Output:
 13.333
 31.500
 */

// Tip:
// 贪心算法
// 优先满足局部最优情况

#include <iostream>
#include <algorithm>
using namespace std;

struct room {
    int j, f;
    double t;
}r[999];

void computeT(room *r) {
    r->t = double(r->j) / r->f;
}

bool compareT(room a, room b) {
    return a.t > b.t;
}

int main(int argc, const char * argv[]) {
    int m, n, i;
    double sum;
    cout.precision(3);
    while (cin >> m >> n && m != -1 && n != -1) {
        sum = 0;
        for (i = 0; i < n; i++) {
            cin >> r[i].j >> r[i].f;
            computeT(&r[i]);
        }
        sort(r, r+n, compareT);
        for (i = 0; i < n; i++) {
            m -= r[i].f;
            sum += r[i].j;
            if (m < 0) {
                sum -= abs(m)*r[i].t;
                break;
            }
        }
        cout << fixed << sum << endl;
    }
    return 0;
}
