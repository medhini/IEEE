//knapsack 

#include<stdio.h>
#include<iostream>

using namespace std;

main()
{
	int w, n, V[100], wt[100];
	cout<<"Enter max weight of knapsack : ";
	cin>>w;
	
	cout<<"Enter the number of items : ";
	cin>>n;
	
	for(int j=0; j<n; j++)
	{
		cout<<"value "<<j+1<<" : ";
		cin>>V[j];
		cout<<"weight "<<j+1<<" : ";
		cin>>wt[j];
	}
	
	int D[100][100]={};
	
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=w; j++)
		{
			if(i==0||j==0)
			D[i][j]=0;
			else if(wt[i-1]<=w)
			{
				D[i][j]=max((V[i-1] + D[i-1][j-wt[i]]), D[i-1][w]);  
			}
			else
				D[i][j]=D[i-1][j];
		}
	}
	cout<<"Maximum value : "<<D[n][w];
}
