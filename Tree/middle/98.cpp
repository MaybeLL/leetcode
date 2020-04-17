//
// Created by 78540 on 2020/4/16.
//

#include <vector>
#include <stack>
using namespace std;

typedef struct TreeNode TreeNode;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
//    验证二叉搜索树
//    错误输出:[10,5,15,null,null,6,20]
//   必须确保右子树的最小节点大于根节点,左子树的最大节点小于根节点
//  思路1:非递归中序遍历(超时)  思路2:递归
//    思路1:超时
//    bool isValidBST(TreeNode* root) {
//        TreeNode* cur_p = root;
//        stack<TreeNode*> mystack;
//        int last;
//        bool flag = true;
//        while(cur_p!=NULL||!mystack.empty()){
//            while(cur_p!=NULL){
//                mystack.push(cur_p);
//                cur_p = cur_p->left;
//            }
//            cur_p = mystack.top();
//            mystack.pop();
//            if(flag){
//                last = cur_p->val;
//                flag = false;
//            }
//            if(cur_p->val<last){
//                return false;
//            }
//            last = cur_p->val;
//        }
//        return true;
//    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        if(root->left==NULL&&root->right==NULL){
            return true;
        }
        if(root->left!=NULL&&root->right!=NULL){
//            右子树最小值要大于根
            TreeNode* min;
            TreeNode* cur_p = root->right;
            while (cur_p!=NULL){
                min = cur_p;
                cur_p = cur_p->left;
            }
            TreeNode* max;
            TreeNode* cur_q = root->left;
            while (cur_q!=NULL){
                max = cur_q;
                cur_q = cur_q->right;
            }

            return isValidBST(root->left)&&isValidBST(root->right)&&(min->val>root->val)&&(max->val<root->val);
        }
        if(root->left!=NULL){
            TreeNode* max;
            TreeNode* cur_q = root->left;
            while (cur_q!=NULL){
                max = cur_q;
                cur_q = cur_q->right;
            }
            return isValidBST(root->left)&&(max->val<root->val);
        } else{
            TreeNode* min;
            TreeNode* cur_p = root->right;
            while (cur_p!=NULL){
                min = cur_p;
                cur_p = cur_p->left;
            }
            return isValidBST(root->right)&&(min->val>root->val);
        }
    }
};