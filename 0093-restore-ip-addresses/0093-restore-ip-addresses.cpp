class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;

        int n = s.length();

        //quick optimisation length must be bwtween 4 and 12 integers 
        if(n < 4 || n> 12){
            return result;
        }
    backtrack ( s, 0, 0 ,"" , result);
    return result;
    }

    private:
    void backtrack(const string&s , int index, int dots, string current , vector<string>& result){
        //base case : 4 segments ( 3 dots addded ) and cosumers full string 
        if(dots == 4){
            if(index == s.length()){
                current.pop_back();//remove the trailing dot
                result.push_back(current);
            }
            return ;
        }

        //try 1,2,3, digits for the current ip segment 
        for(int len = 1;len <= 3; len++){
            if(index + len > s.length())
            break;
            string segment = s.substr(index , len);

            //check leading zero rule : multi-digit segment
            if(segment.length() > 1 && segment[0] == '0')
            break;

            //check range : segment integer valkue must be <= 25
            int val = stoi(segment);
            if(val > 255) 
            break;

            backtrack(s, index + len, dots + 1 , current+ segment + ".", result);
        }

    }
};