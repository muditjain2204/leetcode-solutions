class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram;

        for(const string& s: strs){
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            anagram[sorted_s].push_back(s);
        }
        vector<vector<string>> result;
        result.reserve(anagram.size());
        for(auto & x: anagram){
            result.push_back(move(x.second));
        }
        return result;

    }
};