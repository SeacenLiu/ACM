//
//  main.cpp
//  1006
//
//  Created by SeacenLiu on 2018/4/11.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 Problem
 Tick and Tick
 
 Problem Description:
 The three hands of the clock are rotating every second and meeting each other many times everyday. Finally, they get bored of this and each of them would like to stay away from the other two. A hand is happy if it is at least D degrees from any of the rest. You are to calculate how much time in a day that all the hands are happy.
 
 Input:
 The input contains many test cases. Each of them has a single line with a real number D between 0 and 120, inclusively. The input is terminated with a D of -1.
 
 Output:
 For each D, print in a single line the percentage of time in a day that all of the hands are happy, accurate up to 3 decimal places.
 
 Sample Input:
 0
 120
 90
 -1
 
 Sample Output:
 100.000
 0.000
 6.251
 */

// s(t) = 6t , m(t) = 0.1t , h(t) = 1/120 t

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int D;
    while (cin >> D && D != -1) {
        
    }
    return 0;
}
