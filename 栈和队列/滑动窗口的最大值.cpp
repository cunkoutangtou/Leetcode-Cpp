给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

提示：

你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。

链接：https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof

//适用双端队列保证队首始终为窗口内的最大值。
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()||k==0)
        return {};
        deque<int> q;
        vector<int> re;
        for(int i=0;i<nums.size();i++){
            while(!q.empty()&&nums[i]>nums[q.back()])//检测要插入元素是否比队内元素大，是就弹出
            q.pop_back();
            q.push_back(i);
            if(i+1-k>=0){//从第一个窗口中的最后一个元素开始判断。
                re.push_back(nums[q.front()]);
                if(q.front()<=i+1-k)//若当前元素已经在窗口内的最左侧，则弹出
                q.pop_front();
            }
        }
        return re;
    }
};
