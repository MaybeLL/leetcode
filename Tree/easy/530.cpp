//
// Created by 78540 on 2020/4/15.
//

//给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

//error test:[543,384,652,null,445,null,699]  699-652=47   错误输出61
class Solution {
public:
    //考虑利用中序遍历有序性。
    int getMinimumDifference(TreeNode* root) {
        TreeNode* cur_p = root;
        stack<TreeNode*> mystack;
        int lastval;
        int mindiff;
        bool flag = false;
//        int res;
        while (cur_p!=NULL||!mystack.empty()) {
            while (cur_p != NULL) {
                mystack.push(cur_p);
                cur_p = cur_p->left;
            }
            //出栈访问
            cur_p = mystack.top();
            mystack.pop();
            if(flag){
                mindiff = min(abs(cur_p->val-lastval),mindiff);
                lastval = cur_p->val;
            }else{
                lastval = cur_p->val;
                mindiff = INT_MAX;
                flag = true;
            }

            cur_p = cur_p->right;
        }
        return mindiff;
    }
};