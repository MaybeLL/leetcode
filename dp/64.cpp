//
// Created by 78540 on 2020/3/19.
//

//64.最小路径和
//输入:
//[
//[1,3,1],
//[1,5,1],
//[4,2,1]
//]
//输出: 7
//解释: 因为路径 1→3→1→1→1 的总和最小。

//cost[i][j]=min(cost[i-1][j],cost[i][j-1])+grid[i][j]

#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> cost(m,vector<int>(n,0));

//        for(int i =1;i<n;i++){
//            cost[0][i]=cost[0][i-1]+grid[0][i];
//        }
//        for(int i =1;i<m;i++){
//            cost[i][0]=cost[i-1][0]+grid[i][0];
//        }
//
//        for(int i=1;i<m;i++){
//            for(int j=1;j<n;j++){
//                cost[i][j]=min(cost[i-1][j],cost[i][j-1])+grid[i][j];
//            }
//        }

// ----------------优化------------------------
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0){
                    cost[0][0]=grid[0][0];
                }else if(i==0){
                    cost[i][j]=cost[i][j-1]+grid[i][j];
                }else if(j==0){
                    cost[i][0]=cost[i-1][0]+grid[i][0];
                } else{
                    cost[i][j]=min(cost[i-1][j],cost[i][j-1])+grid[i][j];
                }

            }
        }
        return cost[m-1][n-1];
    }
};