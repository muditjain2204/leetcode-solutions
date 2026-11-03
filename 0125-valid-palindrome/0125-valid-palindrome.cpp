class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        int n = s.length();
        //removing specials character and spaces 
        for(int i=0; i<n; i++){
            if(isalnum(s[i])){
                temp += tolower(s[i]);
            }
        }

        //step 2 :- create reversed string 
        string rev  = temp;
        reverse (rev.begin() , rev.end());

        //step3 :- compare both string 
        return temp == rev;
    }
};


