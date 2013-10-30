#include <iostream>
using namespace std;
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>

int main()
{
	int n,i;
	cin>>n;

    vector<string> total{"CPP","C","JAVA","PYTHON","PERL","PHP","RUBY","CSHARP","HASKELL","CLOJURE","BASH","SCALA","ERLANG","CLISP","LUA","BRAINFUCK","JAVASCRIPT","GO","D","OCAML","R","PASCAL","SBCL","DART","GROOVY","OBJECTIVEC"};


	for(i=0;i<n;i++)
	{
        int id;
        string req;
        cin>>id>>req;
        vector<string>::iterator it=find(total.begin(),total.end(),req);
        if(it==total.end())
           cout<<"INVALID"<<endl;
        else
           cout<<"VALID"<<endl;      
	}
    



	return 0;
}