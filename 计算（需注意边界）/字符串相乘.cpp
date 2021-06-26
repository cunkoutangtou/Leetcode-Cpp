
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
https://leetcode-cn.com/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/

//竖式乘法，先计算出每位总共有多少个数在这相加，再处理进位。注意m位的num1和n位的num2相乘总位数不会超过m+n。
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
        return "0";
        string re;
        int l1=num1.length(),l2=num2.length();
        vector<int> t(l1+l2,0);
        for(int i=l1-1;i>=0;i--){
            for(int j=l2-1;j>=0;j--){
                int su=(num1[i]-'0')*(num2[j]-'0');
                t[j+i+1]+=su;
        }
        }
        for(int i=l1+l2-1;i>=1;i--){
                t[i-1]+=t[i]/10;
                t[i]%=10;
        }
        int i=0;
        if(t[i]==0)
        i++;
        for(;i<l1+l2;i++){
            re+=t[i]+'0';
        }
        return re;
    }
};
//计算出被乘数每位与乘数相乘的结果，然后一个一个加起来。
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
        return "0";
        string re="0";
        int l1=num1.length(),l2=num2.length();
        for(int i=l1-1;i>=0;i--){
            string cur="";
            int add=0;
            for(int j=l1-1;j>i;j--){
                cur+='0';
            }
            for(int j=l2-1;j>=0;j--){
                cur+=((num1[i]-'0')*(num2[j]-'0')+add)%10+'0';
                add=((num1[i]-'0')*(num2[j]-'0')+add)/10;
            }
            while(add!=0){
                cur+=add+'0';
                add/=10;
            }
            reverse(cur.begin(),cur.end());
            re=addstr(re,cur);
        }
        return re;
    }
    //字符串进行算数相加，注意进位不为0也要继续处理，并且最后逆个序
    string addstr(const string &re,const string &cur){
        int i=re.length()-1,j=cur.length()-1,add=0;
        string ans;
        while(i>=0||j>=0||add!=0){
            int x=i>=0?re[i]-'0':0;
            int y=j>=0?cur[j]-'0':0;
            ans+=(x+y+add)%10+'0';
            add=(x+y+add)/10;
            i--;
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
