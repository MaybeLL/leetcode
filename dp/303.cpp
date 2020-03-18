//
// Created by jixie on 2020/3/17.
//

//给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
//
//示例：
//
//给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()
//
//sumRange(0, 2) -> 1
//sumRange(2, 5) -> -1
//sumRange(0, 5) -> -3
//说明:
//
//你可以假设数组不可变。
//会多次调用 sumRange 方法。

#include <map>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        data = nums;
    }

    int sumRange(int i, int j) {
        _index index(i, j);
        if (!sumranges.count(index)) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += data[k];
            }
            sumranges.insert(map<_index, int>::value_type(index, sum));
            return sum;
        } else {
            return sumranges[index];
        }
    }

private:
    vector<int> data;
    typedef pair<int, int> _index;
    map<_index, int> sumranges;

//public:
//    NumArray(vector<int>& nums) {
//        int psum=0;
//        for(int i=0;i<nums.size();i++){
//            psum+=nums[i];
//            sum.push_back(psum);
//        }
//    }
//
//    int sumRange(int i, int j) {
//        if(i==0){
//            return sum[j];
//        } else{
//            return sum[j]-sum[i-1];
//        }
//    }
//
//private:
//    vector<int> sum;

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */


