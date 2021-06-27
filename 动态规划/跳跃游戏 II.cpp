给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

假设你总是可以到达数组的最后一个位置。

 

示例 1:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
示例 2:

输入: [2,3,0,1,4]
输出: 2
 

提示:

1 <= nums.length <= 1000
0 <= nums[i] <= 105

链接：https://leetcode-cn.com/problems/jump-game-ii

//动态规划,从最后面找，dp中存的是该位置到最后一位的最小步数，需要遍历在该位步长范围内的所有可能到达的位置来找到到最后一位最小的步数。
class Solution {
public:
    int jump(vector<int>& nums) {
        int l=nums.size();
        int dp[l];
        for(int i=0;i<l-1;i++)
        dp[i]=l;
        dp[l-1]=0;
        for(int i=l-2;i>=0;i--){
            for(int step=1;step<=nums[i];step++){
                if(i+step<l-1)
                dp[i]=min(dp[i],1+dp[i+step]);
                else{
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[0];
    }
};
//贪婪算法，正向一次遍历，i代表左边界，rb代表右边界，在i和rb重合前，找到下一个尽可能远的右边界，直到右边界的范围包含了最右边的位置。
class Solution {
public:
    int jump(vector<int>& nums) {
        int rb=0,step=0,maxp=0,l=nums.size();        
        for(int i=0;i<l-1;i++){
            maxp=max(i+nums[i],maxp);
            if(maxp>=l-1)
            return ++step;
            if(i==rb){
                rb=maxp;
                step++;
            }
        }
        return step;
    }
};
