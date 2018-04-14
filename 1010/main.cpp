//
//  main.cpp
//  1010
//
//  Created by SeacenLiu on 2018/4/14.
//  Copyright © 2018年 成. All rights reserved.
//

/**
 Problem
 Tempter of the Bone
 
 Problem Description:
 The doggie found a bone in an ancient maze, which fascinated him a lot. However, when he picked it up, the maze began to shake, and the doggie could feel the ground sinking. He realized that the bone was a trap, and he tried desperately to get out of this maze.
 
 The maze was a rectangle with sizes N by M. There was a door in the maze. At the beginning, the door was closed and it would open at the T-th second for a short period of time (less than 1 second). Therefore the doggie had to arrive at the door on exactly the T-th second. In every second, he could move one block to one of the upper, lower, left and right neighboring blocks. Once he entered a block, the ground of this block would start to sink and disappear in the next second. He could not stay at one block for more than one second, nor could he move into a visited block. Can the poor doggie survive? Please help him.
 
 Input:
 The input consists of multiple test cases. The first line of each test case contains three integers N, M, and T (1 < N, M < 7; 0 < T < 50), which denote the sizes of the maze and the time at which the door will open, respectively. The next N lines give the maze layout, with each line containing M characters. A character is one of the following:
 
 'X': a block of wall, which the doggie cannot enter;
 'S': the start point of the doggie;
 'D': the Door; or
 '.': an empty block.
 
 The input is terminated with three 0's. This test case is not to be processed.
 
 Output:
 For each test case, print in one line "YES" if the doggie can survive, or "NO" otherwise.
 
 Sample Input:
 4 4 5
 S.X.
 ..X.
 ..XD
 ....
 3 4 5
 S.X.
 ..X.
 ...D
 0 0 0
 
 Sample Output:
 NO
 YES
 */

// Tip:
// 深度优先搜索
// 奇偶剪枝

# include <iostream>
# include <cmath>
using namespace std;

char str[10][10];
int m, n, t;
int ex, ey;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool if_yes;                //布尔变量，来判断是否可以到达
int main()
{
    void dfs(int x, int y, int count);
    while(cin >> m >> n >> t && m != 0 && n != 0 && t != 0)
    {
        int i, j, sx = 0, sy = 0, wall_count = 0;
        getchar();
        if_yes = false;
        memset(str, '\0', sizeof(str));
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                cin >> str[i][j];
                if(str[i][j] == 'S' || str[i][j] == 's')     //找到起点
                {
                    sx = i;
                    sy = j;
                    str[i][j] = 'X';                        //起点变成墙，避免搜索的时候进来，
                }
                else if(str[i][j] == 'D' || str[i][j] == 'd') //找到终点
                {
                    ex = i;
                    ey = j;
                }
                else if(str[i][j] == 'X' || str[i][j] == 'x')  //数墙有多少
                    wall_count++;
            }
            getchar();
        }
        if(n * m - wall_count >= t)                 //空白的地方必须大于等于时间，这个很明确的，不然到不了，进行剪枝
        {
            dfs(sx, sy, 0);
        }
        if(if_yes)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
void dfs(int x, int y, int count)
{
    if(ex == x && ey == y && count == t)                //找到了
    {
        if_yes = true;
        return;
    }
    int a = (t - count) - (abs(x - ex) + abs(y - ey));   //算出偏移路径
    if(a % 2 == 1 || a < 0)                               //如果是奇数或者小于0， 进行剪枝
    {
        if_yes = false;
        return;
    }
    for(int i = 0; i < 4; i++)                       //四个方向进行搜索
    {
        if(x + dx[i] < 0 || x + dx[i] > m - 1 || y + dy[i] < 0 || y + dy[i] > n - 1)  //越出边界的情况
            continue;
        if(str[x + dx[i]][y + dy[i]] != 'X' && str[x + dx[i]][y + dy[i]] != 'x')   //如果该位置可以走
        {
            str[x + dx[i]][y + dy[i]] = 'X';         //变成墙，避免重新走过
            dfs(x + dx[i], y + dy[i], count + 1);    //递归进行搜索
            str[x + dx[i]][y + dy[i]] = '.';         //变回来
        }
        if(if_yes)
            break;
    }
}

