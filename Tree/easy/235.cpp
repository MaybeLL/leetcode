//
// Created by 78540 on 2020/4/14.
//

#include <stack>
using namespace std;

//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//
//};

class Solution {
public:
    //二叉搜索树的最近公共祖先
    //对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||p==NULL||q==NULL){
            return NULL;
        }
        if(p==q)
            return q;
        if(p->val>q->val){
            if((p->val>=root->val&&q->val<=root->val)){
                return root;
            }
            if(p->val<root->val){
                return lowestCommonAncestor(root->left, p, q);
            }else{
                return lowestCommonAncestor(root->right, p, q);
            }
        } else{
            if((q->val>=root->val&&p->val<=root->val)){
                return root;
            }
            if(q->val<root->val){
                return lowestCommonAncestor(root->left, p, q);
            }else{
                return lowestCommonAncestor(root->right, p, q);
            }
        }
    }

//    //是祖先则包含。
//    bool isancestoer(TreeNode* root, TreeNode* p, TreeNode* q){
//        if(root==NULL){
//            return false;
//        }
//        bool findp= false;
//        bool findq = false;
//        stack<TreeNode*> mystack;
//        TreeNode* _p = root;
//        while(_p!=NULL||!mystack.empty()){
//            while (_p!=NULL){
//                mystack.push(_p);
//                _p = _p->left;
//            }
//            //出栈访问
//            _p = mystack.top();
//            if(_p==p){
//                findp = true;
//            }
//            if(_p==q){
//                findq = true;
//            }
//            if(findp&&findq)
//                break;
//            //转向右边
//            _p = _p->right;
//        }
//
//        return findp&&findq;
//    }
};