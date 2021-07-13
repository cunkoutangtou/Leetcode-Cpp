统计一个数字在排序数组中出现的次数。

 

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
 

限制：

0 <= 数组长度 <= 50000

链接：https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof

//二分法查找target位置，找到后从该位置向左右一个一个找左右边界。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
        return 0;
        int left=0,right=nums.size()-1;
        while(left<right){//不取等号可以保证left和right不会出nums的边界。
            int mid=(left+right)/2;
            if(nums[mid]<target)
            left=mid+1;
            else if(nums[mid]>target)
            right=mid-1;
            else{
                int cnt=1;
                left=mid-1;
                right=mid+1;
                while(left>=0&&nums[left]==target){
                    cnt++;
                    left--;
                }
                while(right<nums.size()&&nums[right]==target){
                    cnt++;
                    right++;
                }
                return cnt;
            }
        }
        if(nums[left]==target)
        return 1;
        else
        return 0;
    }
};
//使left最终停在target的右边第一个位置，所以找到target与target-1的右边界即可。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
        return 0;
        return findEdge(nums,target)-findEdge(nums,target-1);
    }
    int findEdge(vector<int> &nums,int target){
        int left=0,right=nums.size()-1;
        while(left<=right){//这里不取等号的话无法判断最终left停在target右边界处还是右边界加1处。
            int mid=(left+right)/2;
            if(nums[mid]>target)
            right=mid-1;
            else
            left=mid+1;
        }
        return left;
    }
};
