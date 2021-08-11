给定一个正整数数组 nums和整数 k ，请找出该数组内乘积小于 k 的连续的子数组的个数。

 

示例 1:

输入: nums = [10,5,2,6], k = 100
输出: 8
解释: 8 个乘积小于 100 的子数组分别为: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于100的子数组。
示例 2:

输入: nums = [1,2,3], k = 0
输出: 0
 

提示: 

1 <= nums.length <= 3 * 104
1 <= nums[i] <= 1000
0 <= k <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ZVAVXX

//滑动窗口，数组老朋友。
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(nums.empty()||k<=1)//输入元素大于等于1，不可能有元素乘积比1小。
        return 0;
        int l=0,r=0,cnt=0,product=nums[0];
        while(l<nums.size()){//使用的统计方式需要l最终和r重合
            while(r<nums.size()&&product<k){//先把窗口拉到最大，r最终停到符合条件的元素的下一个位置。
                r++;
                if(r>=nums.size())
                break;
                product*=nums[r];
            }
            cnt+=r-l;//比如(1,2,3),按一个方向统计，可能结果为(1),(1,2),(1,2,3)，所以连续数组个数和元素个数相同。
            product/=nums[l];
            l++;
        }
        return cnt;
    }
};
