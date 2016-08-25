class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses ,prerequisites);
        vector<int> degrees = computr_degrees(graph);
        for(int i = 0; i < numCourses; ++i) {
        	int j = 0; 
        	for( ; j < numCourses; ++j) {
        		if(!degrees[j]) break;
        	}
        	if(j == numCourses) return false;
        	degrees[j] = -1;
        	for(auto neigh : graph[j]) {
        		degrees[neigh]--;
        	}
        }
        return true;
    }

    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
    	vector<unordered_set<int>> graph(numCourses);
    	for(auto& pre : prerequisites) {
    		graph[pre.second].insert(pre.first);
    	}
    	return graph;
    }

    vector<int> computr_degrees(vector<unordered_set<int>> graph) {
    	vector<int> degrees(graph.size(), 0);
    	for(auto& neighbors : graph) {
    		for(auto neigh : neighbors) {
    			degrees[neigh]++;
    		}
    	}
    	return degrees;
    }
};