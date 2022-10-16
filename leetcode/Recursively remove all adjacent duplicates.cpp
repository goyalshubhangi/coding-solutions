class Solution{
public:
    
    string rem(string s){
        int i=0;
        string ans;
        int n=s.size();
        while(i<n){
            if(i<n-1 && s[i]==s[i+1]){
                while(i<n-1 && s[i]==s[i+1]) i++;
            }
            else{
                ans.push_back(s[i]);
            }
            i++;
        }
        return ans;
    }
    

    
    string rremove(string s){
        string s1;
        while(s.size()!=s1.size()){
            s1=s;
            s=rem(s1);
        }
        return s;
        // code here
    }
};
