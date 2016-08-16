class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream in1(version1), in2(version2);
        int num1 = 0, num2 = 0, i1 = 0, i2 = 0;
        int n1 = version1.size(), n2 = version2.size();
        while(i1 < n1 || i2 < n2) {
            while(i1 < n1 && version1[i1] != '.') 
                num1 = num1*10 + version1[i1++] - '0';
            ++i1;
            while(i2 < n2 && version2[i2] != '.') 
                num2 = num2*10 + version2[i2++] - '0';
            ++i2;

            if(num1 > num2) return 1;
            else if(num1 < num2) return -1;
            else {
                num1 = 0;
                num2 = 0;
            }
        }
        return 0;
    }
};