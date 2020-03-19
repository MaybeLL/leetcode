//
// Created by jixie on 2019/12/16.
//
//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
//
//示例 1：
//
//输入: "babad"
//输出: "bab"
//注意: "aba" 也是一个有效答案。
//示例 2：
//
//输入: "cbbd"
//输出: "bb"

//Test Case
//in : ""    "s"    "ab"   "aa"   "aabccb"
//out : ""    "s"   "a"    "aa"    "bccb"
#include "iostream"
#include <string>
#include <vector>
using namespace std;

////    1.暴力法   超时
//class Solution {

//public:
//    string longestPalindrome(string s) {
//        int n = s.size();
//        if(n==1)
//            return s;
//        if(n==2){
//            if(s[0]==s[1])
//                return s;
//            else{
//                return s.substr(0,1);
//            }
//        }
//        int _n = 2*n-1;
//
//        int mid = (_n-1)/2;
//        int maxlength=0;
//        int left=0,right=0;
//
//        int i = _n-1;
//        while (i>=0){
////            a_b_a_b
//            if (i%2==1){
//                if(s[(i-1)/2]==s[(i+1)/2]){
//                    int j=1;
//                    while(s[(i-1-2*j)/2]==s[(i+1+2*j)/2]&&(i-1-2*j)>=0&&(i+1+2*j)<=_n-1){
//                        j++;
//                    }
//                    if(2*j>maxlength){
//                        maxlength = 2*j;
//                        left = (i-1-2*j+2)/2;
//                    }
//                }
//                i--;
//                if(i+1<maxlength){
//                    break;
//                }
//
//            }
////            a_b_a
//            if (i%2==0){
//                int j=0;
//                while(s[(i-2*(j+1))/2]==s[(i+2*(j+1))/2]&&(i-2*(j+1))>=0&&(i+2*(j+1))<=_n-1){
//                    j++;
//                }
//                if((1+2*j)>maxlength){
//                    maxlength = 1+2*j;
//                    left = (i-2*j)/2;
//                }
//                i--;
//                if(i+1<maxlength){
//                    break;
//                }
//            }
//
//            }
//
//        return s.substr(left,maxlength);
//    }
//};

//dp法
//初始化1字母和2字母回文
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==1)
            return s;
        if(n==2){
            if(s[0]==s[1])
                return s;
            else{
                return s.substr(0,1);
            }
        }

        int maxlen = 1;
        int left=0;
        vector<vector<bool>> p = vector<vector<bool>>(n,vector<bool>(n, false));
        for(int i=0;i<n;i++){
            p[i][i]= true;
            maxlen =1;
            left =i;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                p[i][i+1]= true;
                maxlen =2;
                left = i;
            }
        }
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                p[i][i+k-1]=(p[i+1][i+k-2])&&(s[i]==s[i+k-1]);
                if((k>maxlen)&&p[i][i+k-1]){
                    maxlen = k;
                    left = i;
                }
            }
        }
        return s.substr(left,maxlen);
    }
};

