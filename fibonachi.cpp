#include <vector>
#include <iostream>
#include <string>
#include <cmath>

#define	CRLF	"\n"

using namespace std;

long long fibo_01(int n);
int fibo_02(int n);

long long fibo_01(int n)
{
	long long answer=0;
	int count=2;
	long long fib[100]={0,1};
	
	while(count<=n)
	{
		fib[count]=fib[count-1]+fib[count-2];
//		cout<<fib[count]<<endl;
		++count;
	}
	
	answer=fib[n];
	
	return answer;
}

int fibo_02(int n)
{
	int count=0;
	int answer=0;
	answer=fibo_02(count);
	
	return answer;
}

int fibor(int n)
{
	int f = n ;
	
	if ( n < 2  ) 
		return n ;
	else
		f = fibor( n-1 ) + fibor( n-2 ) ;
	
	return f ;
}

void fibor_test( int N = 5 )
{
	printf( "fibor_test()" ) ; printf( CRLF ) ;
	for ( int i=1; i<( N+1 ) ; i++ ) 
	{
		cout<< fibor( i )<<endl ;
	}
}


void fn( int n )
{
	if ( n == 0 )
		return ;
		
	printf( "%4d", n ) ;
	fn( n-1) ;
}

void fn_test( ) 
{
	printf( "fn_test()" ) ; printf( CRLF ) ;
	fn( 5 ) ;
}

int Unused(int n)
{
	return pow(2,n+1)-2-pow(2,n)-pow(2,n-1)-(n+1);
}

int main(void)
{
	long long answer=0;
	int unuse=0;
	
	answer=fibo_01(100);
	cout<<answer<<endl;
//	answer=fibo_02(10);
	
	fibor_test() ;
	fn_test() ;
	unuse=Unused(8);
	
	cout<<"\n"<<unuse<<endl;
	return 0;
}






