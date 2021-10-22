给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
 
示例 1：

输入：[3,2,3]
输出：[3]
示例 2：

输入：nums = [1]
输出：[1]
示例 3：

输入：[1,1,1,3,3,2,2,2]
输出：[1,2]
 

提示：

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 

进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element-ii

//由于个数大于n/3的元素最多只有两个，所以可以用ele1和ele2记录当前元素，vote1和vote2判断元素有效性，先找到两个不同的元素，找到第三个不同的则同时抵消。
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> re;
        int vote1=0,vote2=0,ele1=0,ele2=0;
        for(int a:nums){
            if(vote1&&a==ele1)
            vote1++;
            else if(vote2&&a==ele2)
            vote2++;
            else if(vote1==0){//第一个元素抵消完了
                vote1++;
                ele1=a;
            }
            else if(vote2==0){//第二个元素抵消完了
                vote2++;
                ele2=a;
            }else{//同时遇见三个不同元素才会同时抵消
                vote1--;
                vote2--;
            }
        }
        int cnt1=0,cnt2=0;
        for(int a:nums){//判断最后剩下的元素ele1和ele2满不满足元素个数的要求
            if(vote1&&a==ele1)
            cnt1++;
            if(vote2&&a==ele2)
            cnt2++;
        }
        if(cnt1>n/3)
        re.push_back(ele1);
        if(cnt2>n/3)
        re.push_back(ele2);
        return re;
    }
};
