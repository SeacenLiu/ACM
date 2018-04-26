//
//  main.cpp
//  1173
//
//  Created by SeacenLiu on 2018/4/26.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 Problem
 采矿
 
 Problem Description:
 某天gameboy玩魔兽RPG。有一个任务是在一个富含金矿的圆形小岛上建一个基地，以最快的速度采集完这个小岛上的所有金矿。这个小岛上有n(0<n<1000000)个金矿，每个金矿的矿藏量是相等的。而且这个小岛的地势非常平坦，所以基地可以建在小岛的任何位置，每个金矿的采矿速度只跟矿藏到基地的路程长度有关。为了不让这个任务太无聊，游戏设计者对这个小岛施了个“魔法”，规定矿工在小岛上只能正南正北正西正东走。也就是说矿工不能斜着在岛上走。
 
 这个小岛在一个二维直角坐标系中描述。
 
 你的任务就是帮gameboy找一个建造基地的位置，使矿工能以最快的速度采完所有矿。
 
 Input:
 输入数据有多组。每组数据的第一行是一个正整数n(0<n<1000000),表示小岛上有n个金矿。在接下来的n行中，每行有两个实数x,y，表示其中一个金矿的坐标。n=0表示输入数据结束。

 
 Output:
 每一组输入数据对应一行输出，输出两个实数x，y（保留小数点后两位），也就是你找到的建造基地的位置坐标。如果坐标不唯一，可以任选一个输出。
 
 Sample Input:
 4
 1.0 1.0
 3.0 1.0
 3.0 3.0
 1.0 3.0
 0
 
 Sample Output:
 2.00 2.00
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct point {
    double x, y;
}points[1000000];

bool compX(point a, point b) {
    return a.x < b.x;
}

bool compY(point a, point b) {
    return a.y < b.y;
}

int main(int argc, const char * argv[]) {
    int n, i;
    double x, y;
    cout.precision(2);
    while (cin >> n && n) {
        for (i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }
        if (n % 2) {
            sort(points, points+n, compX);
            x = points[(n-1)/2].x;
            sort(points, points+n, compY);
            y = points[(n-1)/2].y;
        } else {
            sort(points, points+n, compX);
            x = (points[n/2].x + points[(n-2)/2].x) * 0.5;
            sort(points, points+n, compY);
            y = (points[n/2].y + points[(n-2)/2].y) * 0.5;
        }
        cout << fixed << x << " " << y << endl;
    }
    return 0;
}

//        for (i = 0; i < n; i++) {
//            cout << fixed << points[i].x << " " << points[i].y << endl;
//        }
