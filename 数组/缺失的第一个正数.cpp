给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 

示例 1：

输入：nums = [1,2,0]
输出：3
示例 2：

输入：nums = [3,4,-1,1]
输出：2
示例 3：

输入：nums = [7,8,9,11,12]
输出：1
 

提示：

1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1


链接：https://leetcode-cn.com/problems/first-missing-positive

//思想是n个数的数组其中大小在1~n的数一定都有位置可以满足i=nums[i]，先将负数变为n+1，再将nums[i]变为-abs(nums[i])，代表数组中有这个数，最后数组中的第一个正数就是缺的最小正整数。
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int &a:nums){
            if(a<=0)
            a=n+1;
        }
        for(int &a:nums){
            int b=abs(a);
            if(b<=n)
            nums[b-1]=-abs(nums[b-1]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0)
            return i+1;
        }
        return n+1;
    }
};
//另一种思路，不断将nums[i]放到他应该在的位置nums[nums[i]-1]，最后找到第一个坐标与数组的值不符的，该坐标就是缺的整数。
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]>0&&nums[i]<=n&&nums[nums[i]-1]!=nums[i])
            swap(nums[nums[i]-1],nums[i]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)
            return i+1;
        }
        return n+1;
    }
};
