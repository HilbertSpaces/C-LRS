#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class TreeHeight {
  int n;             
  std::vector<int> parent;

public:
  void read() {
    std::cin >> n;
    parent.resize(n);
    for (int i = 0; i < n; i++)
      std::cin >> parent[i];
  }
  int compute_height() {
    // Replace this code with a faster implementation
    /*int maxHeight = 0;
    for (int vertex = 0; vertex < n; vertex++) {
      int height = 0;
      for (int i = vertex; i != -1; i = parent[i])
        height++;
      maxHeight = std::max(maxHeight, height);
    }
    return maxHeight;*/
  std::vector<std::vector<int> > tree;
  tree.resize(n);
  for(int i=0; i<n; i++)
  {
	  tree[i][0]=i;
	  tree[i][1]=-2;
	  tree[i][2]=-2;
  }
  int next;
  for(int i=0; i<n; i++)
  {
	  if(parent[i]==-1)
		  next=i;
	  else if(tree[parent[i]][1]==-2)
		  tree[parent[i]][1]=parent[i];
	  else
		  tree[parent[i]][2]=parent[i];
  }
  return Height(tree,next,1);
  }
  int Height(std::vector<std::vector<int> > tree,int next,int side)
  {
	  if(tree[next][side]==-2)
		  return 0;
	  return 1+ std::max(Height(tree,tree[next][side],1),Height(tree,tree[next][side],2));
  }
};
int main() {
  std::ios_base::sync_with_stdio(0);
  TreeHeight tree;
  tree.read();
  std::cout << tree.compute_height() << std::endl;
}
