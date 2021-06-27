给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

链接：https://leetcode-cn.com/problems/group-anagrams

//通过哈希表进行分类，注意字符串可以进行排序，确定哈希表的键值是什么，即异位词的共同点，这里是排序好的字符串。
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        vector<vector<string>> re;
        for(auto &s:strs){
            string key=s;
            sort(key.begin(),key.end());
            m[key].push_back(s);
        }
        for(auto it=m.begin();it!=m.end();it++){
            re.push_back(it->second);
        }
        return re;
    }
};
