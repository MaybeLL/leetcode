//
// Created by 78540 on 2020/4/16.
//

//根据一棵树的中序遍历与后序遍历构造二叉树。
//
//注意:
//你可以假设树中没有重复的元素。

#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
    //思路和105一样
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

    }
};