//
// Created by 78540 on 2020/4/20.
//

//173. 二叉搜索树迭代器

//实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。
//
//调用 next() 将返回二叉搜索树中的下一个最小的数。
//要求：①next() 和 hasNext() 操作的时间复杂度是 O(1)，并使用 O(h) 内存，其中 h 是树的高度。
//你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 中至少存在一个下一个最小的数。
//

//思路1：初始化时中序遍历，产生一个有序数组。next直接对数组遍历。 （无重复）
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
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
// todo: 报错
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        TreeNode* cur = root;
        stack<TreeNode*> mystack;
        while (cur||!mystack.empty()){
            while (cur){
                mystack.push(cur);
                cur = cur->left;
            }
            cur = mystack.top();
            mystack.pop();
            tree.push_back(cur->val);
            cur = cur->right;
        }
        cur_index = tree.begin()-1;
    }

public:
    vector<int> tree;
    vector<int>::iterator cur_index;
    /** @return the next smallest number */
    int next() {
        cur_index++;
        return *cur_index;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(tree.empty()){
            return false;
        }
        return cur_index +1!=tree.end();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */