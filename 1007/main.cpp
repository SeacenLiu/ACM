//
//  main.cpp
//  1007
//
//  Created by SeacenLiu on 2018/4/12.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 Problem
 Quoit Design
 
 Problem Description:
 Have you ever played quoit in a playground? Quoit is a game in which flat rings are pitched at some toys, with all the toys encircled awarded.
 In the field of Cyberground, the position of each toy is fixed, and the ring is carefully designed so it can only encircle one toy at a time. On the other hand, to make the game look more attractive, the ring is designed to have the largest radius. Given a configuration of the field, you are supposed to find the radius of such a ring.
 
 Assume that all the toys are points on a plane. A point is encircled by the ring if the distance between the point and the center of the ring is strictly less than the radius of the ring. If two toys are placed at the same point, the radius of the ring is considered to be 0.
 
 Input:
 The input consists of several test cases. For each case, the first line contains an integer N (2 <= N <= 100,000), the total number of toys in the field. Then N lines follow, each contains a pair of (x, y) which are the coordinates of a toy. The input is terminated by N = 0.
 
 Output:
 For each test case, print in one line the radius of the ring required by the Cyberground manager, accurate up to 2 decimal places.
 
 Sample Input:
 2
 0 0
 1 1
 2
 1 1
 1 1
 3
 -1.5 0
 0 0
 0 1.5
 0
 
 Sample Output:
 0.71
 0.00
 0.75
 */

// Tip
// <algorithm> 中的 sort函数 排序的时间复杂度是 n*log2(n)

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
#define min(a,b) ( ((a)>(b)) ? (b):(a) )
struct point {
    double x,y;
}a[100001];

bool cmp(const point &a,const point &b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x<b.x;
}

double dis(point a,point b) {
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

double S(point a[],int n) {
    double m = 1e+10;
    if (n == 2)
        return dis(a[0],a[1]);
    for(int i = 0; i < n-2; i++) {
        m = min(m,min(dis(a[i],a[i+1]),min(dis(a[i],a[i+2]),dis(a[i+1],a[i+2]))));
    }
    return m;
}

int main() {
    int n;
    while(scanf("%d",&n) && n) {
        for(int i=0; i<n; i++) {
            scanf("%lf%lf",&a[i].x,&a[i].y);
        }
        sort(a, a+n, cmp);
        printf("%.2lf\n",S(a,n)/2);
    }
    return 0;
    
}

/**
 Input:
 4
 0 0
 1 1
 0.5 100000
 100000 0.5
 下面的程序计算出的结果有误
 */

/** 分治法 三步骤
 划分问题：把问题的实例划分成子问题
 递归求解：递归解决子问题
 合并问题：合并子问题的解得到原问题的解
*/
/** 分治思想
 把这些点分成左右两部分，即将问题缩小，解决了小的，大的也就解决了。求出两个部分距离最短的距离，
 然后关键是求一点在左边，一点在右边的点的最短距离（关键），方法是找到“可疑点”，就是可能会小于刚才找到的最短距离的
 点集合。
*/
/** 好处
 在全局来说，测试数据越多，总的效率比暴力循环要高
*/

//#include <iostream>
//#include <cmath>
//#include <algorithm>
//#define Count 1000000
//
//using namespace std;
//struct point {
//    double x, y;
//} arrP[Count], arrX[Count], arrY[Count];
//
//static int tot = 0;
//
//double getDistance(point a, point b) {
//    tot++;
//    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
//}
//
//double minDistance(double a, double b) {
//    return a > b ? b : a;
//}
//
//bool upCompX(point a, point b) {
//    if (a.x == b.x) return a.y < b.y;
//    return a.x < b.x;
//}
//
//bool upCompY(point a, point b) {
//    if (a.y == b.y) return a.x < b.x;
//    return a.y < b.y;
//}
//
//double getMinDistance(int l, int r) {
//    if (l == r)
//        return 0;
//    if (l + 1 == r)
//        return getDistance(arrP[l], arrP[r]);
//    if (l + 2 == r)
//        return minDistance(minDistance(getDistance(arrP[l], arrP[l+1]), getDistance(arrP[l+1], arrP[r])), getDistance(arrP[l], arrP[r]));
//
//    int i = 0, j = 0, k = 0, mid = (l + r) / 2;
//    double min = minDistance(getMinDistance(l, mid), getMinDistance(mid + 1, r));
//
//    for (i = l; i <= r; i++) {
//        if(fabs(arrP[i].x - arrP[mid].x) < min)
//            arrX[j++]=arrP[i];
//    }
//    sort(arrX, arrX+j, upCompY);
//    mid = (j + 1) / 2;
//    for (i = 0; i < j; i++) {
//        if (fabs(arrX[i].y-arrX[mid].y) < min)
//            arrY[k++] = arrX[i];
//    }
//    for (i = 0; i < k; i++) {
//        for (j = i + 1; j < k; j++) {
//            double temp = getDistance(arrY[i], arrY[j]);
//            if (temp < min)
//                min = temp;
//        }
//    }
//
//    return min;
//}
//
//int main() {
//    int n, i;
//
//    while (cin >> n && n) {
//        double min;
//        for (i = 0; i < n; i++) {
//            cin >> arrP[i].x >> arrP[i].y;
//        }
//        sort(arrP, arrP + n, upCompX);
//        min = getMinDistance(0, n-1);
//        cout.precision(2);
//        cout << fixed << min / 2 << endl;
//    }
//    return 0;
//}
//

