给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 

示例 1：



输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9
 

提示：

n == height.length
0 <= n <= 3 * 104
0 <= height[i] <= 105

链接：https://leetcode-cn.com/problems/trapping-rain-water

//使用动态规划记录每个位置(包括该位置)左边最最高的高度，还有右边最高的高度，在该位置作差再减去此处的height[i]即可。
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),re=0;
        if(n==0)
        return 0;
        int left[n],right[n];
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        for(int i=1;i<n-1;i++){
            re+=min(left[i],right[i])-height[i];
        }
        return re;
    }
};
//使用单调递减栈，不断将栈数组序号按顺序放入栈中，当遇到数组值大于栈顶索引对应的数组值时计算。
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),re=0;
        if(n==0)
        return 0;
        stack<int> sta;
        for(int i=0;i<n;i++){
            while(!sta.empty()&&height[i]>height[sta.top()]){
                int middle=sta.top();//每次拿一个位置进行计算
                sta.pop();
                if(sta.empty())
                break;
                int left=sta.top();
                int wide=i-left-1;
                int h=min(height[left],height[i])-height[middle];//left和i为左右边界，height[middle]为当前要计算位置的高度。
                re+=h*wide;
            }
            sta.push(i);
        }
        return re;
    }
};
//双指针法，只要右面最高高度大于左面最高高度左面一定就能蓄水，反之亦然，所以只要不断判断左右两侧最高高度，然后让矮的那一面的最高高度减去当前位置的高度即可。
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),re=0;
        if(n==0)
        return 0;
        int left=0,right=n-1;
        int leftmax=0,rightmax=0;
        while(left<right){
            leftmax=max(leftmax,height[left]);
            rightmax=max(rightmax,height[right]);
            if(leftmax<rightmax){
                re+=leftmax-height[left];
                left++;
            }
            else{
                re+=rightmax-height[right];
                right--;
            }
        }
        return re;
    }
};
