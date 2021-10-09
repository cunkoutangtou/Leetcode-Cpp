找到某个数满足1,a,b,c，其中a-1>=x,b-a>=x，c=a*x，且a，b为质数。
#include <bits/stdc++.h>

using namespace std;

int main () {
    int T;
    cin >> T;
    for (int p = 0; p < T; p++) {
        int x;
        cin >> x;
        //找两个比较质数乘一下，第一个要大于x，第二个要大于2x
        vector<bool> ok(30000, true);
        for (int i = 2; i <= x; i++) {
            int k = 1;
            while (k * i < 30000) {
                ok[k * i] = false;
                k++;
            }
        }
        long long num1 = x + 1;
        while (!ok[num1]) num1++;
        long long num2 = num1 + x;
        while (!ok[num2]) num2++;
        cout << num1 * num2 << endl;
    }
    return 0;
}
