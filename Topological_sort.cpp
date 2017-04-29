#include <bits/stdc++.h>
using namespace std;

// Directed graph
class Graph{
public:
    Graph(int v)
    {
        V = v;
        adjList = new list<int>[V+1];
    }

    ~Graph(){
        delete [] adjList;
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }

    void dfs_visit(int s, bool isVisited[], list<int>& slist){
        isVisited[s] = true;
        for (int curr: adjList[s]){
            if (!isVisited[curr]){
                dfs_visit(curr, isVisited, slist);
            }
        }
        slist.push_front(s);
    }

    void dfs()
    {
        bool isVisited[V+1]{false};
        list<int> topologically_sorted_list;
        for (int i=1; i<=V; ++i){
            if (!isVisited[i]){
                dfs_visit(i, isVisited, topologically_sorted_list);
            }
        }

        for (int i: topologically_sorted_list){
            cout << i << endl;
        }
    }

private:
    int V;
    list<int>* adjList;
};

int main(){
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(4, 3);
    g.addEdge(4, 5);
    g.dfs();
    return 0;
}
