class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , char> s_to_t;
        unordered_map<char , char> t_to_s;

        for(int i =0; i< s.length(); i++){
            char c1 = s[i];
            char c2 = t[i];

            //if c1 was already mapped to a different characters in t
            if(s_to_t.count(c1) && s_to_t[c1] != c2){
                return false;
            }

            //if c2 was already mapped from a different char 
            if(t_to_s.count(c2) && t_to_s[c2] != c1){
                return false;
            }

            s_to_t[c1] = c2;
            t_to_s[c2] = c1;
        }

        return true;
    }
};