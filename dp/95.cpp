//
// Created by 78540 on 2020/3/20.
//

//95. 不同的二叉搜索树 II

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
using namespace std;

//递归法
class Solution {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==1){
            TreeNode* head = &TreeNode(1);
        }
        for(int i =1;i<n+1;i++){
            TreeNode* head = &TreeNode(i);
//            遍历所有左子树结构vector：
//                将其插入head的左边
//                遍历所有右子树结构vector：
//                   将其插入head的右边
//                   将head插入generateTrees[]
        }
        if()


    }
};