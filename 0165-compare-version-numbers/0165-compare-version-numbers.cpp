class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.length();
        int n2 = version2.length();
        int i = 0, j = 0;
        
        while (i < n1 || j < n2) {
            long long num1 = 0;
            long long num2 = 0;
            
            // Extract revision from version1
            while (i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            
            // Extract revision from version2
            while (j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            
            // Compare revisions
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
            
            // Skip the dot '.' character
            i++;
            j++;
        }
        
        return 0;
    }
};