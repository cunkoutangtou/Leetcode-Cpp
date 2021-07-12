 History
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
示例 4:

输入: s = ""
输出: 0
 

提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成

链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
        return 0;
        int l=0,start=0,i=0;
        map<char,int> m;
        while(i<s.size()){
            if(s.size()-start<=l)
            break;
            if(m.count(s[i])>0&&m[s[i]]>=start){
                start=m[s[i]]+1;
                m.erase(s[i]);
            }
            m[s[i]]=i;
            l=l>i-start+1?l:i-start+1;
            i++;
        }
        return l;
    }
};
//滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int db[128]={0},head=0,tail=0,ans=0;
        for(;tail<s.size();tail++){
            head=max(head,db[s[tail]-NULL]);
            db[s[tail]-NULL]=tail+1;//当出现重复时窗口左端点该在重复的地方向右移动一个点。
            ans=max(ans,tail-head+1);
        }
        return ans;
    }
};
