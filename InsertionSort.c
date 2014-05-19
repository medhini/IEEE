#include <stdio.h>

int main(void) 
{
	int i, n, temp, A[1000], j;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	scanf("%d", &A[i]);
	for(i=1; i<n; i++)
	{
		temp=A[i];
		j=i-1;
		while(temp<A[j] && j>=0)
		{
			A[j+1]=A[j];
			j--;
		}
	A[j+1]=temp;
	}

	for(i=0; i<n; i++)
	{
		printf("%d ", A[i]);
	}
	return 0;
}
