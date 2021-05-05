class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
        return 0;
        int l=0,start=0,i=0;
        map<char,int> m;
        while(i<s.size()){
            if(s.size()-start<=l)
            break;
            if(m.count(s[i])>0&&m[s[i]]>=start){
                start=m[s[i]]+1;
                m.erase(s[i]);
            }
            m[s[i]]=i;
            l=l>i-start+1?l:i-start+1;
            i++;
        }
        return l;
    }
};
