#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>

class student
{  public:
	int index;
	int candies;
};

class range_element
{
   public:
   	int range;
   	int start;  //start_index
   	int end;    //end_index
   	int last_rating;  //rating of last student in range list

};

void evaluate(vector<int> rating,student** stud_list)
{
      for(int range=1;range<=rating.size();range++)   //to specify range of subproblem
      {
             for(int begin=0;begin<rating.size()-range;begin++) //to specify beginning of subproblem
             {
                  	
             }          
      }
}

int main()
{
	int n;
	cin>>n;
	student** stud_list=new student*[n];
	vector<int> rating;
	for(int i=0;i<n;i++)
	{   int temp;
		cin>>temp;
		rating.push_back(temp);
        stud_list[i]->index=i;         //initialize
        stud_list[i]->candies=0;
		n--;
	}
    
    evaluate(rating,stud_list);    
    
    //evaluate sum of candies..
    int sum=0;
    for(int i=0;i<n;i++)
    	sum+=stud_list[i]->candies;
    cout<<sum<<endl;
	return 0;
}