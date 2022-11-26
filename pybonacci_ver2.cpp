#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

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

void pybo_test(void)
{
	int output=0;
//	output=pybonacci(rand()%100);
	output=pybonacci(31);
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
