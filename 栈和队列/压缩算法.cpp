链接：https://www.nowcoder.com/questionTerminal/ebf85b76361245f4a3ac273e6876c662
来源：牛客网

小Q想要给他的朋友发送一个神秘字符串，但是他发现字符串的过于长了，于是小Q发明了一种压缩算法对字符串中重复的部分进行了压缩，对于字符串中连续的m个相同字符串S将会压缩为[m|S](m为一个整数且1<=m<=100)，例如字符串ABCABCABC将会被压缩为[3|ABC]，现在小Q的同学收到了小Q发送过来的字符串，你能帮助他进行解压缩么？ 



示例1
输入
"HG[3|B[2|CA]]F"
输出
"HGBCACABCACABCACAF"
说明
HG[3|B[2|CA]]F−>HG[3|BCACA]F−>HGBCACABCACABCACAF

备注:
S的长度<=1000;
S仅包含大写字母、[、]、|;
解压后的字符串长度不超过100000;
压缩递归层数不超过10层;

//
class Solution {
    struct Node{
        string str;
        int num;
    };
    stack<Node> sta;
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return string字符串
     */
    string compress(string str) {
        if(str.empty())
            return "";
        string t="";
        int num=0;
        for(auto s:str){
            if(s>='0'&&s<='9'){//数字转换
                num*=10;
                num+=s-'0';
            }
            else if(s=='['){//进入压缩区域，保存现场
                sta.push({t,num});
                t="";
                num=0;
            }
            else if(s=='|'){//进行下一个循环，准备解压缩
                continue;
            }
            else if(s==']'){//离开压缩区域，解压缩
                string t1="";
                for(int i=0;i<num;i++){
                    t1+=t;
                }
                t=sta.top().str+t1;//返回上一个现场
                num=sta.top().num;
                sta.pop();
            }
            else//存储压缩的字符用于解压缩
                t+=s;
        }
        return t;
    }
};
