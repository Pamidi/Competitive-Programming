#include <iostream>

int n;

struct apple
{
	int a[n];
	apple()
	{
		cout<<"n:"<<n<<endl;
	}
};

int main()
{
	n=3;
    apple* a=new apple();
    return 0;
}