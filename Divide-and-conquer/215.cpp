//
// Created by 78540 on 2020/4/20.
//

//215. 数组中的第K个最大元素
//假设k总是有效的

#include <vector>
#include <stack>
#include <queue>
using namespace std;

//class Solution {
//public:
//    //思路1：快排
//
//    int findKthLargest(vector<int>& nums, int k) {
//        quicksort(nums,0,nums.size()-1);
//        return nums[nums.size()-k];
//    }
//
//    void quicksort(vector<int>& arr,int left,int right){
//        if(left>=right)
//            return;
//        int key = arr[left];
//        int i = left;
//        int j = right;
//        while(i<j){
//            while(i<j&&arr[j]>key){
//                j--;
//            }
//            if(i<j){
//                arr[i++] = arr[j];
//            }
//            while (i<j&&arr[i]<key){
//                i++;
//            }
//            if(i<j){
//                arr[j--] = arr[i];
//            }
//        }
//        arr[i]=key; // i==j
//        quicksort(arr,left,i-1);
//        quicksort(arr,i+1,right);
//    }
//};

//思路2：堆排序
class Solution {
public: int size; //（堆的大小,k）
private:
    //堆化（小顶堆）   父节点index，其左、右子节点: 2 * index +1 ,2*index+2s
    void heapify(vector<int>& nums,int index){
        int left = 2 * index + 1, min_index ; //左结点; 父左右值最小的
        while(left < size){
            min_index = left+1 < size && nums[left + 1] < nums[left] ? left + 1 : left;
            if(nums[index]<nums[min_index]){
                min_index = index;
                return;    // 父结点最小，无需交换，堆化结束
            }
            this->swap(nums[index],nums[min_index]);
            index = min_index;    //层层判断
            left = 2 * index + 1;
        }
    }
    void swap(int &a, int &b){
        int t = a; a = b; b = t;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = nums.size();   size = k;
        int i;
        //先用前k个元素建大小为size的堆， 从最后一个非叶子节点开始 （下标：size / 2 - 1）;
        for(i = size/2-1; i>=0;i--)
            this->heapify(nums,i);
        // 对剩下的元素，若大于堆顶， 则和堆顶交换，小顶堆调整顺序
        for(i = size; i < l ;i++){
            if(nums[i] > nums[0]){
                this->swap(nums[i],nums[0]);
                this->heapify(nums,0);
            }
        }
        return nums[0];
    }
};