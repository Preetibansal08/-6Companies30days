class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
     
        vector<string> ans;

        //Base Case
        if(s.length()<=10){
            return ans;
        }
        unordered_map<string,int>mp;
        for(int i=0; i <=s.length()-10;i++)
        {
            string h= s.substr(i,10);
            mp[h]++;
        }

        for(auto x: mp){
            if(x.second > 1){
                ans.push_back(x.first);
            }
        }

        return ans;
    }
};
