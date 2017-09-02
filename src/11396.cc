// 11396 Claw Decomposition
// Graph Traversal Bipartite Graph Check
// Since every node in the graph has rank 3
// each node can either be the center of one claw 
// or be at the periphery of three claws.
// Choose one node for each connected componet
// if he can't be neither 
// then the graph isn't claw-decomposable.
#include <iostream>
#include <vector>
using namespace std;
int c[3010];
vector<int> e[3010];
int main() {
  int v, a, b;
  while(cin >> v && v != 0) {
    // parse input
    for(int i = 1; i <= v; i++) {
      c[i] = 0;
      e[i].clear();
    }
    while(cin >> a) {
      cin >> b;
      if(a == 0 && b == 0) {
        break;
      }
      e[a].push_back(b);
      e[b].push_back(a);
    }
    bool can = true;
    for(int i = 1; i <= v; i++) {
      if(c[i] == 0) {
        vector<int> dfs_stack;
        dfs_stack.push_back(i);
        c[i] = 1;
        
        while(!dfs_stack.empty()) {
          int top = dfs_stack.back();
          dfs_stack.pop_back();
          for(auto& n : e[top]) {
            if(c[n] == 0) {
              c[n] = -c[top];
              dfs_stack.push_back(n);
            }
            else if(c[n] == c[top]) {
              can = false;
            }
          }
        }
      }
    }
    cout << (can ? "YES\n" : "NO\n");
  }
}
