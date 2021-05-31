给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

 

示例 1：

输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"
示例 2：

输入：s = ")()())"
输出：4
解释：最长有效括号子串是 "()()"
示例 3：

输入：s = ""
输出：0
 

提示：

0 <= s.length <= 3 * 104
s[i] 为 '(' 或 ')'

链接：https://leetcode-cn.com/problems/longest-valid-parentheses

//使用栈，最底下放没有被匹配的括号位置，初始为-1
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s=="")
        return 0;
        int n=s.size();
        stack<int> sta;
        sta.push(-1);
        int re=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
            sta.push(i);
            else{
                sta.pop();
                if(sta.empty()){
                    sta.push(i);
                }
                else{
                    re=max(re,i-sta.top());
                }
            }
        }
        return re;
    }
};
//动态规划，只有遇见')'才可能匹配，所以其他情况dp都为0。
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s=="")
        return 0;
        int n=s.size(),re=0;
        vector<int> dp(n+1,0);
        //遇到')'时需要判断是....()还是....))这种情况，与'('匹配后需要注意前面有可能还有连续的已匹配好的括号
        for(int i=2;i<=n;i++){
            if(s[i-1]==')'){
                if(s[i-2]=='('){
                    dp[i]=dp[i-2]+2;
                }
                else if(i-dp[i-1]-2>=0&&s[i-dp[i-1]-2]=='('){//第一个条件避免“())”的情况
                    dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2;
                }
            }
            re=max(re,dp[i]);
        }
        return re;
    }
};
//不用额外空间的方法，从左向右扫描一遍，再反过来扫描一遍，当左括号和右括号一样多时比较长度
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s=="")
        return 0;
        int left=0,right=0,re=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
            left++;
            else
            right++;
            if(left==right)
            re=max(right*2,re);
            if(right>left){
                left=0;
                right=0;
            }
        }
        left=0;
        right=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')')
            right++;
            else
            left++;
            if(left==right)
            re=max(right*2,re);
            if(left>right){
                left=0;
                right=0;
            }
        }
        return re;
    }
};
