//
// Created by 78540 on 2020/3/20.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//p[i][j]=false;
//for(int k: 0 -- m-1)
//p[i][j]=(p[i][j-wordDict[k].size()]&&(s.substr((j-wordDict[k].size()+1),wordDict[k].size())==wordDict[k]))||p[i][j]
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int l = s.size();
        int n_word =wordDict.size();
        if(n_word==0){
            return false;
        }
        int minwordlength = wordDict[0].size();
        string minword = wordDict[0];
        for(int i =0;i<n_word;i++){
            if(minwordlength>wordDict[i].size()){
                minwordlength = wordDict[i].size();
                minword = wordDict[i];
            }
        }

        if(l<minwordlength){
            return false;
        } else if(l==minwordlength){
            bool res = false;
            for(int i =0;i<n_word;i++){
                res = res|| (s==wordDict[i]);
            }
            return res;
        }
        else{
            vector<bool> p(l, false);
            for(int k=0;k<n_word;k++){
                if(s.substr(0,minwordlength)==wordDict[k]){
                    p[minwordlength-1]=true;
                }
            }

            for(int j=minwordlength;j<l;j++){
                for(int k=0;k<n_word;k++){
                    if(j>=wordDict[k].size()){
                        p[j]=(p[j-wordDict[k].size()]&&(s.substr((j-wordDict[k].size()+1),wordDict[k].size())==wordDict[k]))||p[j];
                    }
                    if((j==wordDict[k].size()-1)&&(s.substr(0,wordDict[k].size())==wordDict[k])){
                        p[j]=true;
                    }
                }
            }
            return p[l-1];
        }
    }
};