#include <iostream>
using namespace std;
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

int main()
{
	string input,space_removed="",output="";
	getline(cin,input);
	int space=count(input.begin(),input.end(),' ');
	int row=floor(sqrt(input.length()-space));
	int col=ceil(sqrt(input.length()-space));
	while(row*col<(input.length()-space))
       row++;
	//cout<<"row:"<<row<<" col:"<<col<<endl;
	vector<vector<char> > table(row);

	for(int i=0;i<input.length();i++)
	{
		if(!isspace(input[i]))
			space_removed+=input[i];
	}

    int z=0;
    int j=0;
    for(int i=0;i<row;i++)
    {j=0;
       while(z!=space_removed.length()&&j<col)
       {	
       	table[i].push_back(space_removed[z++]);
        j++;
       }
    }
 //   cout<<"j:"<<j<<endl;
    for(int i=0;i<col;i++)
    {
    	int end=(i<j)?row:row-1;
    	//cout<<"end:"<<end<<endl;
    	for(int z=0;z<end;z++)
    		cout<<table[z][i];
      cout<<" ";
    }

}