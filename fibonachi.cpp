#include <vector>
#include <iostream>
#include <string>
#include <cmath>

#define	CRLF	"\n"

using namespace std;

long long fibo_01(int n)
{
	long long answer=0;
	int count=2;
	long long fib[100]={0,1};
	
	while(count<=n)
	{
		fib[count]=fib[count-1]+fib[count-2];
		++count;
	}
	
	answer=fib[n];
	
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

vector< vector<int> > FN;
vector<int> set;

int fibor01(int n)
{
    int answer = 0;
    vector< vector<int> >::iterator row;
    vector<int>::iterator col;    
    
    if(n<2)
    {
        answer=n;
    }
    else
    {
        for(row=FN.begin();row!=FN.end();++row)
        {
            col=row->begin();
            if(n==(*col))
            {
                return (*(col+1));
            }
        }
        answer=(fibor01(n-1)+fibor01(n-2));
    }
    set.push_back(n);
    set.push_back(answer);
    FN.push_back(set);
    set.clear();
//    cout<<answer<<endl;
    return answer;
}

void fn( int n )
{
	if ( n == 0 )
		return ;
		
	printf( "%4d", n ) ;
	fn( n-1) ;
}

void fibor_test( int N = 30 )
{
	printf( "fibor_test()" ) ; printf( CRLF ) ;
	for ( int i=1; i<( N+1 ) ; i++ ) 
	{
		cout<< fibor01( i )<<endl ;
	}
}

void fn_test( ) 
{
	printf( "fn_test()" ) ; printf( CRLF ) ;
	fn( 30 ) ;
}

void fibo_test(void)
{
	long long answer=0;
	int idx=30;
	answer=fibo_01(idx);
	cout<<"common repeat fibonachi index : "<<idx<<", result : "<<answer<<endl;
}

int main(void)
{
	fibor_test();
//	fn_test();
	fibo_test();

	return 0;
}
