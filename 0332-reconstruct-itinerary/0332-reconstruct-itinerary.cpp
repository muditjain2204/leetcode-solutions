#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build the adjacency list with priority queues for min-heap ordering
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        vector<string> itinerary;
        dfs("JFK", graph, itinerary);

        // Path is built in post-order, so reverse it
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }

private:
    void dfs(const string& airport, 
             unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph, 
             vector<string>& itinerary) {
        
        // Traverse all available outgoing edges in lexicographical order
        while (!graph[airport].empty()) {
            string next = graph[airport].top();
            graph[airport].pop();
            dfs(next, graph, itinerary);
        }
        
        // Add to itinerary after visiting all outgoing destinations
        itinerary.push_back(airport);
    }
};