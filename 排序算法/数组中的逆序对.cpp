在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

 

示例 1:

输入: [7,5,6,4]
输出: 5
 

限制：

0 <= 数组长度 <= 50000

链接：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof

//使用归并排序
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size()<=1)
        return 0;
        vector<int> tmp(nums);
        return merge(nums,tmp,0,nums.size()-1);
    }
    int merge(vector<int> &nums,vector<int> &tmp,int l,int r){
        int number=0;
        int mid=(l+r)/2;
        int cnt=0;
        if(r-l>0){
        cnt+=merge(tmp,nums,l,mid)+merge(tmp,nums,mid+1,r);//注意这里交换了tmp和nums，这样每次递归它们对应的位置便可以交替作为nums与tmp，而不需要最后再把tmp复制回nums。
        }
        int st1=l,st2=mid+1,i=l;
        while(st1<=mid&&st2<=r){
            if(nums[st1]>nums[st2]){
                tmp[i++]=nums[st2];
                cnt+=mid-st1+1;//意味着st2位置的数比st1及其之后的都小。
                st2++;
            }
            else{
                tmp[i++]=nums[st1];
                st1++;
            }
        }
        while(st1<=mid)
        tmp[i++]=nums[st1++];
        while(st2<=r)
        tmp[i++]=nums[st2++];
        return cnt;
    }
};
