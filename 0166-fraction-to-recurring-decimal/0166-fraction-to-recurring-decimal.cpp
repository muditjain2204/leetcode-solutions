class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator ==0) 
        return "0";

        string result  = "";

        //handle signs ( xorx for negative result if signs differ)
        if((numerator < 0)^(denominator < 0)) {
            result += "-";
        }

        //convert to long long to avoid overflow with INT_MIN
        long long num = abs(static_cast< long long > (numerator));
        long long den = abs(static_cast < long long > (denominator));

        //append integral part
        result += to_string(num/den);
        long long remainder = num % den;

        if(remainder == 0) {
            return result;
        }
        result += ".";

        //Map to store remainder -> position in the string where it occurred 
        unordered_map<long long, int > remainderMap;

        while(remainder != 0){
            //if remainder is seen before , we foind a repeating cycle 
            if(remainderMap.find(remainder) != remainderMap.end()){
                result.insert(remainderMap[remainder] , "(");
                result += ")";
                break;
            }

            //Record the current remainder position 
            remainderMap[remainder] = result.length();
            remainder *= 10;
            result += to_string(remainder / den);
            remainder %= den;
        }

        return result;
    }

};