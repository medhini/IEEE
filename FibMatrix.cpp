#include<stdio.h>
#include<iostream>

using namespace std;

void mul(long long int F[2][2], int M[2][2])
{
	int p = F[0][0]*M[0][0]+F[0][1]*M[1][0];
	int q= F[0][0]*M[0][1]+F[0][1]*M[1][1];
	int r= F[1][0]*M[0][0]+F[1][0]*M[1][0];
	int s=F[1][0]*M[0][1]+F[1][1]*M[1][1];
	
	F[0][0]=p;
	F[0][1]=q;
	F[1][0]=r;
	F[1][1]=s;
}

void power(long long int F[2][2], long long int n)
{
	int M[2][2] = {{1,1},{1,0}};
	
	for(long long int i=2; i<n; i++)
		mul(F,M);
}

main()
{
	long long int F[2][2]={{1,1},{1,0}};
	long long int n;
	
	scanf("%lld", &n);
	
	if(n==0)
	printf("0");
	
	else
		{
			power(F, n);
			printf("%lld", F[0][0]);
		}
}
