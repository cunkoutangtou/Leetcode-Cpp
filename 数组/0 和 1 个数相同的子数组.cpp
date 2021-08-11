给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。

 

示例 1:

输入: nums = [0,1]
输出: 2
说明: [0, 1] 是具有相同数量 0 和 1 的最长连续子数组。
示例 2:

输入: nums = [0,1,0]
输出: 2
说明: [0, 1] (或 [1, 0]) 是具有相同数量 0 和 1 的最长连续子数组。
 

提示：

1 <= nums.length <= 105
nums[i] 不是 0 就是 1
 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/A1NYOS

//使用前缀和，当有条件可以判断窗口右边界到头时可以用滑动窗口，但本题无法判断，因为右边界不能根据当前位置元素是什么来确定边界是否该停止。
//一般有类似前面元素累加直到当前值大于某值时就该停下的这种条件时才该用滑动窗口。
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size()<=1)
        return 0;
        int cnt=0,re=0;
        unordered_map<int,int> m;
        m[0]=-1;//正好1,0平衡时，长度为坐标值-（-1），即+1
        for(int i=0;i<nums.size();i++){
            cnt+=nums[i]?1:-1;//当cnt为正数时代表1多了几个，为负数时代表0多了几个
            if(m.count(cnt))
            re=max(re,i-m[cnt-0]);//本题满足条件时，累加和-前缀=0，即消去前缀中多的1或者0正好1,0平衡
            else//只记录最开始1和0不平衡时当前所处的位置即可，这样能保证长度最大
            m[cnt]=i;
        }
        return re;
    }
};
