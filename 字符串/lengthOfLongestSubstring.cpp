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
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int db[127]={0},head=0,tail=0,ans=0;
        for(;tail<s.size();tail++){
            head=max(head,db[s[tail]-NULL]);
            db[s[tail]-NULL]=tail+1;
            ans=max(ans,tail-head+1);
        }
        return ans;
    }
};
