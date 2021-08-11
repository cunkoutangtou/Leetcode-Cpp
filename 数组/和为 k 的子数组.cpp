给定一个整数数组和一个整数 k ，请找到该数组中和为 k 的连续子数组的个数。

 

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2
解释: 此题 [1,1] 与 [1,1] 为两种不同的情况
示例 2 :

输入:nums = [1,2,3], k = 3
输出: 2
 

提示:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/QTMn0o

//由于数组是整数数组，可能有负数，不能用滑动窗口，所以使用前缀和。
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.empty())
        return 0;
        unordered_map<int,int> m;//m中存储前缀和
        m[0]=1;//某个元素正好等于k的情况
        int sum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];//计算累计的和，并最后作为前缀存储进m
            if(m.count(sum-k))//累计和-前缀=k的话
            cnt+=m[sum-k];//计数加上有多少个和相同的前缀
            m[sum]++;//当前累加和成为下一个累加和的前缀
        }
        return cnt;
    }
};
