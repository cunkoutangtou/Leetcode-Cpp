给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]
 

提示：

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 是一个非递减数组
-109 <= target <= 109

链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array

//通过二分法找到目标点，再向其两端寻找端点，需要注意索引别超出边界
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int mid=0;
        vector<int> re;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==target)
            break;
            else if(nums[mid]>target)
            right=mid-1;
            else
            left=mid+1;
        }
        if(left>right)
        return {-1,-1};
        left=mid-1;
        right=mid+1;
        while(left>=0&&nums[left]==target){
            left--;
        }
        while(right<nums.size()&&nums[right]==target){
            right++;
        }
        re.push_back(left+1);
        re.push_back(right-1);
        return re;
    }
};
//二分法变种，当遇到目标值时不返回，而是继续寻找直到到其边界，利用判断条件中的'='可以控制向哪个方向寻找边界。
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        if(left>right)
        return {-1,-1};
        int mid=0;
        vector<int> re;
        int first=0,last=0;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]>=target){
            right=mid-1;
            first=mid;
            }
            else
            left=mid+1;
        }
        if(nums[first]!=target)
        first=-1;
        left=0;
        right=nums.size()-1;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]>target)
            right=mid-1;
            else{
            last=mid;
            left=mid+1;
            }
        }
        if(nums[last]!=target)
        last=-1;
        re.push_back(first);
        re.push_back(last);
        return re;
    }
};
