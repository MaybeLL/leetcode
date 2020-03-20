#include <iostream>
#include "dp/139.cpp"
#include  <string>
#include <vector>

using namespace std;

int main() {
    Solution solution;
//    s = "leetcode", wordDict = ["leet", "code"]
//    "bb"
//    ["a","b","bbb","bbbb"]
    string s = "bb";
    vector<string> wordDict={"a","b","bbb","bbbb"};
    bool res =solution.wordBreak(s,wordDict);
    cout<<res<<endl;
    return 0;


}
