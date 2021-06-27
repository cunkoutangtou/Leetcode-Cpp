给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。


示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

提示：

1 <= nums.length <= 8
-10 <= nums[i] <= 10

链接：https://leetcode-cn.com/problems/permutations-ii

//回溯法，每个位置上某个数字只应该出现一次，需要剪枝，用一个数组记录一下该数字是否出现过即可。
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
        int sign[20]{0};
        for(int i=index;i<nums.size();i++){
            if(sign[nums[i]+10]==1)
            continue;
            sign[nums[i]+10]=1;
            swap(nums[index],nums[i]);
            per(re,nums,index+1);
            swap(nums[index],nums[i]);
        }
    }
};
