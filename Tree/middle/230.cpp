//
// Created by 78540 on 2020/4/20.
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
    //说明：
    //你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
//    进阶：
//    如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
//    哈希表存
//二叉搜索树：有序性，用中序遍历。
    int kthSmallest(TreeNode* root, int k) {
        vector<int> tree;
        TreeNode* cur = root;
        stack<TreeNode*> mystack;
        while(cur||!mystack.empty()){
            while(cur){
                mystack.push(cur);
                cur = cur->left;
            }
            cur = mystack.top();
            mystack.pop();
            tree.push_back(cur->val);
            cur = cur->right;
        }

        return tree[k-1];
    }
};