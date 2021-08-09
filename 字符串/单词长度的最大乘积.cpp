给定一个字符串数组 words，请计算当两个字符串 words[i] 和 words[j] 不包含相同字符时，它们长度的乘积的最大值。假设字符串中只包含英语的小写字母。如果没有不包含相同字符的一对字符串，返回 0。

 

示例 1:

输入: words = ["abcw","baz","foo","bar","fxyz","abcdef"]
输出: 16 
解释: 这两个单词为 "abcw", "fxyz"。它们不包含相同字符，且长度的乘积最大。
示例 2:

输入: words = ["a","ab","abc","d","cd","bcd","abcd"]
输出: 4 
解释: 这两个单词为 "ab", "cd"。
示例 3:

输入: words = ["a","aa","aaa","aaaa"]
输出: 0 
解释: 不存在这样的两个单词。
 

提示：

2 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] 仅包含小写字母

链接：https://leetcode-cn.com/problems/aseY1I

//先统计各字符串字符出现情况，然后将每个字符串与每个与它字符不重复的字符串的长度相乘，找最大的。
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxl=0,n=words.size();
        if(n<2)
        return 0;
        vector<int> sign(n);
        for(int i=0;i<n;i++)
        for(int j=0;j<words[i].size();j++){
            sign[i]|=1<<(words[i][j]-'a');
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int t=words[i].size()*words[j].size();
                if((sign[i]&sign[j])==0)
                maxl=max(maxl,t);
            }
        }
        return maxl;
    }
};
