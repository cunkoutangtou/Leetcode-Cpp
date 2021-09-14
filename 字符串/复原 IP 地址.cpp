给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。

有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。

 

示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：

输入：s = "0000"
输出：["0.0.0.0"]
示例 3：

输入：s = "1111"
输出：["1.1.1.1"]
示例 4：

输入：s = "010010"
输出：["0.10.0.10","0.100.1.0"]
示例 5：

输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

提示：

0 <= s.length <= 3000
s 仅由数字组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/restore-ip-addresses

//dfs尝试划分各个段。
class Solution {
    const int mseg=4;
    int segnum=0;
    vector<string> re;
    vector<string> temp;
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.empty()||s.size()>12)//长度不超过12
        return {};
        dfs(s,0);
        return re;
    }
    void dfs(const string& s,int l){
        if(l==s.size()){//遍历到结束
            if(segnum!=mseg)//如果分的段不够则回溯
            return;
            string b;
            for(auto a:temp)
            b+=a+'.';
            b.pop_back();
            re.push_back(move(b));
            return;
        }
        if(s[l]=='0'){//0不能出现在为前导，出现，则必须分段。
            temp.push_back("0");
            segnum++;
            dfs(s,l+1);
            temp.pop_back();
            segnum--;
        }
        else{
            string ans;
            for(int i=l;i<s.size();i++){//从该位置遍历后面各位
                ans+=s[i];
                auto judge=[=](){
                    int re=0;
                    for(int i=0;i<ans.size();i++){
                        re*=10;
                        re+=ans[i]-'0';
                    }
                    return re;
                };
                if(judge()>255)//判断是否超上限，超了则之后的各位也没必要遍历了
                break;
                temp.push_back(ans);
                segnum++;
                dfs(s,i+1);
                temp.pop_back();
                segnum--;
            }
        }
    }
};
