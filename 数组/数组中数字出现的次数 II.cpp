在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

 

示例 1：

输入：nums = [3,4,3,3]
输出：4
示例 2：

输入：nums = [9,1,7,9,7,9,7]
输出：1
 

限制：

1 <= nums.length <= 10000
1 <= nums[i] < 2^31

链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof

//用32个数保存nums中每一个数每一位的累加和，然后模3即可。
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty())
        return 0;
        int re[32]{0},bit;
        for(auto a:nums){
            bit=1;
            for(int j=31;j>=0;j--){
                if(bit&a)
                re[j]++;
                if(bit==INT_MIN)
                break;
                bit<<=1;
            }
        }
        int r=0;
        for(int i=0;i<=31;i++){
            r<<=1;
            r+=re[i]%3;
        }
        return r;
    }
};
