给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a ，b ，c ，使得 a + b + c = 0 ？请找出所有和为 0 且 不重复 的三元组。

 

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
示例 2：

输入：nums = []
输出：[]
示例 3：

输入：nums = [0]
输出：[]
 

提示：

0 <= nums.length <= 3000
-105 <= nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/1fGaJU

//固定一个数，移动剩余的两个数。
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
        return {};
        vector<vector<int>> re;
        sort(nums.begin(),nums.end());//不排序没办法避免结果中的重复答案
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1])//避免第一个数重复
            continue;
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(j>i+1&&nums[j]==nums[j-1]){//避免第二个数重复
                    j++;
                    continue;
                }
                int t=nums[i]+nums[j]+nums[k];
                if(t==0){
                re.push_back({nums[i],nums[j],nums[k]});
                j++;
                }
                else if(t<0)
                j++;
                else
                k--;
            }
        }
        return re;
    }
};
