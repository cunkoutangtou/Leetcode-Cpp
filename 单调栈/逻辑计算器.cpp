优先级!>&>|。
//使用单调找记录符号，另一个栈记录数字。
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>

using namespace std;

int main() {
	string s;
	cin >> s;
	s.push_back('#');
	stack<int> num;
	stack<char> ope;
	map<char, int> m{
		{'!',3},
		{'&',2},
		{'|',1},
		{'#',0}//设定一个最低优先级的额外符号，用来保证符号栈不会因为单调递增而没有将全部符号都计算一遍。
	};
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i]))
			num.push(s[i] - '0');
		else {
			if (s[i] == '(')
				ope.push(s[i]);
			else if (s[i] == ')') {
				while (ope.top() != '(') {//直到遇到左括号为止，将括号内的内容全部计算。
					char c = ope.top(); ope.pop();
					int a = 0;
					switch (c) {
					case '!':
						num.top() = !num.top(); break;
					case '&':
						a = num.top(); num.pop();
						num.top() &= a; break;
					case '|':
						a = num.top(); num.pop();
						num.top() |= a; break;
					}
				}
				ope.pop();
			}
			else {
				while (!ope.empty() && m.count(ope.top()) && m[s[i]] < m[ope.top()]) {//保证符号栈的单调性并且没有遇到左括号。
					char c = ope.top(); ope.pop();
					int a = 0;
					switch (c) {
					case '!':
						num.top() = !num.top(); break;
					case '&':
						a = num.top(); num.pop();
						num.top() &= a; break;
					case '|':
						a = num.top(); num.pop();
						num.top() |= a; break;
					}
				}
				ope.push(s[i]);
			}
		}
	}
	cout << num.top();
}
