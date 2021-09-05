给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :

数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-sum-equals-k

//两个位置的前缀和之差本质上就是取了一段连续数组的和，使用哈希表记录某个前缀和值出现的次数，每当遇到出现过的前缀和，代表出现了一段新的连续数组，其和为k。
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.empty())
        return 0;
        int su=0,re=0;
        unordered_map<int,int> m;//m中记录的的是出现某个前缀和值的次数，每次都代表一个不同的位置，当前位置的前缀和与它们分别相减都能得到一段满足题目要求的连续数组。
        m[0]=1;//代表第一次遇见的前缀和正好等于k时的情况。      
        for(auto a:nums){
            su+=a;
            if(m.count(su-k))
            re+=m[su-k];
            m[su]++;
        }
        return re;
    }
};
