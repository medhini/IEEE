#include<stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int fib[5002][1003]={};

char str[1002];

vector <string> ans;

void check()
{
	long long int a,j,k,l,i;
	
    fib[0][1000]=0;
	fib[1][1000]=1;
	fib[2][1000]=1;
	
    for(long long int i=3; i<5000; i++)
    {
        for(j=1000; j>=0; j--)
        {
            fib[i][j]=fib[i][j]+fib[i-1][j]+fib[i-2][j];
            
            if(fib[i][j]>9)
            {
                fib[i][j-1]+=(fib[i][j]/10);
                fib[i][j]=fib[i][j]%10;
            }
 
        }
		
		for(k=0;;k++)
        {  
			if(fib[i][k]!=0)
				break; 
		}
        for(j=k,l=0; j<=1000; j++,l++)
        {
        	str[l]=fib[i][j]+48;
        }
		str[l]=0;
		
		ans.push_back(str);
		
    }
}

int main() 
{
	int t;
	ans.push_back("0");
	ans.push_back("1");
	ans.push_back("1");
    check();
    sort(ans.begin(),ans.end());
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s", str);
		if(binary_search(ans.begin(), ans.end(), str)==true)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
