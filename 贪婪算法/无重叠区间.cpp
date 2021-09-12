给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
示例 1:

输入: [ [1,2], [2,3], [3,4], [1,3] ]

输出: 1

解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:

输入: [ [1,2], [1,2], [1,2] ]

输出: 2

解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
示例 3:

输入: [ [1,2], [2,3] ]

输出: 0

解释: 你不需要移除任何区间，因为它们已经是无重叠的

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/non-overlapping-intervals

//动态规划
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty())
        return 0;
        sort(intervals.begin(),intervals.end(),[](auto& a,auto& b){
            return a[0]<b[0];
        });
        int n=intervals.size();
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){//遍历每个i，找出左边界为i的情况下最多有几个不重叠的区间。
            for(int j=0;j<i;j++){
                if(intervals[j][1]<=intervals[i][0]){//保证不重叠。
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return n-*max_element(dp.begin(),dp.end());
    }
};
//贪心算法。对于找区间不重合的题，可以尝试先对各区间按左端点或右端点排序。贪心策略是，始终保证左侧的区间和右面的区间都不重叠。所以按照右端点排序，只要找到下一个左端点
//大于当前区间右端点的第一个区间，就能保证两个区间间隔最小，并且右端点增加得最少，即在确定范围内能塞入更多不重叠区间。
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(),intervals.end(),[](auto& a,auto& b){
            return a[1]<b[1];
        });
        int right=intervals[0][1],re=1;//初始把最左侧区间已经找出来了，所以re从1开始。
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=right){
                re++;
                right=intervals[i][1];
            }
        }
        return intervals.size()-re;
    }
};
