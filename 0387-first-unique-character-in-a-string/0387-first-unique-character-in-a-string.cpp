class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char , int> firstMap;
        for(char c:s){
            firstMap[c]++;
        }

        for(int i=0; i<s.length(); i++){
            if(firstMap[s[i]] == 1){
                return i;
            }

        }
        return -1;



        
    }
};