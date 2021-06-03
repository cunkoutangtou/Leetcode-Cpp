给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
示例 2：

输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 

提示：

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate 中的每个元素都是独一无二的。
1 <= target <= 500

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum

//回溯法，每次向下可以看成继续使用当前候选数，还是跳过，递归过程是个二叉树。
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> re;
        vector<int> temp;
        recall(re,temp,candidates,target,0);
        return re;
    }
    void recall(vector<vector<int>> &re,vector<int> &temp,vector<int> &candidates,int target,int ind){
        if(target<0||ind==candidates.size())
        return;
        if(target==0){
        re.push_back(temp);
        return;
        }
        recall(re,temp,candidates,target,ind+1);//跳过
        if(target-candidates[ind]>=0){//剪枝，减少不必要的回溯
        temp.push_back(candidates[ind]);
        recall(re,temp,candidates,target-candidates[ind],ind);
        temp.pop_back();
        }
    }
};
