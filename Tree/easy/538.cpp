//
// Created by 78540 on 2020/4/15.
//

#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
    //累加树：使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
    //还是中序遍历
    TreeNode* convertBST(TreeNode* root) {

    }
};