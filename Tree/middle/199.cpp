//
// Created by 78540 on 2020/4/20.
//

//199. 二叉树的右视图

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
    //层序遍历，每层的最后一个节点(用双指针来获得最后一个节点)被记录
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return vector<int>();
        vector<int> res;
//        TreeNode* father = NULL;
        TreeNode* cur = root;
        queue<TreeNode*> nextlevel;
        queue<TreeNode*> curlevel;
        nextlevel.push(root);
        while (!nextlevel.empty()){
            swap(curlevel,nextlevel);
            while (!curlevel.empty()){
//                father = cur;
                cur = curlevel.front();
                curlevel.pop();
                if(cur->left){
                    nextlevel.push(cur->left);
                }
                if(cur->right){
                    nextlevel.push(cur->right);
                }
            }
            res.push_back(cur->val);

        }
        return res;
    }

    //review: 更简单的层序遍历：不需要双队列。
    //层序遍历思想,把每层的最右侧输出即可
//    while (!nodes.empty()) {
//        int size = nodes.size();
//        for (int i = 0; i < size; i++) {
//            pnode = nodes.front();
//            if (i == size - 1)
//                result.push_back(pnode->val);
//            if (pnode->left != NULL)
//                nodes.push(pnode->left);
//            if (pnode->right != NULL)
//                nodes.push(pnode->right);
//            nodes.pop();
//        }
//    }

};