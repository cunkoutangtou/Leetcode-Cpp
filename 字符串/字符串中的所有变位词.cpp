给定两个字符串 s 和 p，找到 s 中所有 p 的 变位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

变位词 指字母相同，但排列不同的字符串。

 

示例 1:

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的变位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的变位词。
 示例 2:

输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的变位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的变位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的变位词。
 

提示:

1 <= s.length, p.length <= 3 * 104
s 和 p 仅包含小写字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/VabMRr

//滑动窗口+哈希，这种异位但是内容一样的果断哈希表来进行存储。
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size())
        return {};
        unordered_map<char,int> m;
        vector<int> re;
        for(char a:p)
        m[a]++;
        for(int l=0,i=0;i<s.size();){
            if(!m.count(s[i])){
                i++;
                while(l<i){
                    if(m.count(s[l]))
                    m[s[l]]++;
                    l++;
                }
            }
            else{
                m[s[i]]--;
                while(l<i&&m[s[i]]<0){
                    m[s[l]]++;
                    l++;
                }
                i++;
                if(i-l==p.size())
                re.push_back(l);
            }
        }
        return re;
    }
};
