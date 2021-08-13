给定一个字符串 s ，请计算这个字符串中有多少个回文子字符串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

 

示例 1：

输入：s = "abc"
输出：3
解释：三个回文子串: "a", "b", "c"
示例 2：

输入：s = "aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 

提示：

1 <= s.length <= 1000
s 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/a7VOhD

//中心扩散
class Solution {
public:
    int countSubstrings(string s) {
        if(s.size()<=1)
        return s.size();
        int re=0;
        for(int i=0;i<s.size();i++){
            re+=cen2side(i,i+1,s)+cen2side(i,i,s);
        }
        return re;
    }
    int cen2side(int l,int r,string &s){
        int re=0;
        while(l>=0&&r<s.size()&&s[l]==s[r]){
            re++;
            l--;
            r++;
        }
        return re;
    }
};
//动态规划
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        if(n<=1)
        return n;
        vector<vector<int>> dp(n,vector<int>(n,1));
        int re=0;
        for(int i=2;i<=n;i++){//每次判断len个字符是不是回文的
            for(int l=0;l<=n-i;l++){//遍历所有字符，每i个一组
                int r=l+i-1;
                if(r==l+1&&s[l]==s[r]){//处理i=2的情况
                    dp[l][r]=1;
                    re++;
                }
                else if(s[l]==s[r]&&dp[l+1][r-1]){//i>2的情况
                    dp[l][r]=1;
                    re++;
                }
                else{
                    dp[l][r]=0;
                }
            }
        }          
        return re+n;    
    }
};
