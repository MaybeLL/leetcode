//
// Created by 78540 on 2020/3/18.
//

#include <vector>
using namespace std;

class Solution {
public:
    int waysToStep(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(n==3)
            return 4;
        int i=4;
        long long a =1,b = 2,c = 4,res =0;

        while (i<n+1){
            res=(a+b+c)%1000000007;
            a=b;
            b=c;
            c=res;
            i++;
        }
        return res;
    }
};
