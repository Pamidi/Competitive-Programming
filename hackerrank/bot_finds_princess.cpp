#include <iostream>
#include <vector>
#include<cstring>
#include<cstdlib>
using namespace std;
/* Head ends here */

string find_xstring(bool top)
{
    if(top)
        return "UP";
    else
        return "DOWN";
}
string find_ystring(bool right)
{
if(right)
return "RIGHT";
else
return "LEFT";}

void displayPathtoPrincess(int n, vector <string> grid){
    //your logic here
  int p=string::npos,i=0;
    while(p==string::npos)
    {
       p=grid[i].find('p');
       i++;
    }
    int m_x,m_y,p_x,p_y,x_diff,y_diff,j;
    bool right,top;
    m_x=m_y=n/2;
    p_y=--i;
    p_x=p;
    x_diff=p_x-m_x;
    y_diff=p_y-m_y;
    if(x_diff>=0) right=true;
    else right=false;
    if(y_diff>=0) top=false;
    else top=true;

    for(i=0;i<abs(x_diff);i++)
        cout<<find_xstring(top)<<endl;
    for(j=0;j<abs(y_diff);j++)
         cout<<find_ystring(right)<<endl;
}
/* Tail starts here */
int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin>>s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}
