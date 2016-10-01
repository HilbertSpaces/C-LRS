#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
typedef std::vector<int> vec; 
typedef std::vector<int>& refvec; 
void merge(refvec A,int p,int q,int r,long long& count)
{
	//Create vectors of length q-p for the left and r-q+1 for the right to store the halves of A
	int n1=q-p;
	int n2=r-q-1;
	vec L;
	L.resize(n1+2);
	vec R;
	R.resize(n2+2);
	//copy left and right halves of A into arrays L & R
	for(int i=0;i<=n1;i++)
		L[i]=A[p+i];
	for(int j=0;j<=n2;j++)
		R[j]=A[q+j+1];
	//sentinel values that no value from A will ever be larger than
	L[n1+1]=1000000;
	R[n2+1]=1000000;
	int i=0;
	int j=0;
	for(int k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			A[k]=L[i]; 
			i++;
		}
		else
		{
			A[k]=R[j];
			//add the length leftover in the left half **this is n1+1 (since n1 is index tracker we add one)
			//-i since we have put i elements from left half back into A already**
			count+=n1+1-i;
			j++;
		}
	}
}
void mergeInvert(refvec A, int p, int r,long long& count)
{
	if(p<r)
	{
		int q=((p+r)/2);
		mergeInvert(A,p,q,count);
		mergeInvert(A,q+1,r,count);
		merge(A,p,q,r,count);
	}
}
int main()
{
	using namespace std;
	ifstream inf("IntergerArray.txt");
	if(!inf)
		cerr<<"Couldn't read file"<<endl;
	vec A;
	int i=0;
	while(inf)
	{
		std::string strInput;
		inf>>strInput;
		if(inf!=0)
		{
			A.resize(i+1);
			A[i]=stoi(strInput);
		}
		i++;
	}
	long long count=0;
	mergeInvert(A,0,A.size()-1,count);
	std::cout<<count<<endl;
	//test array (used to avoid testing on given array of 100k elements)
	/*int B[]={1,3,5,2,4,6};
	vec C(B,B+sizeof(B)/sizeof(B[0]));
	mergeInvert(C,0,C.size()-1,count);
	cout<<"The count is: "<<count<<endl;
	count=0;
	while(count<C.size())
	{
		cout<<C[count]<<"|";
		count++;
	}
	cout<<endl;*/
	return 0;
}        
