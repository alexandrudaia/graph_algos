#include <vector>
#include <iostream>

using std::vector;
using std::pair ;

void explore(int v, vector<vector<int> > &adj, vector <bool> &visited){
  visited[v]=true;
  for( size_t i=0 ; i<adj[v].size() ; i++){
    // explore if we have not visited yet 
    int w=adj[v][i];
    if(!visited[w])
	    explore(w,adj,visited);
  }

}

int number_of_components(vector<vector<int> >&adj){
	vector<bool> visited ;
	visited.resize(adj.size());
	int res=0;
	for(size_t v=0 ; v<adj.size() ; v++){
	  if(!visited[v]){
	  explore(v, adj , visited);
	  res++;
	  }
	}

	return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
 std:: cout << number_of_components(adj);

}

