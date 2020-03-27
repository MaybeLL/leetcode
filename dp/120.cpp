//
// Created by 78540 on 2020/3/20.
//
//[
//[2],
//[3,4],
//[6,5,7],
//[4,1,8,3]
//]
//pathsum[i][j] = min(pathsum[i-1][j],pathsum[i-1][j-1])+triangle[i][j]

#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if(m==1){
            return triangle[0][0];
        } else{
            vector<vector<int>> pathsum(m,vector<int>(m,0));
            pathsum[0][0]=triangle[0][0];
            for(int i=1;i<m;i++){
                pathsum[i][0]=pathsum[i-1][0]+triangle[i][0];
            }
            for(int i=1;i<m;i++){
                pathsum[i][i]=pathsum[i-1][i-1]+triangle[i][i];
            }
            for(int i=2;i<m;i++){
                for(int j=1;j<i;j++){
                    pathsum[i][j] = min(pathsum[i-1][j],pathsum[i-1][j-1])+triangle[i][j];
                }
            }
            int res = pathsum[m-1][0];
            for(int i=0;i<m;i++){
                res = min(res,pathsum[m-1][i]);
            }
            return res;
        }
    }
};