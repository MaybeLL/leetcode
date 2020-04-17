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
    //一般二叉树
    //思路:层序遍历+双指针
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        if(!root->left&&!root->right){
            root->next = NULL;
            return root;
        }
        queue<Node*> curlevel;
        queue<Node*> nextlevel;

        Node* cur = root;
        nextlevel.push(cur);
        while(!nextlevel.empty()){
            Node* father = NULL;
            swap(curlevel,nextlevel);
            while(!curlevel.empty()){
                cur = curlevel.front();
                curlevel.pop();
                if(father){
                    father->next = cur;
                }
                if(cur->left){
                    nextlevel.push(cur->left);
                }
                if(cur->right){
                    nextlevel.push(cur->right);
                }
                father = cur;
            }
            father->next = NULL;

        }
        return root;

    }
};

