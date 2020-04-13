//
// Created by 78540 on 2020/3/23.
//
//[1,2,-3,0,4,0,-6,-1,3]
#include <vector>

using namespace std;

//设p[i]是长度为i的最大乘积
//“由于存在负数，那么会导致最大的变最小的，最小的变最大的。因此还需要维护当前最小值imin。”
class Solution {
public:
    int maxProduct(vector<int> nums) {
        int max = Integer.MIN_VALUE, imax = 1, imin = 1;
        for(int i=0; i<nums.length; i++){
            if(nums[i] < 0){
                int tmp = imax;
                imax = imin;
                imin = tmp;
            }
            imax = max(imax*nums[i], nums[i]);
            imin = min(imin*nums[i], nums[i]);

            max = max(max, imax);
        }
        return max;
    }
}

