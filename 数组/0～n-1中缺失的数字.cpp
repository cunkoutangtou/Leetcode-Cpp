一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

 

示例 1:

输入: [0,1,3]
输出: 2
示例 2:

输入: [0,1,2,3,4,5,6,7,9]
输出: 8
 

限制：

1 <= 数组长度 <= 10000

链接：https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof

//找到二分法中让左右边界移动的条件即可，本题不存在nums[mid]<mid的情况，所以直接使用了==。
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==mid)
            left=mid+1; 
            else
            right=mid-1;        
        }
        return left;
    }
};
