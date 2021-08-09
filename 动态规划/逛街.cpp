链接：https://www.nowcoder.com/questionTerminal/58ae39f4436b44d9836fc89542d67f71
来源：牛客网

小Q在周末的时候和他的小伙伴来到大城市逛街，一条步行街上有很多高楼，共有n座高楼排成一行。
小Q从第一栋一直走到了最后一栋，小Q从来都没有见到这么多的楼，所以他想知道他在每栋楼的位置处能看到多少栋楼呢？（当前面的楼的高度大于等于后面的楼时，后面的楼将被挡住） 
示例1
输入
[5,3,8,3,2,5]
输出
[3,3,5,4,4,4]
说明
当小Q处于位置3时，他可以向前看到位置2,1处的楼，向后看到位置4,6处的楼，加上第3栋楼，共可看到5栋楼。当小Q处于位置4时，他可以向前看到位置3处的楼，向后看到位置5,6处的楼，加上第4栋楼，共可看到4栋楼。

备注:
输入为一个数组，表示每一栋楼的高度w[i]
1<=数组长度<=100000;
1<=wi<=100000; 

//利用栈存储一个递减数组，并且从左右两个方向分别存储。
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param heights int整型vector 
     * @return int整型vector
     */
    vector<int> findBuilding(vector<int>& heights) {
         if(heights.empty())
             return {};
        stack<int> a,b;
        int n=heights.size();
        vector<int> left(n),right(n),re;
        for(int i=0;i<n;i++){
           left[i]=a.size();//由于栈中元素递减，所以栈的大小就是从当前位置向左看能看到的所有楼的个数。
           if(a.empty()){
               a.push(i);
            }
            else{
                while(!a.empty()&&heights[i]>=heights[a.top()]){//当前楼高大于等于前面的楼高的话就要不断弹出前面的元素，直到栈中元素递减。
                    a.pop();
                }
                a.push(i);
            }
        }
        for(int i=n-1;i>=0;i--){
           right[i]=b.size();
           if(b.empty()){
               b.push(i);
            }
            else{
                while(!b.empty()&&heights[i]>=heights[b.top()]){
                    b.pop();
                }
                b.push(i);
            }
        }
        for(int i=0;i<n;i++){//将每个位置向左看和向右看能看到的楼数加上当前这个楼即为结果。
            re.push_back(left[i]+right[i]+1);
        }
        return re;
    }
};
