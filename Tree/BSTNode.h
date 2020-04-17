//
// Created by 78540 on 2020/4/13.
//

#ifndef LEETCODE_BSTNODE_H
#define LEETCODE_BSTNODE_H
template <class T>
class BSTNode{
public:
    T key;            // 关键字(键值)
    BSTNode *left;    // 左孩子
    BSTNode *right;    // 右孩子
    BSTNode *parent;// 父结点

    BSTNode(T value, BSTNode *p, BSTNode *l, BSTNode *r):
            key(value),parent(),left(l),right(r) {}
};

#endif //LEETCODE_BSTNODE_H
