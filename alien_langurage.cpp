// A C++ program to order of characters in an alien language
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;


class Graph {
public:
    Graph();
    // add an edge to graph
    void AddEdge(char v, char w);
    // prints a Topological Sort of the complete graph
    bool TopologicalSort();
    void PrintAdjacentList();
private:
    enum DFS_Status{
        kUnvisited,
        kVisiting,
        kVisited
    };
    static const int kCharNum = 256;
    vector<bool> V_;    // all vertices
    unordered_map<char, vector<char> > adj_; // adjacency list

    /**
     * Depth First Search
     * @param v current vertex
     * @param visit record the node status during DFS
     * @param result push the visited node to result
     * @return false if the graph has circle
     */
    bool DFS(char v, vector<DFS_Status> *visit, string *result);
};

Graph::Graph() : V_(kCharNum, false) {
}

void Graph::AddEdge(char v, char w) {
    V_[v] = true;
    V_[w] = true;
    adj_[v].push_back(w); // Add w to v’s list.

}

bool Graph::DFS(char v, vector<DFS_Status> *visit,
                string *result)
{
    // Mark the current node as visiting.
    (*visit)[v] = kVisiting;
    // Recur for all the vertices adjacent to this vertex
    for (char u : adj_[v]) {
        if ((*visit)[u] == kUnvisited){
            bool ret = DFS(u, visit, result);
            if(!ret)  return false;
        } else if((*visit)[u] == kVisiting){
            cout << "ERROR: Circle detected! This graph is not a DAG."
                 << endl;
            return false;
        }
    }
    (*visit)[v] = kVisited;
    //push the visited node to the result
    *result += v;
    return true;
}

bool Graph::TopologicalSort() {
    string result;
    // Mark all the vertices as not visit
    vector<DFS_Status> visit(kCharNum, kUnvisited);
    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < kCharNum; ++i) {
        if (V_[i] && visit[i] == kUnvisited) {
            if(!DFS(i, &visit, &result)){
                return false;
            }
        }
    }
    // Print result
    reverse(result.begin(), result.end());
    for(char ch : result) {
        cout << ch << " ";
    }
    cout << endl;
    return true;
}
void Graph::PrintAdjacentList() {
    for(const auto & kv : adj_){
        cout << kv.first << ":\t" ;
        for(char ch : kv.second)    cout << ch << " ";
        cout << endl;
    }
}
// This function fidns and prints order of characer from a sorted
// array of words.
void PrintOrder(const vector<string> &words)  {
    const int n = words.size();
    Graph graph;
    // Process all adjacent pairs of words and create a graph
    for (int i = 0; i < n - 1; ++i) {
        // Take the current two words and find the first mismatching
        // character
        const string &word1 = words[i];
        const string &word2 = words[i + 1];
        for (int j = 0; j < min(word1.length(), word2.length()); ++j){
            // If we find a mismatching character, then add an edge
            // from character of word1 to that of word2
            if (word1[j] != word2[j]) {
                graph.AddEdge(word1[j], word2[j]);
                break;
            }
        }
    }
    graph.PrintAdjacentList();
    // Print topological sort of the above created graph
    graph.TopologicalSort();
}

int main()
{
    vector<string> words = {"caa", "aaa", "aab"};
    PrintOrder(words);
    cout << endl;
    vector<string> words1 = {"baa", "abcd", "abca", "cab", "cad"};
    PrintOrder(words1);
    cout << endl;
    vector<string> words2 = {"aaa", "abcd", "aba", "c" };
    PrintOrder(words2);
    return 0;
}
