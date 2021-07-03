请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

数值（按顺序）可以分成以下几个部分：

若干空格
一个 小数 或者 整数
（可选）一个 'e' 或 'E' ，后面跟着一个 整数
若干空格
小数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
下述格式之一：
至少一位数字，后面跟着一个点 '.'
至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
至少一位数字
部分数值列举如下：

["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]
部分非数值列举如下：

["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]
 

示例 1：

输入：s = "0"
输出：true
示例 2：

输入：s = "e"
输出：false
示例 3：

输入：s = "."
输出：false
示例 4：

输入：s = "    .1  "
输出：true
 

提示：

1 <= s.length <= 20
s 仅含英文字母（大写和小写），数字（0-9），加号 '+' ，减号 '-' ，空格 ' ' 或者点 '.' 。

链接：https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof

class Solution {
    enum state{
        start,
        number,
        numdecimal,
        decimal,
        denum,
        sign,
        exp,
        expsign,
        expnum,
        end,
    };
    enum getChar{
        num,
        point,
        blank,
        Ee,
        symbol,
        illegal
    };
    map<state,map<getChar,state>> m{//状态转移图
        {
            start,{
                {blank,start},
                {num,number},
                {point,decimal},
                {symbol,sign}
            }
        },{
            number,{
                {num,number},
                {point,numdecimal},
                {Ee,exp},
                {blank,end}
            }           
        },{
            numdecimal,{
                {num,denum},
                {Ee,exp},
                {blank,end}
            }
        },{
            decimal,{
                {num,denum}               
            }
        },{
            denum,{
                {num,denum},
                {Ee,exp},
                {blank,end}
            }
        },{
            sign,{
                {num,number},
                {point,decimal},
            }
        },{
            exp,{
                {symbol,expsign},
                {num,expnum}
            }
        },{
            expsign,{
                {num,expnum}
            }
        },{
            expnum,{
                {num,expnum},
                {blank,end}
            }
        },{
            end,{
                {blank,end}
            }
        }
    };
    getChar getc(char a){//确定输入的函数
        if(a=='+'||a=='-')
        return symbol;
        else if(a==' ')
        return blank;
        else if(isdigit(a))
        return num;
        else if(a=='.')
        return point;
        else if(a=='E'||a=='e')
        return Ee;
        else
        return illegal;
    }
public:
    bool isNumber(string s) {
        int l=s.size();
        state sta=start;
        for(auto a:s){
            getChar b=getc(a);
            if(m[sta].count(b)>0){
                sta=m[sta][b];
            }
            else
            return false;
        }
        return sta==end||sta==number||sta==expnum||sta==denum||sta==numdecimal;
    }
};
