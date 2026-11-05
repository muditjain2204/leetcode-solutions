class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mapS[265] = {0};
        int mapT[256] = {0};

        for(int i=0; i<s.length() ; i++){
            unsigned char c1 = s[i];
            unsigned char c2 = t[i];

            //check if the last seen positions
            if(mapS[c1] != mapT[c2]){
                return false;
            }

                //store the 1-based index to different 
                mapS[c1] = i+ 1;
                mapT[c2] = i + 1;
        }

        return true;

    }
};