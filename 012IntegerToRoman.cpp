class Solution {
public:
    string intToRoman(int num) {
    	vector<vector<string>> dic = {{"","I","II","III","IV","V","VI","VII","VIII","IX"},
            						  {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
						              {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
						              {"","M","MM","MMM"}};
		string roman = "";
		roman += dic[3][num/1000%10];
		roman += dic[2][num/100%10];
		roman += dic[1][num/10%10];
		roman += dic[0][num%10];
		return roman;				              
    }
};