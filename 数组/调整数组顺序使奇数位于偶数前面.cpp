输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

 
示例：

输入：nums = [1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。
 

提示：

0 <= nums.length <= 50000
1 <= nums[i] <= 10000

链接：https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof

//双指针法1，快慢指针
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.size()<2)
        return nums;
        int fast=0,slow=0;
        while(fast<nums.size()){
            if(nums[fast]&1){
                swap(nums[fast],nums[slow]);
                slow++;
            }
            fast++;
        }
        return nums;
    }
};
//双指针法2，头尾指针
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.size()<2)
        return nums;
        int tail=nums.size()-1,head=0;
        while(head<tail){
            while(head<tail&&!(nums[tail]&1))tail--;
            while(head<tail&&nums[head]&1)head++;
            swap(nums[head],nums[tail]);
        }
        return nums;
    }
};
