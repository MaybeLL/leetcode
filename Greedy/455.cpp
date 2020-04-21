//
// Created by 78540 on 2020/4/20.
//
#include <vector>
using namespace std;

//455. 分发饼干
//假设你是一位很棒的家长，想要给你的孩子们一些小饼干。
// 但是，每个孩子最多只能给一块饼干。
// 对每个孩子 i ，都有一个胃口值 gi ，这是能让孩子们满足胃口的饼干的最小尺寸；
// 并且每块饼干 j ，都有一个尺寸 sj 。
// 如果 sj >= gi ，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。
// 你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。


class Solution {
public:
    //最佳适应
    int findContentChildren(vector<int>& g, vector<int>& s) {
        quicksort(g,0,g.size()-1);
        quicksort(s,0,s.size()-1);
        for(int i =0;i<g.size();i++){

        }
    }

    void quicksort(vector<int>& arr,int left, int right){
        if(left<right){
            int key = arr[left];
            int i = left;
            int j = right;
            while(i<j){
                while (i<j&&arr[j]>key){
                    j--;
                }
                if(i<j){
                    arr[i++] = arr[j];
                }
                while(i<j&&arr[i]<key){
                    i++;
                }
                if(i<j){
                    arr[j--] = arr[i];
                }
            }
            arr[j] = key;
            quicksort(arr,left,i-1);
            quicksort(arr,i+1,right);
        }
    }
};