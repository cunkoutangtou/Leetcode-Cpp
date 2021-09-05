给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。

返回仅包含 1 的最长（连续）子数组的长度。

 

示例 1：

输入：A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释： 
[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。
示例 2：

输入：A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。
 

提示：

1 <= A.length <= 20000
0 <= K <= A.length
A[i] 为 0 或 1 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-consecutive-ones-iii

//问题可以转化为前缀和，lsum和rum统计在位置l和r处遇到0的累计个数，只要保证lsum>=rsum-k即可将0控制在可接受范围。
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if(nums.empty())
        return 0;
        int lsum=0,rsum=0,l=0,r=0,re=0;;
        while(r<nums.size()){
            rsum+=1-nums[r];//遇到0才会增加。
            while(lsum<rsum-k){
                lsum+=1-nums[l];
                l++;
            }
            re=max(re,r-l+1);
            r++;
        }
        return re;
    }
};
//转化为求一个连续子数组，其中0的个数不大于k。
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if(nums.empty())
        return 0;
        int cnt=0,l=0,r=0,re=0;;
        while(r<nums.size()){
            cnt+=1-nums[r];
            while(cnt>k){
                cnt-=1-nums[l];
                l++;
            }
            re=max(re,r-l+1);
            r++;
        }
        return re;
    }
};
