#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>

int find_max_path(vector<vector<int> > &input,vector<vector<int> > &table,int i,int j)
{
     if(table[i][j]!=-1)
     	return table[i][j];

     table[i][j]=0;

     if(i==input.size()-1)
     	table[i][j]=input[i][j];
     else
     {
        //choose either of the two paths
        int temp;
        temp=input[i][j]+find_max_path(input,table,i+1,j);
        temp=max(temp,input[i][j]+find_max_path(input,table,i+1,j+1));
        table[i][j]=temp;
     }
     return table[i][j];
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int lines,k,j,temp,z;
		cin>>lines;
		vector<vector<int> > input(lines),table(lines);
		for(j=0;j<lines;j++)
		{   
			table[j].resize(j+1);
			input[j].resize(j+1);
		    k=j+1;
			z=0;
			while(z<k)
			{    
				 table[j][z]=-1;
                 cin>>temp;
                 input[j][z]=temp;
                 z++;
            }
		}
		cout<<find_max_path(input,table,0,0)<<endl;
	}
}