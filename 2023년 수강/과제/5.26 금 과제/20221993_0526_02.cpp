#include <iostream>
#include <vector>
#include <queue>

#define MAX_VERTICES 100

class Edge {
public :
  int node;
  int weight;
  Edge (int node, int weight) {
    this->node = node;
    this->weight = weight;
  }
  
  bool operator<(const Edge& edge) const {
    return this->weight > edge.weight;
  }
};

class Prim {
public :
  int num_vertex;
  std::vector<Edge> graph[MAX_VERTICES];
  
  Prim(int num_vertex) {
    this->num_vertex = num_vertex;
  }
  
  void addEdge(int nodeA, int nodeB, int weight) {
    graph[nodeA].push_back(Edge(nodeB, weight));
    graph[nodeB].push_back(Edge(nodeA, weight));
  }
  
  void execute (int start) {
    std::vector<bool> selected(num_vertex, false);
    std::priority_queue<Edge> Q;
    Q.push(Edge(start, 0));
  
    int totalWeight = 0;
  
    while (!Q.empty()) {
      Edge cur = Q.top();
      Q.pop();
  
      if (selected[cur.node]) continue;
  
      selected[cur.node] = true;
      totalWeight += cur.weight;
  
      for (Edge next : graph[cur.node]) {
        if (!selected[next.node]) Q.push(next);
      }
    }
    std::cout << "Total weight: " << totalWeight << std::endl;
  }
};

int main() {
  Prim prim(7);
  prim.addEdge(0, 1, 9);
  prim.addEdge(0, 2, 10);
  prim.addEdge(1, 3, 10);
  prim.addEdge(1, 4, 5);
  prim.addEdge(2, 4, 7);
  prim.addEdge(2, 5, 2);
  prim.addEdge(3, 6, 4);
  prim.addEdge(4, 6, 7);
  prim.addEdge(5, 6, 6);
  prim.execute(0);
  return 0;
}