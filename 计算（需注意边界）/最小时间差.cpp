给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。

 

示例 1：

输入：timePoints = ["23:59","00:00"]
输出：1
示例 2：

输入：timePoints = ["00:00","23:59","00:00"]
输出：0
 

提示：

2 <= timePoints <= 2 * 104
timePoints[i] 格式为 "HH:MM"
 

注意：本题与主站 539 题相同： https://leetcode-cn.com/problems/minimum-time-difference/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/569nqc

//先转换为分钟再进行比较。
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> min;
        for(int i=0;i<timePoints.size();i++){//转换为分钟
            int j=0,cur=0;
            while(timePoints[i][j]!=':'){
                cur*=10;
                cur+=timePoints[i][j]-'0';
                j++;
            }
            min.push_back(cur*60);
            j++;
            cur=0;
            while(j<timePoints[i].size()){
                cur*=10;
                cur+=timePoints[i][j]-'0';
                j++;
            }
            min[i]+=cur;
        }
        sort(min.begin(),min.end());
        int re=INT_MAX;
        int n=min.size();
        for(int i=0;i<n-1;i++){
            int t=min[i+1]-min[i];//计算间距。
            t=t>720?1440-t:t;//将一周分为0~719和720~1439两部分，如果t>半个周的范围，则取另一个半周的距离，即较小的那个距离。
            re=t<re?t:re;
        }
        int t=min[n-1]-min[0];//额外比一次最后一个元素和第一个元素间的距离。
        t=t>720?1440-t:t;
        re=t<re?t:re;
        return re;
    }
};
