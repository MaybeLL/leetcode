//
// Created by 78540 on 2020/4/20.
//

//给出一个完全二叉树，求出该树的节点个数。
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
    //求完全二叉树的节点个数
//    int countNodes(TreeNode* root) {
//        if(!root){
//            return 0;
//        }
//        return 1+countNodes(root->left)+countNodes(root->right);
//    }

    //层序遍历解法
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<TreeNode*> level;
        TreeNode* cur = root;
        level.push(cur);
        int res=0;
        while (!level.empty()){
            int range = level.size()-1;
            for(int i =0;i<=range;i++){
                cur = level.front();
                level.pop();
                if(cur->left){
                    level.push(cur->left);
                }
                if(cur->right){
                    level.push(cur->right);
                }
                res++;
            }
        }
        return res;
    }
};