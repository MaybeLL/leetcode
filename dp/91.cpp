//
// Created by 78540 on 2020/3/19.
//

//91.解码方法
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//173452
//test case: 117-->3
#include  <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n==1){
            if(s[0]=='0'){
                return 0;
            } else{
                return 1;
            }
        }
        if(n==2){
            if((s[0]=='2'&&s[1]>'6')||(s[0]>'2'&&s[1]!='0')||(s[0]<='2'&&s[0]>='1'&&s[1]=='0')){
                return 1;
            }else if(s[0]=='0'||(s[0]>'2'&&s[1]=='0')){
                return 0;
            } else{
                return 2;
            }
        }
        vector<int> f(n,0);
        if(s[0]=='0'){
            f[0]=0;
        } else{
            f[0]=1;
        }
        if((s[0]=='2'&&s[1]>'6')||(s[0]>'2'&&s[1]!='0')||(s[0]<='2'&&s[0]>='1'&&s[1]=='0')){
            f[1]= 1;
        } else if (s[0]=='0'||(s[0]>'2'&&s[1]=='0')){
            f[1]=0;
        }else{
            f[1]= 2;
        }

        for(int i=2;i<n;i++){
            if(s[i-1]=='2'&&s[i]>'6')||(s[i-1]>'2'&&s[i]!='0'){
                f[i]=f[i-1];
            } else if(s[i-1]=='0'&&s[i]!='0'){
                f[i]=f[i-1];
            }else if(s[i-1]=='0'&&s[i]=='0'||(s[i-1]>'2'&&s[i]=='0')){
                f[i]=0;
            } else if ((s[i-1]<='2'&&s[i-1]>='1'&&s[i]=='0')){
                f[i]=f[i-2];
            }
            else{
                f[i]=f[i-2]+f[i-1];
            }

        }
        return f[n-1];
    }
};