class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    	int dup = 0;
        if(B > H || F > D || E > C || A > G)
        	dup = 0;
        else {
	    	int x = 0, y = 0;
	        y = min(D, H) - max(B, F);
	        x = min(C, G) - max(A, E);
	        int dup = x * y;
        }
        int area = (C - A) * (D - B) + (G - E) * (H - F);
        return area - x*y;
    }
};