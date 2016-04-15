
#include<stdio.h>

#define MAXSIZE 100
#define ERRCODE_OVERFLOW -2
#define ERRCODE_UNDERFLOW -1  

int mempad[MAXSIZE] = {-1};
int fibo(int );

int fibo(int N)
{	if(N>=0)
	{
		if(N>MAXSIZE)
		{
			printf(" Exceeded MAXSIZE : %d \n", MAXSIZE); 
			return ERRCODE_OVERFLOW;
		}        
		else if(N <=1)
			return N;
		else if(mempad[N])
			return mempad[N];
		else	
		{
			mempad[N] = fibo (N-1) + fibo(N-2);
			return mempad[N];    
		}
	} 
   	else
      return ERRCODE_UNDERFLOW;
}

int main(void)
{
	int N;
    	printf("Enter the fibonaci term you want : ");
   	  scanf("%d", &N);
	
	int num = fibo(N-1);
	if(num>=0)
   		printf("Fibonaci number : %d\n", num);
}
