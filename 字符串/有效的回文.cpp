给定一个字符串 s ，验证 s 是否是 回文串 ，只考虑字母和数字字符，可以忽略字母的大小写。

本题中，将空字符串定义为有效的 回文串 。

 

示例 1:

输入: s = "A man, a plan, a canal: Panama"
输出: true
解释："amanaplanacanalpanama" 是回文串
示例 2:

输入: s = "race a car"
输出: false
解释："raceacar" 不是回文串
 

提示：

1 <= s.length <= 2 * 105
字符串 s 由 ASCII 字符组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/XltzEq

class Solution {
public:
    bool isPalindrome(string s) {
        auto judge=[](const char &a){
            if((a>='0'&&a<='9')||(a>='a'&&a<='z')||(a>='A'&&a<='Z'))
            return true;
            else
            return false;
        };
        string ss;
        for(char a:s)
        if(judge(a))//isalnum也可以判断，和tolower()都在ctype头文件
        ss+=tolower(a);
        int l=0,r=ss.size()-1;
        while(l<r){
            if(ss[l]!=ss[r])
            return false;
            r--;
            l++;
        }
        return true;
    }
};
