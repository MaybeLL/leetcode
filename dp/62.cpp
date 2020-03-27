//
// Created by 78540 on 2020/3/19.
//

#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> a=vector<vector<int>>(n,vector<int>(m,0));
        for(int i=0; i < m; i++){
            a[0][i]=1;
        }
        for(int j=0;j<n;j++){
            a[j][0]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                a[i][j]=a[i][j-1]+a[i-1][j];
            }
        }
        return a[n-1][m-1];
    }
};