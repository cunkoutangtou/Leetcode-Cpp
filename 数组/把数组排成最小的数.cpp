输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

 

示例 1:

输入: [10,2]
输出: "102"
示例 2:

输入: [3,30,34,5,9]
输出: "3033459"
 

提示:

0 < nums.length <= 100
说明:

输出结果可能非常大，所以你需要返回一个字符串而不是整数
拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0

链接：https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof

//将所有数字转换成字符串然后排序输出即可。
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> vs(nums.size());
        for(int i=0;i<nums.size();i++)
        vs[i]=i2s(nums[i]);
        sort(vs.begin(),vs.end(),[](string &x,string &y){return x+y<y+x;});
        string re="";
        for(auto &a:vs)
        re+=a;
        return re;
    }
    string i2s(int n){
        if(n==0)
        return "0";
        string s;
        while(n){
            s+=n%10+'0';
            n/=10;
        }
        reverse(s.begin(),s.end());
        return s;
    }  
};
