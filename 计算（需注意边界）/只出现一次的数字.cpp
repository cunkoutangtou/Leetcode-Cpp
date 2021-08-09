给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

 

示例 1：

输入：nums = [2,2,3,2]
输出：3
示例 2：

输入：nums = [0,1,0,1,0,1,100]
输出：100
 

提示：

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次
 

进阶：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

链接：https://leetcode-cn.com/problems/WGki4K

//用32位数组存储每个数字的各位累加和，有三个一样的数字则对应位置%3一定为0，不为0则代表一个不一样的数字在该位有值。
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty())
        return 0;
        int temp[32]{0};
        for(int i=0;i<nums.size();i++){
            int t=nums[i],b=1,j=0;
            while(1){
                if(t&b)//注意2&2=2，不是1！
                temp[j]++;
                j++;
                if(j>=32)
                break;
                b<<=1;
            }
        }
        int re=0;
        for(int i=31;i>=0;i--){
            temp[i]%=3;
            re<<=1;
            re+=temp[i];
        }
        return re;
    }
};
//不使用额外数组，按位计算，每次循环计算好一个位。
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty())
        return 0;
        int re=0;
        for(int i=31;i>=0;i--){
            int b=1<<i,cur=0;
            for(auto a:nums){
                if(a&b)
                cur++;
            }
            re<<=1;
            re+=cur%3;
        }
        return re;
    }
};
