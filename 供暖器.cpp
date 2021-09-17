冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。

在加热器的加热半径范围内的每个房屋都可以获得供暖。

现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。

说明：所有供暖器都遵循你的半径标准，加热的半径也一样。

 

示例 1:

输入: houses = [1,2,3], heaters = [2]
输出: 1
解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
示例 2:

输入: houses = [1,2,3,4], heaters = [1,4]
输出: 1
解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
示例 3：

输入：houses = [1,5], heaters = [2]
输出：3
 

提示：

1 <= houses.length, heaters.length <= 3 * 104
1 <= houses[i], heaters[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/heaters

//遍历房子数组，找到每个离它最近的左右加热器，并存储此时覆盖这个加热器的最小半径，然后对所有最小半径取最大值。
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int re=0;
        int m=houses.size(),n=heaters.size();
        sort(heaters.begin(),heaters.end());
        for(int i=0;i<m;i++){
            int a=findleft(houses[i],heaters),b=findright(houses[i],heaters);//找该房子左右有无加热器，然后分别处理。
            if(a==-1){
                b=abs(houses[i]-b);
                re=max(re,b);
            }
            else if(b==-1){
                a=abs(houses[i]-a);
                re=max(re,a);
            }
            else{
                a=abs(houses[i]-a);
                b=abs(houses[i]-b);
                re=max(re,min(a,b));
            }
        }
        return re;
    }
    int findleft(int house,vector<int> &heaters){
        int l=0,r=heaters.size()-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(heaters[mid]==house)
            return house;
            else if(heaters[mid]>house)
            r=mid-1;
            else{
                l=mid+1;
                if(l<heaters.size()&&heaters[l]>house)//由于加热器两个坐标的间隔不一定是1，防止一步直接跨到房子右边。
                return heaters[l-1];
            }
        }
        return heaters[l]<=house?heaters[l]:-1;
    }
    int findright(int house,vector<int> &heaters){
        int l=0,r=heaters.size()-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(heaters[mid]==house)
            return house;
            else if(heaters[mid]>house){
                r=mid-1;
                if(r>=0&&heaters[r]<house)//防止跨到左边
                return heaters[r+1];
            }
            else
            l=mid+1;
        }
        return heaters[l]>=house?heaters[l]:-1;
    }
};
