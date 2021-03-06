在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例:

s = "abaccdeff"
返回 "b"

s = "" 
返回 " "
 

限制：

0 <= s 的长度 <= 50000

链接：https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof

//第一遍统计，第二遍找第一个为1的字符。
class Solution {
public:
    char firstUniqChar(string s) {
        int sign[128]{0};
        for(int i=0;i<s.size();i++){
            sign[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(sign[s[i]]==1)
            return s[i];
        }
        return ' ';
    }
};
