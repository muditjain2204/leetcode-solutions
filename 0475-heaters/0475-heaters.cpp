class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(heaters.begin() , heaters.end());
        int minRadius = 0;
        
        for(int house:houses){
            //Find the first heater that is >= house position
            auto it = lower_bound(heaters.begin(), heaters.end(), house);

            int distToRightHeater = INT_MAX;
            int distToLeftHeater = INT_MAX;

            //Distance to the heater at ot to the right of the house
            if(it!= heaters.end()){
                distToRightHeater = *it - house;
            }

            //Distance to the heater strictly to the left of the house 
            if(it != heaters.begin()){
                distToLeftHeater = house - *(it - 1);
            }
            
            //the house is warmed by whicever heater is closer
            int closestHeaterDist = min(distToLeftHeater, distToRightHeater);

            //the global radius must be large enough to cover this house
            minRadius = max(minRadius , closestHeaterDist);
        

        
        }

        return minRadius;

    }
};