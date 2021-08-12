给定两个字符串 s 和 t 。返回 s 中包含 t 的所有字符的最短子字符串。如果 s 中不存在符合条件的子字符串，则返回空字符串 "" 。

如果 s 中存在多个符合条件的子字符串，返回任意一个。

 

注意： 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。

 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC" 
解释：最短子字符串 "BANC" 包含了字符串 t 的所有字符 'A'、'B'、'C'
示例 2：

输入：s = "a", t = "a"
输出："a"
示例 3：

输入：s = "a", t = "aa"
输出：""
解释：t 中两个字符 'a' 均应包含在 s 的子串中，因此没有符合条件的子字符串，返回空字符串。
 

提示：

1 <= s.length, t.length <= 105
s 和 t 由英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/M1oyTv

//需要额外加一个变量来统计有几个必须的字符已经出现了。
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())
        return "";
        unordered_map<char,int> m;
        int cnt=t.size(),recnt=INT_MAX;
        string re="";
        for(auto a:t)
        m[a]++;
        for(int l=0,r=0;r<s.size();r++){
            if(m.count(s[r])){//先处理右边界，判断当前字符是否为目标字符串的字符
                if(m[s[r]]>0)
                cnt--;
                m[s[r]]--;//允许s中的字符出现次数超过其在t中重复的次数
            }
            if(cnt==0){//t中的字符全出现过了
                while(1){//处理左边界
                    if(m.count(s[l])){//l指向的字符是t中的
                        if(m[s[l]]<0){//如果l指向的这个字符重复的次数没超过t中的，就不能移动左边界
                            m[s[l]]++;
                            l++;
                        }
                        else
                        break;
                    }
                    else//不必要的字符跳过
                    l++;
                }
                if(r-l+1<recnt){//是否长度更小
                    recnt=r-l+1;
                    re=s.substr(l,recnt);
                }
            }
        }
        return re;
    }
};
