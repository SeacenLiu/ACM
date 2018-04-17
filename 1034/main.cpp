//
//  main.cpp
//  1034
//
//  Created by SeacenLiu on 2018/4/17.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 Problem
 Candy Sharing Game
 
 Problem Description:
 A number of students sit in a circle facing their teacher in the center. Each student initially has an even number of pieces of candy. When the teacher blows a whistle, each student simultaneously gives half of his or her candy to the neighbor on the right. Any student, who ends up with an odd number of pieces of candy, is given another piece by the teacher. The game ends when all students have the same number of pieces of candy.
 Write a program which determines the number of times the teacher blows the whistle and the final number of pieces of candy for each student from the amount of candy each child starts with.
 
 Input:
 The input may describe more than one game. For each game, the input begins with the number N of students, followed by N (even) candy counts for the children counter-clockwise around the circle. The input ends with a student count of 0. Each input number is on a line by itself.
 
 Output:
 For each game, output the number of rounds of the game followed by the amount of candy each child ends up with, both on one line.
 
 Sample Input:
 6
 36
 2
 2
 2
 2
 2
 
 11
 22
 20
 18
 16
 14
 12
 10
 8
 6
 4
 2
 
 4
 2
 4
 6
 8
 0

 Sample Output:
 15 14
 17 22
 4 8
 */

#include <iostream>
using namespace std;

int a[1000] = {0};
int n;

bool isOdd(int x) {
    return x%2 != 0;
}

bool isEqual(int x, int y) {
    for (int i = x; i < y-1; i++) {
        if (a[i] != a[i+1])
            return false;
    }
    return true;
}

void giveCandy(int x, int y) {
    a[x] *= 0.5;
    if (x == n-1) {
        a[0] += a[x];
        a[x] += y;
        return;
    }
    giveCandy(x + 1, a[x]);
    a[x] += y;
}

int main(int argc, const char * argv[]) {
    int i, count;
    while (cin >> n && n) {
        count = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        while (1) {
            for (i = 0; i < n; i++) {
                if (isOdd(a[i])) {
                    a[i]++;
                }
            }
            if (isEqual(0, n)) break;
            giveCandy(0, 0);
            count++;
        }
        
        cout << count << " " << a[0] << endl;
    }
    return 0;
}
