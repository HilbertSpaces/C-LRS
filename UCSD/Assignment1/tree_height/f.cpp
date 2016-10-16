#include <iostream>
#include <queue>
int main()
{
	std::queue<int> v;	
	v.push(5);
	v.push(4);
	v.pop();
	std::cout<<v.front();
	return 0;
}        
