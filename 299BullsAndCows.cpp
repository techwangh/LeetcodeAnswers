class Solution {
public:
    string getHint(string secret, string guess) {
    	int A = 0, B = 0;
        for(int i = 0; i < secret.size(); ++i) {
        	if(secret[i] == guess[i]) {
        		++A;
        		secret[i] = '#';
        		guess[i] = '#';
        	}
        }
        vector<int> count(10, 0);
        for(int i = 0; i < secret.size(); ++i) {
        	if(secret[i] != '#') {
        		count[secret[i] - '0']++;
        	}
        }

        for(int i = 0; i < guess.size(); ++i) {
        	if(guess[i] != '#' && count[guess[i] - '0'] > 0) {
        		++B;
        		count[guess[i] - '0']--;
        	}
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};