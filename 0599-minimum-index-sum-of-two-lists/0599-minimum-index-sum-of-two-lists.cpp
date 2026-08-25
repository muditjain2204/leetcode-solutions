class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2){
        unordered_map<string , int> indexMap;
        vector<string> result;
        int mini = INT_MAX;

        for(int i =0 ; i<list1.size(); i++){
            indexMap[list1[i]] = i;
        }

        //check matching strings in list2
        for(int j=0; j<list2.size(); j++){
            auto x = indexMap.find(list2[j]);
            if(x != indexMap.end()){
                int sum = j + x-> second;

                if(sum < mini){
                    mini = sum;
                    result.clear();
                    result.push_back(list2[j]);
                }else if (sum == mini){
                    result.push_back(list2[j]);
                }
            }
        }

        return result;
    }
    


    
       

        
    
};