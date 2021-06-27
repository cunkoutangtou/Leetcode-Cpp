给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

 

示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：

输入：nums = [1]
输出：[[1]]
 

提示：

1 <= nums.length <= 6
-10 <= nums[i] <= 10
nums 中的所有整数 互不相同

链接：https://leetcode-cn.com/problems/permutations

//回溯法，定住一个位置尝试之后的所有排列，然后依次和后面的交换（即尝试该位置是后面的各个数字的情况）。
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()<=1)
        return {{nums}};
        vector<vector<int>> re;
        per(re,nums,0);
        return re;
    }
    void per(vector<vector<int>> &re,vector<int>& nums,int index){
        if(index==nums.size()-1){
            re.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            per(re,nums,index+1);
            swap(nums[index],nums[i]);
        }
    }
};
