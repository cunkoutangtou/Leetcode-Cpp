一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

 

示例 1：

输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
示例 2：

输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]
 

限制：

2 <= nums.length <= 10000

链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof

//分组，由于相同的数异或为0，不同的数异或一定有一位为1，根据整个数组异或结果最低位为1的位置对数组分组，则两个不同的只有一个的数字会被分到两组中，再次对两组分别一一异或即可。
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        if(nums.empty())
        return {};
        int a=0;
        for(auto b:nums)
        a^=b;
        int f1=a&-a;//一个数和它的相反数异或结果能得到最低位为1的位置。
        vector<int> re(2,0);
        for(auto b:nums){
            if(b&f1)
            re[1]^=b;
            else
            re[0]^=b;
        }
        return re;
    }
};
