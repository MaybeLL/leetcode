//
// Created by 78540 on 2020/4/16.
//

//105. 从前序与中序遍历序列构造二叉树
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
//    思路:根据前序遍历来确定根,对中序划分左右子树,进行递归
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //递归出口
        if(preorder.size()==0){
            return NULL;
        }
        if(preorder.size()==1){
            return new TreeNode(preorder[0]);
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int i;
        for(i = 0;i<inorder.size();i++){
            if(preorder[0]==inorder[i])
                break;
        }
        //左子树为0到i-1个元素,右子树为i+1到end
        if(i>0&&i<preorder.size()-1){
            vector<int> lpre(preorder.begin()+1,preorder.begin()+i+1);
            vector<int> lin(inorder.begin(),inorder.begin()+i);
            root->left = buildTree(lpre,lin);

            vector<int> rpre(preorder.begin()+1+i,preorder.end());
            vector<int> rin(inorder.begin()+i+1,inorder.end());
            root->right = buildTree(rpre,rin);
        }
        if(i==0){
            vector<int> rpre(preorder.begin()+1+i,preorder.end());
            vector<int> rin(inorder.begin()+i+1,inorder.end());
            root->right = buildTree(rpre,rin);
        } else{
            vector<int> lpre(preorder.begin()+1,preorder.begin()+i+1);
            vector<int> lin(inorder.begin(),inorder.begin()+i);
            root->left = buildTree(lpre,lin);
        }
        return root;
    }


};