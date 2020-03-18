#include <iostream>
#include "dp/392.cpp"
#include  <string>

using namespace std;

int main() {
    string s = "he";
    string t = "hell";
    Solution solution;
    if (solution.isSubsequence(s, t)) {
        cout << "true" << endl;
    }
    return 0;

}
