把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

示例 1：

输入：[3,4,5,1,2]
输出：1
示例 2：

输入：[2,2,2,0,1]
输出：0

链接：https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof

//最小值一定在右半数组，所以不能像普通二分法一样在舍弃右半边时把m位也舍弃。
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l=0,r=numbers.size()-1;
        while(l<r){
            int m=(l+r)>>1;
            if(numbers[m]<numbers[r])//在右半数组
            r=m;
            else if(numbers[m]>numbers[r])//在左半数组
            l=m+1;
            else//不确定，即类似[1,1,1,0,1]这种情况
            r--;
        }
        return numbers[l];
    }
};
