#include<stdio.h>
#include<math.h>
int Prime_number();
int N_primenumbers();
int Primenumbers_upto_N();
int Palindrome();
int Armstrong ();
int Perfect_number();
int Strong_number();
int Factorial_upto_20();
int Anagram();
int Anagram_factorial();
int Unique_digit ();
void main()
{
	//Prime_number();
	//N_primenumbers();
	//Primenumbers_upto_N();
	//Palindrome();
	Armstrong ();
	//Perfect_number();
	//Strong_number();
	//Factorial_upto_20();
	//Anagram();
	//Anagram_factorial();
	//Unique_digit ();
}
//1 Prime number
int Prime_number()
{
	int N,fact=0,i=1;
	printf("Enter a number:");
	scanf("%d",&N);
	while(i<=N)
	{
		if(N%i==0)
		{
			fact=fact+1;
		}
		 i=i+1;	
	}	
	if(fact==2)
		printf("prime number\n");
	else
		printf("Not prime number\n");
}
//2 N-PRIME NUMBERS
int N_primenumbers()
{
	int n,i=1,j,fact,c=0;
	printf("\nEnter how many prime numbers you want:");
	scanf("%d",&n);
	while (c<n)
	{
		fact=0;
		for (j=1;j<=i;j++)
		{
			if ((i%j)==0)
				fact+=1;
		}
		if (fact==2)
		{
			printf("%d ",i );
			c++;
		}
		i++;
	}
	printf("\n");
}
//3 PRIME NUMBERS upto N
int Primenumbers_upto_N()
{
	int n,i,j,fact,c=0;
	printf("\nYou want prime numbers upto:");
	scanf("%d",&n);
	i=1;
	while (i<=n)
	{
		fact=0;
		for (j=1;j<=i;j++)
		{
			if ((i%j)==0)
				fact+=1;
		}
		if (fact==2)
			printf("%d ",i);
	i++;
	}
	printf("\n");
}
//4 Palindrome
int Palindrome()
{
	int N1,Q,R,rev=0,K;
	printf("\nEnter a number:");
	scanf("%d",&N1);
	K=N1;
	while(N1>0)
	{
		R=N1%10;
		Q=N1/10;
		N1=Q;
		rev=rev*10+R;
	}
	if(rev==K)
		printf("palindrome\n");
	else
		printf("Not palindrome\n");
}
// Armstrong number
int Armstrong ()
{
	int n,r,c=0,t=0,m,main;
	printf("Enter a number:");
	scanf("%d",&n);
	main=m=n;
	while(n>0){
		r=n%10;c++;n=n/10;
		if (n==0){
			while(m>0){
				r=m%10;
				t+=pow(r,c);
				m=m/10;
			}
		}
	}
if (t==main)
	printf("It is an Amstrong number\n");
else
	printf("It is not an Amstrong number\n");
}
//5 perfect number
int Perfect_number()
{
	int N2,fact_sum=0,j=1;
	printf("\nEnter a number:");
	scanf("%d",&N2);
	while(j<=(N2/2))
	{
		if(N2%j==0)
		{
			fact_sum=fact_sum+j;
		}
		j+=1;
	}
	if(fact_sum==N2)
		printf("perfect number\n");
	else
		printf("Not a perfect number\n");
}
//6 Strong number
int Strong_number()
{
	int n,R1,Q1,i1,k1,fact1,sum;
	sum=0;
	printf("\nEnter the number:");
	scanf("%d",&n);
	k1=n;
	for (;n>0;)
	{
		R1=n%10;
		fact1=1;
		for(i1=1;i1<=R1;i1++)
		{
			fact1*=i1;	
		}
		sum+=fact1;
		Q1=n/10;
		n=Q1;
	}
	if(sum==k1)
		printf("strong number\n");
	else
		printf("Not strong number\n");
}
//7 Factorial_upto_20
int Factorial_upto_20()
{
	long long int N3,k,factorial=1;
	printf("\nEnter the number:");
	scanf("%lld",&N3);
	if(N3>=0&&N3<=20)
	{
		for(k=1;k<=N3;k++)	
		{
			factorial*=k;		
		}
	printf("%d factorial is %lld \n",N3,factorial);
	}
	else
		printf("Enter correct number\n");
}

//8 Anagram
int Anagram()
{
	int n1,n2,c1=0,c2=0,c3=0,c4=0,r1,r2,s1=0,s2=0;
	printf("\nEnter first number:");
	scanf("%d",&n1);
	printf("Enter second number:");
	scanf("%d",&n2);
	int N1=n1,N2=n2,M1=n1,M2=n2;
	while (n1>0)
	{
		r1=n1%10;
		n1=n1/10;
		c1+=1;
		s1+=r1;
	}
	while (n2>0)
	{
		r2=n2%10;
		n2=n2/10;
		c2+=1;
		s2+=r2;
	}
	if (c1!=c2)
		printf("It is not an anagram");
	else
	{
		while(N1>0)
		{
			r1=N1%10;
			N2=M2;
			while(N2>0)
			{
				r2=N2%10;
				if (r1==r2)
				{
					c3+=1;
					break;
				}
				N2=N2/10;
			}
			N1=N1/10;
		}
		N2=M2;
		N1=M1;
		while(N2>0)
		{
			r2=N2%10;
			N1=M1;
			while(N1>0)
			{
				r1=N1%10;
				if (r2==r1)
				{
					c4+=1;
					break;
				}
				N1=N1/10;
			}
			N2=N2/10;
		}
		if (c3==c4 && s1==s2 &&c3!=0 &&c4)
			printf("It is an anagram\n");
		else
			printf("It is not an anagram\n");
	}
}
//9 Anagram using factorial
int Anagram_factorial()
{
	int n1,n2,c1=0,c2=0,r1,r2,s1=0,s2=0,i,fact1,fact2,sum1=0,sum2=0;
	printf("\nEnter first number:");
	scanf("%d",&n1); 
	printf("Enter second number:");
	scanf("%d",&n2);
	while (n1>0)
	{
		r1=n1%10;
		s1+=r1;
		c1+=1;
		i=1;fact1=1;
		while (i<=r1)
		{
			fact1*=i;
			i++;
		}
		sum1+=fact1;
		n1=n1/10;
	}
	while (n2>0)
	{
		r2=n2%10;
		s2+=r2;
		c2+=1;
		i=1;fact2=1;
		while (i<=r2)
		{
			fact2*=i;
			i++;
		}
		sum2+=fact2;
		n2=n2/10;
	}
	if (c1==c2 && sum1==sum2 && s1==s2)
		printf("It is  an anagram\n");
	else
		printf("It is not an anagram\n");
}
//10 Unique digit
int Unique_digit()
{
	int n,sum=0,r,r1,k=0,c=0;
	printf("\nEnter a number:");
	scanf("%d",&n);
	while (1)
	{
		while(n>0)
		{
			r=n%10;
			sum+=r;
			n=n/10;
		}
		if (sum>10)
		{
			int sum1=sum,sum2=sum;
			n=sum;
			c=0;
			while(n>0)
			{
				r1=n%10;
				sum1=sum2;
				while (sum1>0)
				{
					r=sum1%10;
					if (r1==r)
						c+=1;
					sum1=sum1/10;
				}
				n=n/10;
				k+=1;
			}
			if(c==k)
			{
				printf("sum is %d\n",sum2);
				break;
			}
			else
			{
				n=sum2;
				sum=0;
			}
		}
		else
		{
			printf("sum is %d\n",sum);
			break;
		}
	}
}


