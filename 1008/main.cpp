//
//  main.cpp
//  1008
//
//  Created by SeacenLiu on 2018/4/13.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 Problem
 Elevator
 
 Problem Description:
 The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.
 
 For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.
 
 Input:
 There are multiple test cases. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100. A test case with N = 0 denotes the end of input. This test case is not to be processed.
 
 Output:
 Print the total time on a single line for each test case.
 
 Sample Input:
 1 2
 3 2 3 1
 0
 
 Sample Output:
 17
 41
 */

// Tip:
// 确定的必须加的先加上

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, i, sum, temp;
    int a[100] = {0};
    while (cin >> n && n) {
        sum = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        sum += a[0]*6 + n*5;
        for (i = 1; i < n; i++) {
            temp = a[i] - a[i-1];
            sum += temp > 0 ? temp*6 : abs(temp)*4;
        }
        cout << sum << endl;
    }
    return 0;
}
