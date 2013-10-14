#include<iostream>
using namespace std;
#include<cstring>
#include<vector>
#include<cstdlib>

class InsertZ
{
public:
	string canTransform(string init,string	goal)
	{
        while(init!=goal&&init.length()<=goal.length())
        {   int found=goal.find("z");
        	if(found==string::npos)
        		return "No";
        	goal.erase(found,1);

        }
        if(init==goal)
        	return "Yes";
        else
        	return "No";
	}
};

int main()
{
	InsertZ a;
	cout<<a.canTransform("mvixrdnrpxowkasufnvxaq","mvizzxzzzrdzznzrpxozzwzzkazzzszzuzzfnvxzzzazzq");
	return 0;
}