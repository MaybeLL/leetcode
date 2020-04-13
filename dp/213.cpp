//
// Created by 78540 on 2020/3/24.
//
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        vector<int> money(n,0);
        money[0]=nums[0];
        money[1]=max(nums[0],nums[1]);
        for( int i =2;i<=n-2;i++){
            money[i] = max(money[i-1],money[i-2]+nums[i]);
        }
        int res1 = money[n-2];
        money[1] = nums[1];
        money[2] = max(nums[1],nums[2]);
        for( int i =3;i<=n-1;i++){
            money[i] = max(money[i-1],money[i-2]+nums[i]);
        }
        int res2 = money[n-1];
        return max(res1,res2);
    }
};