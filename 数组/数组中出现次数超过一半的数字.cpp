数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

 

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1:

输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2
 

限制：

1 <= 数组长度 <= 50000


链接：https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof

//遇到相同数字cnt++，不同数字cnt--，cnt=0时改变当前数字并cnt=0；
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty())
        return -1;
        if(nums.size()==1)
        return nums[0];
        int cnt=1,re=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==re){
                cnt++;
            }
            else{
                cnt--;
                if(!cnt){
                re=nums[i];
                cnt=1;
                }
            }
        }
        int count=0;
        for(auto a:nums){
            if(a==re);
            count++;
        } 
        return count>nums.size()/2?re:-1;
    }
};
