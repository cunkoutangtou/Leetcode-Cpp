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
链接：https://leetcode-cn.com/problems/2VG8Kg

//很多数组题都可以用滑动窗口，并且窗口左端一般应该在当前窗口内数据处理完毕后才移动
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.empty())
        return 0;
        int len=nums.size(),l=0,r=0,mincnt=INT_MAX,sum=0;
        while(r<len){
            sum+=nums[r];
            while(sum>=target){//可能突然加进来一个比较大的数，甚至直接大于target，所以要循环处理完才移动窗口右端。
                mincnt=min(mincnt,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;//每次窗口固定移动1个位置
        }
        if(mincnt==INT_MAX)
        return 0;
        else
        return mincnt;
    }
};
