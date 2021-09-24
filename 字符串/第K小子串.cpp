链接：https://www.nowcoder.com/questionTerminal/c59d9690061e448fb8ec7d744c20ebff?answerType=1&f=discussion
来源：牛客网

输入一个字符串 s，s 由小写英文字母组成，保证 s 长度小于等于 5000 并且大于等于 1。在 s 的所有不同的子串中，输出字典序第 k 小的字符串。
字符串中任意个连续的字符组成的子序列称为该字符串的子串。
字母序表示英文单词在字典中的先后顺序，即先比较第一个字母，若第一个字母相同，则比较第二个字母的字典序，依次类推，则可比较出该字符串的字典序大小。

输入描述:
第一行输出一个字符串 s，保证 s 长度小于等于 5000 大于等于 1。
第二行一个整数 k (1<= k <= 5)，保证 s 不同子串个数大于等于 k。


输出描述:
输出一个字符串表示答案。
示例1
输入
aabb
3
输出
aab
说明
不同的子串依次为：
a aa aab aabb ab abb b bb
所以答案为aab

//利用set存储string时本身排序就是字典序的特点，遍历所有连续的字符串，始终保证set大小为k，实际上就类似一个堆的作用，只将字典序小于set最后一个元素的字符串放进来。
#include<iostream>
#include<set>
#include<string>
#include<vector>

using namespace std;

int main(){
    string s;
    int k;
    cin>>s>>k;
    set<string> order;
    for(int i=0;i<s.size();i++)
    {
        string temp;
        for(int j=i;j<s.size();j++){
            temp.push_back(s[j]);
            if(order.size()==k)
                if(temp>=*(--order.end()))//新字符串字典序大于set中的最后一个元素，则它和它之后的字符串都不用看了。
                    break;
            order.insert(temp);
            if(order.size()>k)//set大小大于k了就吐出一个元素。
            order.erase(*(--order.end()));
        }
    }
    cout<<*(--order.end());
}
