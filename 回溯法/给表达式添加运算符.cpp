给定一个仅包含数字 0-9 的字符串 num 和一个目标值整数 target ，在 num 的数字之间添加 二元 运算符（不是一元）+、- 或 * ，返回所有能够得到目标值的表达式。

 

示例 1:

输入: num = "123", target = 6
输出: ["1+2+3", "1*2*3"] 
示例 2:

输入: num = "232", target = 8
输出: ["2*3+2", "2+3*2"]
示例 3:

输入: num = "105", target = 5
输出: ["1*0+5","10-5"]
示例 4:

输入: num = "00", target = 0
输出: ["0+0", "0-0", "0*0"]
示例 5:

输入: num = "3456237490", target = 9191
输出: []
 

提示：

1 <= num.length <= 10
num 仅含数字
-231 <= target <= 231 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/expression-add-operators

class Solution {
    vector<string> re;
public:
    vector<string> addOperators(string num, int target) {
        dfs(num,"",target,0,0,0);
        return re;
    }
    void dfs(const string s,string temp,const int target,long long cur,int index,long long mul){//mul用于回滚上一步的操作，将上一步的操作加到cur之前先与当前val相乘
        if(index>=s.size()&&cur==target){
            re.push_back(temp);
            return;
        }
        if(index>=s.size())
        return;
        long long val=0;
        int si=temp.size();//用于回溯到temp添加字符之前的状态
        if(index>0)//第一个数之后才会添加符号
        temp.push_back(0);//占位符，可以直接更改这个值
        for(int i=index;i<s.size();i++){//每次多添加一个数字
            if(s[index]=='0'&&i!=index)
            break;
            val=val*10+s[i]-'0';
            temp.push_back(s[i]);
            if(index==0){
                dfs(s,temp,target,val,i+1,val);//第一个数字直接放，没有左边的cur。
            }else{
                temp[si]='+';dfs(s,temp,target,cur+val,i+1,val);//cur是符号左边所有的值的计算结果，右边是当前dfs层已经放入的数字的值。
                temp[si]='-';dfs(s,temp,target,cur-val,i+1,-val);
                temp[si]='*';dfs(s,temp,target,cur-mul+mul*val,i+1,mul*val);
            }
        }
        temp.resize(si);
    }
};
