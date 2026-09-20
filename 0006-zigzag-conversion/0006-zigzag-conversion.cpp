class Solution {
public:
    string convert(string s, int numRows) {
        //Basr case : if 1 row or string is less than numRows, returns s as is 
        if(numRows == 1 || s.length() <= (size_t)numRows){
            return s;

        }
        vector<string> rows(min((int)s.length(), numRows));
        int currRow = 0;
        bool goingDown = false;

        for(char c: s) {
            rows[currRow] += c;
            //Reverse direction when hitting top or bottom row
            if(currRow == 0 || currRow == numRows - 1){
                goingDown =! goingDown;
            }
            currRow += goingDown ? 1 : -1;
        }

        string result ="";
        for(const string& row : rows){
            result += row;
        }
        return result;
    }
};