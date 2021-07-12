给定一个字符串 s 和一些 长度相同 的单词 words 。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符 ，但不需要考虑 words 中单词串联的顺序。

 

示例 1：

输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
示例 2：

输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
输出：[]
示例 3：

输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
输出：[6,9,12]
 

提示：

1 <= s.length <= 104
s 由小写英文字母组成
1 <= words.length <= 5000
1 <= words[i].length <= 30
words[i] 由小写英文字母组成

链接：https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words

//暴力法，将子串与主串一一比较，当出现一个不符合的单词或出现重复过多的单词时，暴力法会将该情况的单词放入子串的不同位置分别与主串比较一次，即没有剪枝
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty()||words.empty())
        return {};
        map<string,int> map,cmap;
        for(auto &w:words)
        map[w]++;
        int l=words[0].size(),L=words.size();
        vector<int> re;
        string ts;
        for(int i=0;i<s.size()-l*L+1;i+=1){
            int j=i;
            for(;j<i+l*L;j+=l){
                ts=s.substr(j,l);
                if(map[ts]>0&&cmap[ts]<map[ts]){
                cmap[ts]++;
                }
                else
                break;
            }
            if(j==i+l*L)
            re.push_back(i);
            cmap.clear();
        }
        return re;
    }
}；
//滑动窗口法，对其中存在的不符合的单词、重复过多的单词进行了剪枝。
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty()||words.empty())
        return {};
        map<string,int> map,cmap;
        for(auto &w:words)
        map[w]++;
        int l=words[0].size(),L=words.size();
        vector<int> re;
        string ts;
        for(int i=0;i<l;i++){
            int left=i;
            int right=i;
            int cnt=0;
            cmap.clear();
            while(right+l<=s.size()){
                ts=s.substr(right,l);
                right+=l;
                if(map[ts]>0){
                    cmap[ts]++;
                    cnt++;
                    while(cmap[ts]>map[ts]){这个位置重复的太多了，直到该单词重复数达到要求，窗口左侧会一直右移
                        string t=s.substr(left,l);
                        left+=l;
                        cmap[t]--;
                        cnt--;
                    }
                    if(cnt==L)
                    re.push_back(left);
                }
                else{//因为窗口不断将最右侧的单词放进窗口，所以只要放入的不符合要求，窗口内的单词全部丢弃
                    left=right;
                    cnt=0;
                    cmap.clear();
                }
            }
        }
        return re;
    }
};
