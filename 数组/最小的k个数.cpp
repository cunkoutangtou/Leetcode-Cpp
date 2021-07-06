输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

 

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]
 

限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000

链接：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof

//类似的找前多少个数的题都可以用快排的思想，找到第k个位置的数就找到了答案。
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.size()==k)
        return arr;
        if(k==0)
        return {};
        int start=0,end=arr.size()-1;
        int index=partion(arr,start,end);
        while(index+1!=k){
            if(index+1>k){
                end=index-1;
                index=partion(arr,start,end);
            }else{
                start=index+1;
                index=partion(arr,start,end);
            }
        }
        vector<int> re;
        for(int i=0;i<k;i++)
        re.push_back(arr[i]);
        return re;
    }
    int partion(vector<int> &arr,int start,int end){
        if(arr.size()==1)
        return start;
        srand(time(0));
        int index=(rand()%(end-start+1))+start;
        swap(arr[index],arr[end]);
        int left=start-1;
        for(int i=start;i<end;i++){
            if(arr[i]<=arr[end]){
                left++;
                if(left<i){
                    swap(arr[left],arr[i]);
                }
            }
        }
        left++;
        swap(arr[left],arr[end]);
        return left;
    }
};
//使用堆存储最小的k个数，节省内存。
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.size()==k)
        return arr;
        if(k==0)
        return {};
        int l=arr.size();
        priority_queue<int> q;
        vector<int> re;
        for(int i=0;i<k;i++){
            q.push(arr[i]);
        }
        for(int i=k;i<l;i++){
            if(arr[i]<q.top()){
                q.pop();
                q.push(arr[i]);
            }           
        }
        while(!q.empty()){
            re.push_back(q.top());
            q.pop();
        }
        return re;
    }
};
