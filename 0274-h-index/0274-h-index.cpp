class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());

        int h = 0;
        //Count how many papers have at least ( i+ 1) citations
        while(h < citations.size() && citations[h] >= h + 1){
            h++;
        }
        return h;
    }
};