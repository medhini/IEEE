#include <stdio.h>
#include <conio.h>
 
 void mergesort(int a[], int l, int h)
{
 int i = 0;
 int len = h-l+1 ;
 int mid  = 0;
 int merge1 = 0;
 int merge2 = 0;
 int temp[100];
 
 if(l == h)
 return;
 
 mid  = (l + h) / 2;
 
 mergesort(a, l, mid);
 mergesort(a, mid + 1, h);
 
 for(i = 0; i < len; i++)
 {
  temp[i] = a[l + i];
 }
 
 merge1 = 0;
 merge2 = mid - l + 1;
 
 for(i = 0; i < len; i++)
 {
  if(merge2 <= h - l)
  {
   if(merge1 <= mid - l)
   {
    if(temp[merge1] > temp[merge2])
    {
     a[i + l] = temp[merge2++];
    }
 
    else
    {
     a[i + l] = temp[merge1++];
    }
   }
 
   else
   {
    a[i + l] = temp[merge2++];
   }
  }
 
  else
  {
   a[i + l] = temp[merge1++];
  }
 }
return;
}
 
 main()
{
 int a[100],n,i = 0;
 scanf("%d",&n);
 
 for(i = 0 ; i < n ; i++ )
  scanf("%d",&a[i]);
 
 mergesort(a, 0, n - 1);
 
 for(i = 0; i < n; i++)
 {
  printf("%d", a[i]);
 }
}
 

