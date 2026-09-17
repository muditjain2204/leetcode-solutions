class Solution {

    private :
    
    bool isSubsequence(const string& a , const string& b){
        int i  = 0;
        int j = 0;
        while(i<a.length() && j<b.length()){
            if(a[i] == b[j]){
                i++;
            }
            j++;
        }
        return i == a.length();
    }
public:
    int findLUSlength(vector<string>& strs) {
        //Sort strings by length in descending order
        sort(strs.begin(), strs.end(), [](const string& a , const string& b){
            return a.length() > b.length();
        });

        int n = strs.size();
        for(int i=0; i<n; i++){
            bool isUncommon = true;
            for(int j=0; j<n; j++){
                if(i == j) 
                continue;

                //if strs[i] is a subsequence of strs[j], it cannot be common 
                if(isSubsequence(strs[i] , strs[j])){
                    isUncommon = false;
                    break;
                }
            }
            // because we sorted by length , the first valid stringis the largest 
            if(isUncommon) {
                return 
                strs[i].length();
            }
        }

        return -1;

        
        
    }
};