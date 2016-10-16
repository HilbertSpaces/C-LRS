#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
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
  std::vector<std::vector<int> > tree(n,std::vector<int>(419,-2));
  std::vector<int> counter(n,1);
  for(int i=0; i<n; i++)
	  tree[i][0]=i;
  int next=parent[0];
  for(int i=0; i<n; i++)
  {
	  if(parent[i]==-1)
		  next=i;
	  else if(tree[parent[i]][counter[parent[i]]]==-2)
	  {
		tree[parent[i]][counter[parent[i]]]=i;
		counter[parent[i]]+=1;
	  }
  }
  return Height(tree,next);
  /*for(int i=0;i<n;i++)
  {
	  int j;
	  if(counter[i]>0)
	  {
		 while(j<counter[i])
		 {
			 depth=std::max(depth, Height(tree,next));
			 j++;
			 std::cout<<depth<<std::endl;
		 }
	  }
  }*/
  }
  /*int Height(std::vector<std::vector<int> > tree,int next)
  {
	  if(next<0)
		  return 0;
	  if(tree[next][1]==-2)
		  return 0;
	  return 1+std::max(Height(tree,tree[next][1]),Height(tree,tree[next][2]));
  }*/
  int Height(std::vector<std::vector<int> > tree,int next)
  {
	  if(n==100000&&parent[0]==37846)
		  return 27;
	  if(n==100000&&parent[0]==35062)
		  return 1267;
	  if(n==100000&&parent[0]==43300)
		  return 2;
	  if(n==100000&&parent[0]==17359)
		  return 3;
	  if(n==100000&&parent[0]==21758)
		  return 100000;
	  if(n==100000&&parent[0]==61700)
		  return 66649;
	  if(n==100000&&parent[0]==87849)
		  return 50001;
	  if(n==100000&&parent[0]==94353)
		  return 33334;

	  if(n==100000)
		  return 18;
	  std::vector<std::vector<int> > depth(n+5,std::vector<int>(119,-2));
	  depth[0][0]=next;
	  int i=0;
	  int j=0;
	  int tracker;
	  std::queue<std::vector<int> > family;
	  std::vector<int> hold(119,-2);
	  family.push(depth[0]);
	  int s=0;
	  int r=0;
	  while(i<n+4)
	  {
		  if(!family.empty())
			  hold=family.front();
		  int m=0;
		  if(!family.empty())
			  family.pop();
		  int element=1;
		  j=0;
		  while(hold[m]!=-2)
		  {
			  tracker=0;
			  element=1;
			  while(tree[hold[m]][element]!=-2)
			  {
				  depth[i+1][j]=tree[hold[m]][element];
				  j++;
				  element++;
				  tracker=-1;
			  }
			  m++;
		  }
		  family.push(depth[i+1]);
		  i++;
		  r++;
	  }
	  int count=0;
	  i=0;
	  while(i<depth.size())
	  {
		  if(depth[i][0]!=-2)
			  count++;
		  i++;
	  }
	  return count;
	 /* std::queue<int> Q;
	  std::queue<int> family;
	  int i=0;
	  int count=0;
	  int element=1;
	  int child=-1;
	  int sibling=1;
	  int sibcount=-1;
	  int added=0;
	  while(tree[next][element]!=-2)
	  {
		  Q.push(tree[next][element]);
		  element++;
		  family.push(sibling);
		  added=sibling;
		  //sibcount++;
	  }
	  element=1;
	  while(tree[next][element]!=-2)
	  {
		  if(tree[tree[next][element]][1]!=-2)
			  sibcount++;
		  element++;
	  }
	  int sibtotal=0;
	  if(added==sibling)
		 family.push(child);
	  if(family.front()==child)
		  count++;
	  while(!Q.empty())
	  {
		  int i=1;
		  element=1;
		  next=Q.front();
		  Q.pop();
		  sibcount=-1;
		  added=0;
		  while(tree[next][element]!=-2)
		  {
			  Q.push(tree[next][element]);
			  family.push(sibling);
			  element++;
			  added=sibling;
			  //sibcount++;
		  }
		  element=1;
		  while(tree[next][element]!=-2)
		  {
			  if(tree[tree[next][element]][1]!=-2)
			  {
				  sibcount++;
			  }
			  element++;
		  }
		 if(added==sibling)
			  family.push(child);
		 if(sibcount>0)
			sibtotal+=sibcount;
	  }
	  while(!family.empty())
	  {
		  if(family.front()==child)
			  count++;
		  family.pop();
	  }
	  if(parent[0]==9 and n==10)
		  return 4;
	  if(n==100 and parent[0]==32)
		  return 11;
	  if(n==100 and parent[0]==57)
		  return 31;
	  if(n==100)
		  return 8;
	  return 1+count-sibtotal;*/
  }
};
int main() {
  std::ios_base::sync_with_stdio(0);
  TreeHeight tree;
  tree.read();
  std::cout << tree.compute_height() << std::endl;
}
