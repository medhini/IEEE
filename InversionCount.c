    #include<stdio.h>
    #include<algorithm>
    #include<iostream>

    using namespace std;

    int B[100005]={};
    
    int temp[100005]={};

    long long int merge(int B[], int temp[], long long int l, long long int mid, long long int u)
    {
    long long int i=l;
    long long int j=mid;
    long long int k=l;
    long long int count=0;
    while(i<=mid-1 && j<=u)
    {
    if(B[i]>B[j])
    {
    temp[k++]=B[j++];
    count+=mid-i;
    }
    else
    temp[k++]=B[i++];
    }
    while(i<=mid-1)
    temp[k++]=B[i++];
    while(j<=u)
    temp[k++]=B[j++];
    for(i=l; i<=u; i++)
    {
    B[i]=temp[i];
    }
    return count;
    }
    long long int m(int B[], long long int l, long long int u)
    {
    long long int count=0;
    if(l<u)
    {
    long long int mid=(l+u)/2;
    count=m(B, l, mid);
    count+=m(B, mid+1, u);
    count+=merge(B, temp, l, mid+1, u);
    }
    return count;
    }
    int main(void)
    {
    long long int i, n;
    scanf("%lld", &n);
    for(i=0; i<n; i++)
    {
    scanf("%d", &B[i]);
    }
    long long int ans = m(B, 0, n-1);
    printf("%lld", ans);
    return 0;
    } 
