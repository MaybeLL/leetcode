//
// Created by jixie on 2020/3/17.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
//双指针法
public:
    bool isSubsequence(string s, string t) {
        string::iterator i;
        string::iterator j = s.begin();
        for (i = t.begin(); i != t.end(); i++) {
            if (*i == *j) {
                j++;
                if (j == s.end()) {
                    break;
                }
            }
        }
        return j == s.end();
    }
};