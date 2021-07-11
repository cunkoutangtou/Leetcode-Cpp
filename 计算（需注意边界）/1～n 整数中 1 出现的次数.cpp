输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

 

示例 1：

输入：n = 12
输出：5
示例 2：

输入：n = 13
输出：6
 

限制：

1 <= n < 2^31

链接：https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof

//每次考虑第一位，剩下的n-1位靠排列组合就能得到。为了先处理数字高位方便可以先将int转为string再处理。
class Solution {
public:
    int s2i(string s){
        int l=s.size();
        int re=0;
        for(int i=0;i<l;i++){
            re*=10;
            re+=s[i]-'0';
        }
        return re;
    }
    string i2s(int num){
        string s;
        while(num){
            s+=num%10+'0';
            num/=10;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int countDigitOne(int n) {
        string s=i2s(n);
        return Nof1(s);
    }
    int Nof1(string s){
        if(s.empty())
        return 0;
        int l=s.size();
        if(l==1&&s[0]=='1')
        return 1;
        if(l==1&&s[0]=='0')
        return 0;
        int first=0,middle=0;
        if(s[0]-'0'>1)
        first=pow(10,l-1);
        else if(s[0]-'0'==1)
        first=s2i(s.substr(1,l-1))+1;
        middle=(s[0]-'0')*(l-1)*pow(10,l-2);//排列组合
        return first+middle+Nof1(s.substr(1,l-1));
    }
};
