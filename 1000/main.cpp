//
//  main.cpp
//  1000
//
//  Created by SeacenLiu on 2018/4/9.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 Problem
    A + B Problem
 Problem Description:
    Calculate A + B.
 Input:
    Each line will contain two integers A and B. Process to end of file.
 Output:
    For each case, output A + B in one line.
 Sample Input:
    1 1
 Sample Output:
    2
*/

// while(~scanf(“%d”,&n)) <=>  while(scanf(“%d”,&n)!=EOF)

#include<stdio.h>
int main()
{
    int a,b;
    // ~scanf() 不加~会超时
    while(~scanf("%d%d",&a,&b))
    {
        printf("%d\n",a+b);
    }
}

/*
 #include <iostream>
 using namespace std;
 
 int main(int argc, const char * argv[]) {
 int a, b;
 while (cin >> a >> b) {
 cout << a + b << endl;
 }
 return 0;
 }
*/
