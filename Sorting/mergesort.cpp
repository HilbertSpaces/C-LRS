#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
typedef std::vector<int> vector;
typedef std::vector<int>& rvector;
void merge(rvector A, int p, int q, int r)
{
	//create left half and right half vectors of A (L from p to q; R from q+1 to r)
	int n1=q-p;
	int n2=r-q-1;	
	vector L;
	L.resize(100);
	vector R;
	R.resize(100);
	for(int i=0; i<=n1;i++)
		L[i]=A[p+i];
	for(int j=0; j<=n2;j++)
		R[j]=A[q+j+1];
	//sentinel values
	L[n1+1]=10000;
	R[n2+1]=10000;
	//iterate and compare left and right elements then place them into A
	int m=0;
	int n=0;
	for(int k=p;k<=r;k++)
	{
		if(L[m]<=R[n])
		{
			std::cout<<L[m]<<"|"<<m<<"\n";
			A[k]=L[m];
			m++;
		}
		else
		{
			A[k]=R[n];
			n++;
		}
	}
} void mergeSort(rvector A,int p, int r)
{
	if(p<r)
	{
		int q=((p+r)/2);
		mergeSort(A,p,q);
		mergeSort(A,q+1,r);
		merge(A,p,q,r);
	}
}
int main()
{
	int i=0;
	int num=0;
	int starter[]={99,12,5,220,334,10,22,7,18,4,3};
	vector A(starter,starter+sizeof(starter)/sizeof(starter[0]));
	vector B(starter,starter+sizeof(starter)/sizeof(starter[0]));
	mergeSort(A,0,A.size()-1);
	while(i<A.size())
	{
		std::cout<<A[i]<<"|";
		i++;
	}
	std::cout<<"\n";
	return 0;
}        
