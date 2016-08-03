/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
    	int res = 0;
    	unordered_map<float, int> m;
    	for(int i = 0; i < points.size(); ++i) {
    		int duplicate = 1;
    		m.clear();
    		m[INT_MIN] = 0;
    		for(int j = i+1; j < points.size(); ++j) {
    			if(points[i].x == points[j].x && points[i].y == points[j].y) {
    				duplicate++;
    				continue;
    			}
    			float slope = points[i].x == points[j].x ? INT_MAX : (float)(points[i].y - points[j].y) / (points[i].x - points[j].x);
    			m[slope]++;
    		}
    		for(auto it = m.begin(); it != m.end(); ++it) {
    			res = max(res, it->second + duplicate);
    		}
    	}
    	return res;
    }
};