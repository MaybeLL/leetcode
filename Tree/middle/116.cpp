//
// Created by 78540 on 2020/4/17.
//

#include <vector>
#include <stack>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    //对一个完美二叉树,填充它的每个 next 指针，让这个指针指向其下一个右侧节点,每层最右节点的next==null
//    完全二叉树(Complete Binary Tree)： 每层结点都完全填满，在最后一层上如果不是满的，则只缺少右边的若干结点。
//   (三角形) 完美二叉树(Perfect Binary Tree) 所有的非叶子结点都有两个孩子，所有的叶子结点都在同一层。()

    //思路1:层序遍历+双指针
    //想递归时不应注重输入输出.,考虑内在问题子结构.
    //子结构从右下角递推.
    Node* connect(Node* root) {
        if(!root){
            return NULL;
        }
        root->next = NULL;
        if(root->left&&root->right){
            Node* leftfilled = connect(root->left);
            Node* rightfilled = connect(root->right);
            Node* cur_left =  leftfilled;
            Node* cur_right =  rightfilled;
            while(cur_left&&cur_right){
                cur_left->next = cur_right;
                cur_left = cur_left->right;
                cur_right = cur_right->left;
            }
        }
        return root;
    }
};