输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 

限制：

1 <= target <= 10^5

链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof

//双指针法，固定序列的左右两端，不断尝试，小了右指针右移，大了左指针右移。。
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if(target<3)
        return {{target}};
        int l=1,r=2;
        vector<vector<int>> re;
        auto add=[&](int l,int r){
            vector<int> temp;
            for(int i=l;i<=r;i++)
            temp.push_back(i);
            re.push_back(temp);
        };
        int sum=l+r;
        while(l<(target+1)/2){//注意使用while时要注意判断条件会不会永远为真，这里要保证l一定会增加。
            if(sum==target){
                add(l,r);
                r++;
                sum+=r;
            }
            else if(sum>target){
                sum-=l;
                l++;
            }
            else{
                r++;
                sum+=r;
            }
        }
        return re;
    }
};
