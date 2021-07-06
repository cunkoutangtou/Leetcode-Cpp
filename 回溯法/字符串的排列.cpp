输入一个字符串，打印出该字符串中字符的所有排列。

 

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

 

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 

限制：

1 <= s 的长度 <= 8

链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof

//用一个标记数组sign记录第j位已经出现过哪几个字符即可。
class Solution {
public:
    vector<string> permutation(string s) {
        if(s.empty())
        return {};
        vector<string> re;
        int j=0;
        string temp="";
        bt(s,j,re,temp);
        return re;
    }
    void bt(string &s,int j,vector<string> &re,string &temp){
        if(j==s.size()){//这里是用temp存储排列，所以j要到达s.size()处才可以将所有元素全部放完。如果直接存s，则j走到最后一个元素即s.size()-1处即可。
            re.push_back(temp);
            return;
        }
        int sign[128]{0};
        for(int i=j;i<s.size();i++){
            if(sign[s[i]])
            continue;
            sign[s[i]]=1;
            swap(s[i],s[j]);
            temp.push_back(s[j]);
            bt(s,j+1,re,temp);
            temp.pop_back();
            swap(s[i],s[j]);
        }
    }
};
