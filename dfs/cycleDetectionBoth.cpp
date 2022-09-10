#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
vector<int>mark(N, 0), parent(N, 0);
vector<int>graph[N];
bool cycle = 0;

void cycleDetectionDirected(int x) {
  mark[x]++;
  for (auto i : graph[x]) {
    if (!mark[i])parent[i] = x, cycleDetectionDirected(i);
    else if (mark[i] == 1)cycle = 1;
  }
  mark[x]++;
}
void cycleDetectionUndirected(int x) {
  mark[x]++;
  for (auto i : graph[x]) {
    if (!mark[i])parent[i] = x, cycleDetectionUndirected(i);
    else if (mark[i] == 1 and parent[x] != i)cycle = 1;
  }
  mark[x]++;
}
void solve() {
  int noOfVertices, noOfEdges;
  scanf("%d %d", &noOfVertices, &noOfEdges);
  int x, y;

  // for directed graph this input
  for (int i = 1; i <= noOfEdges; i++) {
    scanf("%d %d", &x, &y);
    graph[x].push_back(y);
  }

  // for undirected graph this input
  for (int i = 1; i <= noOfEdges; i++) {
    scanf("%d %d", &x, &y);
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  // for directed graph call this
  for (int i = 1; i <= noOfVertices; i++)if (!mark[i])cycleDetectionDirected(i);

  // for undirected graph call this
  // for(int i=1;i<=noOfVertices;i++)if(!mark[i])cycleDetectionUndirected(i);

    
  cycle ? printf("Cycle Present\n") : printf("No Cycle\n");
}
int main() {
  solve();
}
