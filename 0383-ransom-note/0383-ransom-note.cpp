class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length() > magazine.length()){
            return false;
        }

        // int count[26] = {0};
        // for(char c : magazine){
        //     count[c-'a']++;

        // }

        // for(char c : ransomNote){
        //     if(--count[c-'a']< 0){
        //         return false;
        //     }
        // }

        // return true;

        unordered_map<char, int> count;
        for(char c : magazine){
            count[c]++;

        }
        for(char c : ransomNote){
            if(count[c] <= 0){
                return false;
            }
            count [c]--;
        }

        return true;

    }
};