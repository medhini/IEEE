#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int lcs(char str1[], char str2[], int m, int n)
{
	int L[100][100]={};
	
	for(int i=0; i<=m; i++)
	{
		for(int j=0; j<=n; j++)
		{
			if(i==0 || j==0)
			L[i][j]=0;
			else if(str1[i-1]==str2[j-1])
			L[i][j]=L[i-1][j-1]+1;
			else
			L[i][j]=max(L[i-1][j], L[i][j-1]);	
		}
	}	
	return L[m][n];
}

main()
{
	char str1[100], str2[100];
	scanf("%s%s", str1, str2);
	int m=strlen(str1);
	int n=strlen(str2);
	int ans= lcs(str1, str2, m, n);
	printf("%d", ans);
}
