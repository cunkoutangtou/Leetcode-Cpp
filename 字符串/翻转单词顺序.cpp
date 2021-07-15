输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

 

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

说明：

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

链接：https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof

//先去除头尾空格，然后整个字符串翻转，然后查找遇到空格就翻转一个单词，遇到连着的空格就跳过。
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())
        return "";
        int l=0,r=s.size()-1;
        while(s[l]==' '){
            l++;
            if(l==s.size())
            return "";
        }
        while(s[r]==' '){
            r--;
        }
        s=s.substr(l,r-l+1);//去除头尾空格
        s=reversew(s);
        string re="";
        int i=0,j=1;//保证j在单词最后一个字母的右边一个位置，i在单词第一个字母
        for(;j<s.size();){
            if(s[j]==' '&&s[j-1]!=' '){
                re+=reversew(s.substr(i,j-i))+' ';
                i=++j;//i，j同时跳过空格
            }
            else if(s[j]==' '&&s[j-1]==' '){//连续空格则跳过
                ++j;
                ++i;
            }
            else{//字母则j右移
                ++j;
            }
        }
        re+=reversew(s.substr(i,j-i));//处理最后一个单词，因为是以空格为标志，而最后单词后面没空格了。
        return re;
    }
    string reversew(string s){
        int l=0,r=s.size()-1;
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return s;
    }
};
