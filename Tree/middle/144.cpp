//
// Created by 78540 on 2020/4/17.
//

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
    //给定一个二叉树，返回它的 前序 遍历。
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        stack<TreeNode*> mystack;
        vector<int> res;
        while(cur||!mystack.empty()){
            while(cur){
                //访问根节点
                res.push_back(cur->val);
                mystack.push(cur);
                cur = cur->left;
            }
            cur = mystack.top();
            mystack.pop();
            cur = cur->right;
        }
        return res;
    }
};