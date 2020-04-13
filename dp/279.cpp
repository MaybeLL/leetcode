//
// Created by 78540 on 2020/3/24.
//

//最少平方数p[x]是x所需最少平方数个数。
//p[0]=0,p[1]=1,p[2]=2,p[3]=3,p[4]=1,p[5]=2,p[6]=3,p[7]=4,p[9]=1
//for(int j =1;n-j*j>0;j++){
//minp=min(minp,p[n-j*j])
//
//}
//p[n]=minp+1;
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if(n==0||n==1||n==2||n==3){
            return n;
        }
        else{
            vector<int> p(n+1,0);
            p[0] = 0;
            p[1] = 1;
            p[2] = 2;
            p[3] = 3;
            for ( int i =4;i<n+1;i++){
                int minp = p[i-1];
                for(int j =1;i-j*j>=0;j++){

                    minp=min(minp,p[i-j*j]);
                }
                p[i]=minp+1;
            }
            return p[n];
        }
    }
};