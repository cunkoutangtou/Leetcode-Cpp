给你一个字符串 s，找到 s 中最长的回文子串。

 

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
示例 3：

输入：s = "a"
输出："a"
示例 4：

输入：s = "ac"
输出："a"
 

提示：

1 <= s.length <= 1000
s 仅由数字和英文字母（大写和/或小写）组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring

//动态规划
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n < 2)
            return s;
        int begin = 0, maxL = 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        dp[i][i] = 1;
        //从长度为2的子串开始寻找
        for (int L = 2; L <= n; L++)
        {
            //i为子串左边界，j为右边界
            for (int i = 0; i < n; i++)
            {
                int j = i + L - 1;
                if (j >= n)
                    break;
                if (s[i] == s[j])
                {
                    if (L <= 2)
                    {
                        dp[i][j] = 1;
                        if (L > maxL)
                        {
                            begin = i;
                            maxL = L;
                        }
                    }
                    else
                    {
                        if (dp[i + 1][j - 1])
                        {
                            dp[i][j] = dp[i + 1][j - 1];
                            if (L > maxL)
                            {
                                begin = i;
                                maxL = L;
                            }
                        }
                    }
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return s.substr(begin, maxL);
    }
};
//先把L=1和2的情况计算一遍
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
        return {};
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        int re=1,l=0;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                re=2;
                l=i;
            }
        }
        for(int L=3;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j=i+L-1;
                if(j>=n)
                break;
                if(s[i]==s[j])
                dp[i][j]=dp[i+1][j-1];
                else
                dp[i][j]=0;
                if(dp[i][j]){
                    if(j-i+1>re){
                        re=j-i+1;
                        l=i;
                    }
                }
            }
        }
        return s.substr(l,re);
    }
};
//中心扩散
class Solution {
public:
    pair<int,int> expand(int left,int right,string &s){
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            left--;
            right++;
        }
        return {left+1,right-1};
    }
    string longestPalindrome(string s) {
        if(s.empty())
        return s;
        int start=0,end=0;
        for(int i=0;i<s.size();i++){
            auto [start1,end1]{expand(i,i,s)};
            auto [start2,end2]{expand(i,i+1,s)};
            if(end1-start1>end-start){
                start=start1;
                end=end1;
            }
            if(end2-start2>end-start){
                start=start2;
                end=end2;
            }
        }
        return s.substr(start,end-start+1);
    }
};
//快速中心扩散
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
        return {};
        int n=s.size();
        int maxl=1,l=0;;
        for(int i=0;i<n;){
            int left=i,right=i;
            while(right<n&&s[right]==s[right+1])
            right++;
            i=right+1;
            while(left>=0&&right<n&&s[left]==s[right]){
                left--;
                right++;
            }
            if(right-left-1>maxl){
                maxl=right-left-1;
                l=left+1;
            }
        }
        return s.substr(l,maxl);
    }
};
