在英语中，我们有一个叫做 词根(root)的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。

现在，给定一个由许多词根组成的词典和一个句子。你需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。

你需要输出替换之后的句子。

 

示例 1：

输入：dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
输出："the cat was rat by the bat"
示例 2：

输入：dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
输出："a a b c"
示例 3：

输入：dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
输出："a a a a a a a a bbb baba a"
示例 4：

输入：dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was rattled by the battery"
输出："the cat was rat by the bat"
示例 5：

输入：dictionary = ["ac","ab"], sentence = "it is abnormal that this solution is accepted"
输出："it is ab that this solution is ac"
 

提示：

1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] 仅由小写字母组成。
1 <= sentence.length <= 10^6
sentence 仅由小写字母和空格组成。
sentence 中单词的总量在范围 [1, 1000] 内。
sentence 中每个单词的长度在范围 [1, 1000] 内。
sentence 中单词之间由一个空格隔开。
sentence 没有前导或尾随空格。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/replace-words

//字典树判断前缀
class tnode{
public:
    vector<tnode*> next;
    bool end=false;
    tnode():next(26,nullptr){}
    void insert(string word){
        if(word.empty())
        return;
        tnode* p=this;
        for(char c:word){
            if(p->next[c-'a']==nullptr)
            p->next[c-'a']=new tnode();
            p=p->next[c-'a'];
        }
        p->end=true;//插入所有字符后设置终止节点。
    }
    string presearch(string word){
        string re;
        tnode* p=this;
        for(char c:word){
            if(p->end)//判断当前节点是否为某个字符串的终止节点。
            return re;
            re+=c;
            if(p->next[c-'a'])
            p=p->next[c-'a'];
            else
            break;
        }
        return word;//没有前缀则返回本身
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        tnode root;
        for(string s:dictionary){
            root.insert(s);
        }
        sentence+=' ';//为了让最后一个字符子串也能被处理
        string re;
        for(int l=0,i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                re+=root.presearch(sentence.substr(l,i-l))+' ';
                l=i+1;
            }
        }
        re.pop_back();//最后会多一个空格
        return re;
    }
};
