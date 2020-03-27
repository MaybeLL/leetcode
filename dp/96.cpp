//
// Created by 78540 on 2020/3/20.
//
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n==1||n==0){
            return 1;
        }
        else{
            vector<int> t(n+1,0);
            t[0]=1;
            t[1]=1;
            for(int i =2;i<n+1;i++){
                for(int j =1;j<=i;j++){
                    t[i] +=t[j-1]*t[i-j];
                }
            }
            return t[n];
        }
    }
};