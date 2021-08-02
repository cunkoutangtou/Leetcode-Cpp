从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

 

示例 1:

输入: [1,2,3,4,5]
输出: True
 

示例 2:

输入: [0,0,1,2,5]
输出: True
 

限制：

数组长度为 5 

数组的数取值为 [0, 13] .

链接：https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof

//在题目要求长度固定时，nlogn和logn的区别不大。先排序，然后判断特殊情况即可。
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        if(nums.size()!=5)
        return false;
        sort(nums.begin(),nums.end());
        int temp=0,king=0;
        for(int i=0;i<nums.size();i++){
            if(!nums[i])
            king++;
            else{
                if(temp==0){//在一个数不为0后记录下来
                    temp=nums[i];
                    continue;
                }
                if(nums[i]==temp)//有对子
                return false;
                if(nums[i]-temp!=1)//缺数
                king-=nums[i]-temp-1;//缺多少补多少
                if(king<0)
                return false;
                temp=nums[i];
            }
        }
        return true;
    }
};
//记录最大值和最小值，它们之间的差小于5即可。
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        if(nums.size()!=5)
        return false;
        int sign[14]{0};//用来判断是否有对子
        int m=INT_MIN,mi=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
            continue;
            m=max(m,nums[i]);
            mi=min(mi,nums[i]);
            if(sign[nums[i]])
            return false;
            sign[nums[i]]=1;     
        }     
        return m-mi<5;
    }
};
