你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

 

示例 1：

输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2：

输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 3：

输入：nums = [0]
输出：0
 

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-ii

//动态规划，由于是环形，所以可以把头尾的情况分成两种情况进行计算。
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
        return 0;
        int n=nums.size();
        if(n==1)
        return nums[0];
        if(n==2)
        return max(nums[0],nums[1]);
        return max(dp(nums,0,n-2),dp(nums,1,n-1));
    }
    int dp(vector<int>& nums,int l,int r){
        if(nums.empty())
        return 0;
        int d1=nums[l],d2=max(nums[l],nums[l+1]),temp=0;//每轮循环只关注三个位置，然后下一轮整体右移一个位置。
        for(int i=l+2;i<=r;i++){
            temp=d2;//暂存d2，便于移动
            d2=max(d1+nums[i],d2);//下一个位置可由d2或d1过来，通过比较哪个大位置大确定。如果当前d2位置空了，下一轮也绝不会选到这个位置，因为它后面一个位置一定比它大，
            //所以不会连着两个空；要是当前d1空了，那么下一轮选哪个位置都不会有连着两个空。
            d1=temp;
        }
        return d2;
    }
};
