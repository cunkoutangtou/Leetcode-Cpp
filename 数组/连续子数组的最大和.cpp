输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

 

示例1:

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 

提示：

1 <= arr.length <= 10^5
-100 <= arr[i] <= 100

链接：https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof

//最大子数组和一定是加一个负数前的和，如果当前累加和已经<0那么就可以切换下一个子数组了，即使累加和清0重新累加。
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        int temp=0,max=INT_MIN;
        for(int i=0;i<nums.size();i++){
            temp+=nums[i];
            if(temp>max)
            max=temp;
            if(temp<0)
            temp=0;
        }
        return max;
    }
};
