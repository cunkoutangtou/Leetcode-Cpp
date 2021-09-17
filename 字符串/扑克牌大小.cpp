链接：https://www.nowcoder.com/questionTerminal/0a92c75f5d6b4db28fcfa3e65e5c9b3f?f=discussion
来源：牛客网

扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A，2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）:)
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如：4 4 4 4-joker JOKER
请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR

基本规则：
（1）输入每手牌可能是个子，对子，顺子（连续5张），三个，炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）
（3）大小规则跟大家平时了解的常见规则相同，个子，对子，三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
（4）输入的两手牌不会出现相等的情况。

答案提示：
（1）除了炸弹和对王之外，其他必须同类型比较。
（2）输入已经保证合法性，不用检查输入是否是合法的牌。
（3）输入的顺子已经经过从小到大排序，因此不用再排序了.

输入描述:
输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如4 4 4 4-joker JOKER。


输出描述:
输出两手牌中较大的那手，不含连接符，扑克牌顺序不变，仍以空格隔开；如果不存在比较关系则输出ERROR。
示例1
输入
4 4 4 4-joker JOKER
输出
joker JOKER

//比较特殊的一点是本题中所有合法字符仅靠其第一位就可判断其与其他字符的的大小，并且题目保证输入合法。
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string temp;
    while(getline(cin,temp)){//先全读进来包括空格
        if(temp.find("joker JOKER")!=-1){//单独处理最大值，这样就不会把它错误归入对子中了
            cout<<"joker JOKER";
            continue;
        }
        int middle=temp.find('-');//划分两个字符串的需要
        string s1=temp.substr(0,middle),s2=temp.substr(middle+1);
        int c1=count(s1.begin(),s1.end(),' ');//数空格判断是哪种牌
        int c2=count(s2.begin(),s2.end(),' ');
        string f1=s1.substr(0,s1.find(' ')),f2=s2.substr(0,s2.find(' '));//找两个次出牌中的第一张牌
        string big="345678910JQKA2jokerJOKER";//后面的比前面大，并且靠首字符位置就能判断大小关系
        if(c1==c2){//牌数一样则只需要判断首字符哪个大
            if(big.find(f1)>big.find(f2))
                cout<<s1;
            else
                cout<<s2;
            return 0;
        }
        else{
            if(c1==3)//不一样就判断是否有炸
                cout<<s1;
            else if(c2==3)
                cout<<s2;
            else
                cout<<"ERROR";
        }
    }
}
