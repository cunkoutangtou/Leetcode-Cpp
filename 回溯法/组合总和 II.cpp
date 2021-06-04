给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]

链接：https://leetcode-cn.com/problems/combination-sum-ii

//由于组合不能重复，为了将重复元素剔除需要先对数组排序，这样重复的元素挨在一起，第一个元素经历的回溯会包含使用多个重复元素的所有组合，所以回溯完后直接后移到下一个元素值不同的位置即可。
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> re;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        back(candidates,re,target,temp,0);
        return re;
    }
    void back(vector<int>& candidates, vector<vector<int>> &re,int target,vector<int> &temp,int index){
        if(target==0){
            re.push_back(temp);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(target-candidates[i]>=0){
            temp.push_back(candidates[i]);
            back(candidates,re,target-candidates[i],temp,i+1);
            temp.pop_back();
            }
            else 
            return;
            while(i<candidates.size()-1&&candidates[i+1]==candidates[i])
            i++;
        }
    }
};
