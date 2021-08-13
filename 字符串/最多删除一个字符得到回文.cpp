给定一个非空字符串 s，请判断如果 最多 从字符串中删除一个字符能否得到一个回文字符串。

 

示例 1:

输入: s = "aba"
输出: true
示例 2:

输入: s = "abca"
输出: true
解释: 可以删除 "c" 字符 或者 "b" 字符
示例 3:

输入: s = "abc"
输出: false
 

提示:

1 <= s.length <= 105
s 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/RQku0D

class Solution {
public:
    bool validPalindrome(string s) {
        int l=0,r=s.size()-1;
        auto check=[&](int l,int r){
            while(l<r){
                if(s[l]!=s[r])
                return false;
                l++;
                r--;
            }
            return true;
        };
        while(l<r){
            if(s[l]!=s[r]){//注意要判断应该l++还是r--，并分别按选择后的结果继续运行，所以重新定义了一个函数。
                return check(l+1,r)||check(l,r-1);
            }
            l++;
            r--;
        }
        return true;
    }
};
