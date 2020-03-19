//
// Created by 78540 on 2020/3/19.
//

// 有障碍物的最短路径
//输入:
//[
//[0,0,0],
//[0,1,0],
//[0,0,0]
//]
//输出: 2

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
     static int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//        m行n列

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>> path(m,vector<long>(n,0));
        if(obstacleGrid[0][0]==1)
            return 0;
        else{
            path[0][0]=1;
            for(int i =1;i<n;i++){
                if(obstacleGrid[0][i]==1)
                    path[0][i]=0;
                else
                    path[0][i]=path[0][i-1];
            }

            for(int j=1;j<m;j++){
                if(obstacleGrid[j][0]==1)
                    path[j][0]=0;
                else
                    path[j][0]=path[j-1][0];
            }

            for(int i=1;i<m;i++){
                for(int j=1;j<n;j++){
                    if(obstacleGrid[i][j]==1)
                        path[i][j]=0;
                    else
                        path[i][j]=path[i-1][j]+path[i][j-1];
                }
            }
            return path[m-1][n-1];
        }
    }
};