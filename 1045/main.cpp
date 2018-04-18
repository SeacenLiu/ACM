//
//  main.cpp
//  1045
//
//  Created by SeacenLiu on 2018/4/18.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 Problem
 Fire Net
 
 Problem Description:
 Suppose that we have a square city with straight streets. A map of a city is a square board with n rows and n columns, each representing a street or a piece of wall.
 
 A blockhouse is a small castle that has four openings through which to shoot. The four openings are facing North, East, South, and West, respectively. There will be one machine gun shooting through each opening.
 
 Here we assume that a bullet is so powerful that it can run across any distance and destroy a blockhouse on its way. On the other hand, a wall is so strongly built that can stop the bullets.
 
 The goal is to place as many blockhouses in a city as possible so that no two can destroy each other. A configuration of blockhouses is legal provided that no two blockhouses are on the same horizontal row or vertical column in a map unless there is at least one wall separating them. In this problem we will consider small square cities (at most 4x4) that contain walls through which bullets cannot run through.
 
 The following image shows five pictures of the same board. The first picture is the empty board, the second and third pictures show legal configurations, and the fourth and fifth pictures show illegal configurations. For this board, the maximum number of blockhouses in a legal configuration is 5; the second picture shows one way to do it, but there are several other ways.
 
    http://acm.hdu.edu.cn/data/images/1045-1.jpg
 
 Your task is to write a program that, given a description of a map, calculates the maximum number of blockhouses that can be placed in the city in a legal configuration.
 
 Input:
 The input file contains one or more map descriptions, followed by a line containing the number 0 that signals the end of the file. Each map description begins with a line containing a positive integer n that is the size of the city; n will be at most 4. The next n lines each describe one row of the map, with a '.' indicating an open space and an uppercase 'X' indicating a wall. There are no spaces in the input file.
 
 Output:
 For each test case, output one line containing the maximum number of blockhouses that can be placed in the city in a legal configuration.
 
 Sample Input:
 4
 .X..
 ....
 XX..
 ....
 2
 XX
 .X
 3
 .X.
 X.X
 .X.
 3
 ...
 .XX
 .XX
 4
 ....
 ....
 ....
 ....
 0
 
 Sample Output:
 5
 1
 5
 2
 4
 */

/**
 测试用例
 4
 ...X
 ..XX
 .XX.
 ....
 
 5
*/

// Tip:
// 需要把所有的可行方法都试出来，要最大的
// 注意search代码中的回溯的用法

#include <iostream>
using namespace std;
int n;
char a[4][4] = {0};
int tot = 0;

bool canAdd(int x, int y) {
    if (a[x][y] != '.')
        return false;
    bool canX = true;
    int i;
    for (i = 0; i < y; i++) {
        if (a[x][i] == 'O')
            canX = false;
        if (a[x][i] == 'X')
            canX = true;
    }
    if (!canX) return canX;
    for (i = 0; i < x; i++) {
        if (a[i][y] == 'O')
            canX = false;
        if (a[i][y] == 'X')
            canX = true;
    }
    return canX;
}

void search(int k, int count) {
    if (k == n * n) {
        if (count > tot) {
            tot = count;
            return;
        }
    } else {
        int x = k / n;
        int y = k % n;
        if (canAdd(x, y)) {
            a[x][y] = 'O';
            search(k + 1, count + 1);
            // 回溯
            a[x][y] = '.';
            search(k + 1, count);
        } else {
            search(k + 1, count);
        }
    }
}

int main(int argc, const char * argv[]) {
    int i, j;
    while (cin >> n && n) {
        tot = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        search(0, 0);
        cout << tot << endl;
    }
    return 0;
}

