给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

 

示例 1:

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
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
示例 4:

输入: s = ""
输出: 0
 

提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters

//下面两个都是滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
        return 0;
        int sign[128],re=0;
        memset(sign,-1,sizeof(sign));
        for(int l=0,r=0;r<s.size();r++){
            while(r>l&&sign[s[r]]>=l){//先判断当前元素是否重复，重复则循环处理直到不重复。
                sign[s[l]]=-1;
                l++;
            }
            sign[s[r]]=r;//元素放入窗口，并记录出现位置。
            re=max(re,r-l+1);
        }
        return re;
    }
};
//着眼点放在l的位置上.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
        return 0;
        int sign[128],re=0;
        memset(sign,-1,sizeof(sign));
        int l=0,r=0;
        while(r<s.size()){
            l=max(l,sign[s[r]]);//先判断，始终保证l及右边没有重复的字符。
            sign[s[r]]=r+1;//若重复则将下一次移动的位置置于当前位置的下一位。
            re=max(re,r-l+1);
            ++r;
        }
        return re;
    }
};
