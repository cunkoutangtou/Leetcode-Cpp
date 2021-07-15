字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

 

示例 1：

输入: s = "abcdefg", k = 2
输出: "cdefgab"
示例 2：

输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"
 

限制：

1 <= k < s.length <= 10000

链接：https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof

//先部分旋转前n个和后面s.size()-n个，最后整体旋转。
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int l=0,r=s.size()-1;
        partrever(s,0,n-1);
        partrever(s,n,r);
        partrever(s,0,r);
        return s;
    }
    void partrever(string &s,int l,int r){
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }
};
