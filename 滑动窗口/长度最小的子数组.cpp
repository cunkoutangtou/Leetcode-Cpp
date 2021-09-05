给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

 

示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
示例 2：

输入：target = 4, nums = [1,4,4]
输出：1
示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
 

提示：

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum

//滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.empty())
        return 0;
        int mi=INT_MAX,sum=0;
        for(int l=0,r=0;r<nums.size();r++){
            sum+=nums[r];
            while(sum>=target){
                mi=min(mi,r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        return mi==INT_MAX?0:mi;
    }
};
//前缀和加二分查找，在数组全为正的情况下，前缀和数组递增则可二分查找。
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.empty())
        return 0;
        int mi=INT_MAX;
        vector<int> sum(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++){//i代表当前有几个数的累加。
            sum[i]=sum[i-1]+nums[i-1];
        }
        for(int i=1;i<=nums.size();i++){//尝试寻找目标值加当前累加和能否在之后的累加和数组内找到相等的值。
            int temp=target+sum[i-1];
            int j=bs(sum,temp);
            if(j)
            mi=min(mi,j-(i-1));
        }
        return mi==INT_MAX?0:mi;
    }
    int bs(vector<int>& nums,int a){
        int l=0,r=nums.size()-1;
        while(l<=r){
            int middle=(l+r)>>1;
            if(nums[middle]>=a&&middle>0&&nums[middle-1]<a)//找到大于等于和小于a的分界线处的值。
                return middle;
            else if(nums[middle]<a)
            l=middle+1;
            else
            r=middle-1;
        }
        return 0;
    }
};
