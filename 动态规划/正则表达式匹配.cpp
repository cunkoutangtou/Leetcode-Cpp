给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

 
示例 1：

输入：s = "aa" p = "a"
输出：false
解释："a" 无法匹配 "aa" 整个字符串。
示例 2:

输入：s = "aa" p = "a*"
输出：true
解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3：

输入：s = "ab" p = ".*"
输出：true
解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4：

输入：s = "aab" p = "c*a*b"
输出：true
解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5：

输入：s = "mississippi" p = "mis*is*p*."
输出：false
 

提示：

0 <= s.length <= 20
0 <= p.length <= 30
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
保证每次出现字符 * 时，前面都匹配到有效的字符

链接：https://leetcode-cn.com/problems/regular-expression-matching

//递归，时间复杂度高，遇见“*”太多难受
class Solution {
public:
    bool isMatch(string s, string p) {
        return matchcore(s,p);
    }
    bool matchcore(string s,string p){
        if(s.empty()&&p.empty())
        return true;
        if(!s.empty()&&p.empty())
        return false;
        int ls=s.size();
        int lp=p.size();
        if(p[1]=='*'){
            if(s[0]==p[0]||(p[0]=='.'&&!s.empty()))
            return matchcore(s.substr(1,ls-1),p)||matchcore(s.substr(1,ls-1),p.substr(2,lp-2))
            ||matchcore(s,p.substr(2,lp-2));
            else
            return matchcore(s,p.substr(2,lp-2));
        }
        else{
            if(s[0]==p[0]||(p[0]=='.'&&!s.empty()))
            return matchcore(s.substr(1,ls-1),p.substr(1,lp-1));
            else
            return false;
        }
    }
};
//动态规划，i，j表示子串长度。
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for(int j=1;j<=n;j++){
            if(p[j-1]=='*'&&f[0][j-2]==1)
            f[0][j]=1;
            else
            f[0][j]=0;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    if(s[i-1]==p[j-2]||p[j-2]=='.')
                    f[i][j]=f[i-1][j]||f[i][j-2];
                    else
                    f[i][j]=f[i][j-2];
                }
                else {
                    if(s[i-1]==p[j-1]||p[j-1]=='.')
                    f[i][j]=f[i-1][j-1];
                }
            }
        }
        return f[m][n];
    }
};
