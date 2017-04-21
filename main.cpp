#include <iostream>

using namespace std;

pair<int,int> partition(int *A, const int &p, const int &r)
{
	int j=p-1;
	for(int i=p; i<r-1; ++i)
	{
		if(A[i]<A[r-1])
		{
			++j;
			swap(A[i],A[j]);
		}
	}
	++j;
	int t=j-1;
	for(int i=j; i<r-1; ++i)
	{
		if(A[i]==A[r-1])
		{
			++t;
			swap(A[i],A[t]);
		}
	}
	t=max(t,j-1);
	swap(A[j],A[r-1]);
	return pair<int,int>(j,t);
}

void quickSort(int *A, const int &p, const int &r)
{
	if(p<r)
	{
		int q=partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}

int main()
{
	int n;
	cin >> n;
	int *A=new int[n];
	for(int i=0; i<n; ++i)
		cin >> A[i];
	pair<int,int> pivots=quickSort(A,0,n);
	cout << "A: ";
	for(int i=0; i<n; ++i)
		cout << A[i] << " ";
	cout << endl;
	cout << "p: " << pivots.first << ", " << "t: " << pivots.second << endl;
	cin.get();
	cin.get();
	return 0;
}
