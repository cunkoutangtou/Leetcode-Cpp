单词数组 words 的 有效编码 由任意助记字符串 s 和下标数组 indices 组成，且满足：

words.length == indices.length
助记字符串 s 以 '#' 字符结尾
对于每个下标 indices[i] ，s 的一个从 indices[i] 开始、到下一个 '#' 字符结束（但不包括 '#'）的 子字符串 恰好与 words[i] 相等
给你一个单词数组 words ，返回成功对 words 进行编码的最小助记字符串 s 的长度 。

 

示例 1：

输入：words = ["time", "me", "bell"]
输出：10
解释：一组有效编码为 s = "time#bell#" 和 indices = [0, 2, 5] 。
words[0] = "time" ，s 开始于 indices[0] = 0 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"
words[1] = "me" ，s 开始于 indices[1] = 2 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"
words[2] = "bell" ，s 开始于 indices[2] = 5 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"
示例 2：

输入：words = ["t"]
输出：2
解释：一组有效编码为 s = "t#" 和 indices = [0] 。
 

提示：

1 <= words.length <= 2000
1 <= words[i].length <= 7
words[i] 仅由小写字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/short-encoding-of-words

//利用set去重。
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        if(words.empty())
        return 0;
        unordered_set<string> s(words.begin(),words.end());
        for(auto &st:words)
        for(int i=1;i<st.size();i++){//遍历所有可能的后缀，去除掉。
            s.erase(st.substr(i));
        }          
        int l=0;
        for(const string &st:s){
            l+=st.size()+1;
        }
        return l;
    }
};
//后缀建立字典树。
class Trienode{
    Trienode* next[26];
public:
    int count=0;//统计子树个数
    Trienode(){
        for(int i=0;i<26;i++)
        next[i]=nullptr;
    }
    Trienode* insert(char c){
        if(next[c-'a']==nullptr){
            next[c-'a']=new Trienode();
            count++;
        }
        return next[c-'a'];
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        if(words.empty())
        return 0;
        unordered_map<Trienode*,int> m;
        int l=0;
        Trienode root;
        for(int i=0;i<words.size();i++){
            Trienode *p=&root;
            for(int j=words[i].size()-1;j>=0;j--){
                p=p->insert(words[i][j]);//插入后，可能会切换到下一层节点
            }
            m[p]=i;
        } 
        for(auto &[node,i]:m){
            if(!node->count)//判断是否为叶子结点
            l+=words[i].size()+1;
        }    
        return l;
    }
};
