#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

void printMat(vector< vector< vector<int> > > input)
{
	vector< vector< vector<int> > >::iterator x;
	vector< vector<int> >::iterator y;
	vector<int>::iterator z;
	int idx=0;
	
	for(x=input.begin(),idx=0;x!=input.end();++x,++idx)
	{
		cout<<"index : "<<idx<<endl;
		for(y=x->begin();y!=x->end();++y)
		{
			for(z=y->begin();z!=y->end();++z)
			{
				cout<<*z<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}

vector< vector< vector<int> > > initMat(int idx)
{
	vector< vector< vector<int> > > result;
	vector< vector<int> > multiMat;
	vector<int> Mat;
	Mat.push_back(1);
	Mat.push_back(0);
	multiMat.push_back(Mat);
	Mat.clear();
	Mat.push_back(0);
	Mat.push_back(1);
	multiMat.push_back(Mat);
	Mat.clear();
	result.push_back(multiMat);//index 0
	multiMat.clear();
	
	Mat.push_back(1);
	Mat.push_back(1);
	multiMat.push_back(Mat);
	Mat.clear();
	Mat.push_back(1);
	Mat.push_back(0);
	multiMat.push_back(Mat);
	Mat.clear();
	result.push_back(multiMat);//index 1
	multiMat.clear();
	
	Mat.push_back(0);
	Mat.push_back(0);
	multiMat.push_back(Mat);
	Mat.clear();
	Mat.push_back(0);
	Mat.push_back(0);
	multiMat.push_back(Mat);
	Mat.clear();
	int count=0;
	for(count=2;count<idx+1;++count)
	{
		result.push_back(multiMat);
	}
//	printMat(result);
	return result;
}

vector< vector<int> > calMat(vector< vector<int> > front, vector< vector<int> > behind)
{
	vector< vector<int> > result;
	vector<int> input;
	int a=front[0][0];
	int b=front[0][1];
	int c=front[1][0];
	int d=front[1][1];
	int e=behind[0][0];
	int f=behind[0][1];
	int g=behind[1][0];
	int h=behind[1][1];
	
	input.push_back(a*e+b*g);
	input.push_back(a*f+b*h);
	result.push_back(input);
	input.clear();
	input.push_back(c*e+d*g);
	input.push_back(c*f+d*h);
	result.push_back(input);

	return result;
}

int* calMat01(int front[2][2], int behind[2][2])
{/*
	int result[2][2];
	int a=front[0][0];
	int b=front[0][1];
	int c=front[1][0];
	int d=front[1][1];
	int e=behind[0][0];
	int f=behind[0][1];
	int g=behind[1][0];
	int h=behind[1][1];
	
	result[0][0]=(a*e+b*g);
	result[0][1]=(a*f+b*h);
	result[1][0]=(c*e+d*g);
	result[1][1]=(c*f+d*h);

	return *result;*/
}

int pybonacci(int idx)
{
	int num=0;
	int result=0;
	vector<int> init;
	vector< vector<int> > fn;
	vector<int> restore;
	vector<int>::iterator itr;
	
	init.push_back(1);
	init.push_back(1);
	fn.push_back(init);
	init.clear();
	init.push_back(1);
	init.push_back(0);
	fn.push_back(init);
	init.clear();
	
	for(num=0;num<idx;++num)
	{
		init.push_back(0);
	}
	*(init.begin()+1)=1;
	*(init.begin()+2)=1;

	while(idx>1)
	{
		if(idx%2)
		{
			restore.insert(restore.begin(),idx%2);
		}
		idx-=idx%2;
		idx/=2;
		restore.insert(restore.begin(),idx);
	}

	for(itr=restore.begin();itr!=restore.end();++itr)
	{

	}

	return result;
}

int pybonacci01(int idx)
{
	vector< vector< vector<int> > > fiboN;
	vector< vector<int> > input;
	vector<int> restore (1,idx);
	vector<int>::iterator itr;
//	fiboN.insert(fiboN.begin(),{{1,0},{0,1}});
//	fiboN.insert(fiboN.begin()+1,{{1,1},{1,0}});
//	fiboN.insert(fiboN.begin()+2,idx,{{0,0},{0,0}});
	int num=idx;
	
	while(num/2>1)
	{
		num-=num%2;
		num/=2;
		restore.insert(restore.begin(),num);
	}
	
	for(itr=restore.begin();itr!=restore.end();++itr)
	{
//		input=catMat( *(fiboN.begin() + *(itr)/2 ),*( fiboN.begin() + *(itr)/2 ));
		input=calMat(input, *(fiboN.begin() + *(itr)%2 ));
		*(fiboN.begin()+ *(itr))=input;
	}
	cout<< fiboN[idx][0][1]<<endl;

	return fiboN[idx][0][1];
}

int pybonacci02(int idx)
{/*
	fiboN[idx][2][2]={};
	input[2][2]={0};
	vector<int> restore (1,idx);
	vector<int>::iterator itr;
	fiboN[0]={{1,0},{0,1}}
	fiboN[1]={{1,1},{1,0}}
	int num=idx;
	
	while(num/2>1)
	{
		num-=num%2;
		num/=2;
		restore.insert(restore.begin(),num);
	}
	
	for(itr=restore.begin();itr!=restore.end();++itr)
	{
		input=catMat01( fiboN[*(itr)/2] ), fiboN[*(itr)/2] );
		input=calMat01( input, fiboN[*(itr)%2] ));
		fiboN[*(itr)]=input;
	}
	cout<< fiboN[idx][0][1]<<endl;

	return fiboN[idx][0][1];*/
}

int pybonacci03(int idx)
{
	vector< vector< vector<int> > > fiboN;
	vector< vector<int> > input;
	vector<int> restore (1,idx);
	vector<int>::iterator itr;
	int num=idx;
	fiboN=initMat(idx);
	
	while(num/2>1)
	{
		num-=num%2;
		num/=2;
		restore.insert(restore.begin(),num);
	}
	
	for(itr=restore.begin();itr!=restore.end();++itr)
	{
		input=calMat( *(fiboN.begin() + *(itr)/2 ),*( fiboN.begin() + *(itr)/2 ));
		input=calMat(input, *(fiboN.begin() + *(itr)%2 ));
		*(fiboN.begin()+ *(itr))=input;
	}
	printMat(fiboN);

	return fiboN[idx][0][1];
}

void pybo_test(void)
{
	int output=0;
//	output=pybonacci(rand()%100);
	output=pybonacci03(31);
	cout<<output<<endl;
}

void cal_test(void)
{
	vector< vector<int> > front;
	vector< vector<int> > behind;
	vector< vector<int> > mat;
	vector<int> input;
	
	input.push_back(1);
	input.push_back(0);
	front.push_back(input);
	input.clear();
	input.push_back(0);
	input.push_back(1);
	front.push_back(input);
	input.clear();
	
	input.push_back(3);
	input.push_back(1);
	behind.push_back(input);
	input.clear();
	input.push_back(2);
	input.push_back(4);
	behind.push_back(input);
	
	mat=calMat(front, behind);
	
	vector< vector<int> >::iterator row;
	vector<int>::iterator col;
	for(row=mat.begin();row!=mat.end();++row)
	{
		for(col=row->begin();col!=row->end();++col)
		{
			cout<<*col<<" | ";
		}
		cout<<endl;
	}
}

int main(void)
{
	pybo_test();
//	cal_test();
	return 0;
}
