给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的某个变位词。

换句话说，第一个字符串的排列之一是第二个字符串的 子串 。

 

示例 1：

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
示例 2：

输入: s1= "ab" s2 = "eidboaoo"
输出: False
 

提示：

1 <= s1.length, s2.length <= 104
s1 和 s2 仅包含小写字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/MPnaiL

//哈希表加滑动窗口。
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m;
        for(char a:s1){
            m[a]++;//使用每个字符的个数来表示窗口内的字母是否合法
        }
        for(int l=0,r=0;r<s2.size();){
            if(!m.count(s2[r])){//s1中没有该字母
                ++r;
                while(l<r){
                    if(m.count(s2[l]))//只对s1中存在的字母进行个数恢复
                    m[s2[l]]++;
                    l++;
                }
            }
            else{
                m[s2[r]]--;
                while(l<r&&m[s2[r]]<0){//重复字母太多
                    m[s2[l]]++;
                    l++;
                }
                r++;
                if(r-l==s1.size())//窗口大小达到了s1的长度则返回true
                return true;
            }
        }
        return false;
    }
};
