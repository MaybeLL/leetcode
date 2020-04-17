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
    //129.求根到叶子节点数字之和
    //1.每下一层,sum乘10+下一层节点val
    //2.问题的的关键是找叶节点
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        int a=0;
        helper(root,a,0);
        return a;
    }

    void helper(TreeNode* cur_root,int &sums,int cur_sum){
        if(!cur_root)
            return;
        if(!cur_root->left&&!cur_root->right){
            cur_sum = cur_sum*10+cur_root->val;
            sums+=cur_sum;
            return;
        }else if(!cur_root->left&&cur_root->right){
            cur_sum = cur_sum*10+cur_root->val;
            helper(cur_root->right,sums,cur_sum);
        }else if(!cur_root->right&&cur_root->left){
            cur_sum = cur_sum*10+cur_root->val;
            helper(cur_root->left,sums,cur_sum);
        }else{
            cur_sum = cur_sum*10+cur_root->val;
            helper(cur_root->left,sums,cur_sum);
            helper(cur_root->right,sums,cur_sum);
        }
    }
};