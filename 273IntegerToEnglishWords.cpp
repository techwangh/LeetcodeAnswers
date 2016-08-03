class Solution {
public:
	vector<string> ones{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
	vector<string> tens{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
	vector<string> oneten{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string numberToWords(int num) {
    	if(num == 0) return "Zero";
    	string res = "";
        vector<string> map{"", " Thousand ", " Million ", " Billion "};
        vector<int> chunks;
        while(num) {
        	chunks.push_back(num % 1000);
        	num /= 1000;
        }

        for(int i = chunks.size()-1; i >= 0; --i) {
        	string s = chunksToWords(chunks[i]);
        	if(s == "Zero") continue;
        	res = res + s + map[i];
        }
        if(res.back() == ' ')
        	res.resize(res.size()-1);
        return res;

    }

    string chunksToWords(int num) {
    	if(num == 0) return "Zero";
    	string res = "";
    	vector<int> digits;
    	while(num) {
    		digits.push_back(num % 10);
    		num /= 10;
    	}
    	if(digits.size() == 3) {
    		res += ones[digits[2]] + " " + "Hundred";
    		if(digits[1] == 1)						//111
    			res += " " + oneten[digits[0]];
    		else if(digits[1] == 0) {				//10*
    			if(digits[0] != 0) 
    				res += " " + ones[digits[0]];	//101
    		}
    		else {
    			res += " " + tens[digits[1]];
    			if(digits[0] != 0)
    				res += " " + ones[digits[0]];	//121
    		}
    	}
    	else if(digits.size() == 2) {
    		if(digits[1] == 1)
    			res += oneten[digits[0]];
    		else {
    			res += tens[digits[1]];
    			if(digits[0] != 0)
    				res += " " + ones[digits[0]];
    		}
    	}
    	else if(digits.size() == 1)
    		res += ones[digits[0]];

    	return res;
    }
};

//more concise one
class Solution {
public:
  	vector<string> v1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", 
  						 "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string numberToWords(int num) {
  		string res;
  		vector<string> v{"", " Thousand ", " Million ", " Billion "};
  		int i = 0;
  		while(num) {
  			string s = convertHundred(num % 1000);
  			if(s != "") {
  				res = convertHundred(num % 1000) + v[i] + res;
  			}
  			num /= 1000;
  			i++;
  		}
  		if(res.back() == ' ')
  			res.pop_back();
  		return res.empty() ? "Zero" : res; 
    }

	string convertHundred(int num) {
		int a = num / 100, b = num %100, c = num % 10;
		string res = "";
		res = b < 20 ? v1[b] : v2[b/10] + (c ? " " + v1[c] : "");
		if(a > 0)
			res = v1[a] + " Hundred" + (b ? " " + res : "");
		return res;
	}    
};