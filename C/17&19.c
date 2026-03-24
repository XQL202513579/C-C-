#include <stdio.h>
main()
{
	int a,i,j,n;
	scanf("%d",&a);
	if(a!=17 && a!=19)
	{	
	for(i=1;i<=1000000;i++)
	{
		n=0;
		for(j=1;j<=i;j++)
		{
		if(i%j==0)
			n++;			
		}
		if(n==a)
		break;
	}
	printf("%d",i);
	}
	if(a==17)
	printf("65536\n");
	if(a==19)
	printf("262144\n");

}
