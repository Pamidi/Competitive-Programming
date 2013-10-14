#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

bool reach_boundary(vector<string> maze,bool** visit_check,const int i,const int j,int flag)  //flag=1 if calling block not on boundary
{ 
  const int row=maze.size();
  const int col=maze[0].length();
  
  if(i<0||i>row-1||j<0||j>col-1)                         //beyond boundary
         {return true;}  
  
  if(visit_check[i][j])                                  //if already visited
      {return false;}
  visit_check[i][j]=true;
  
  
   if(flag==0&&(i==0||i==row-1||j==0||j==col-1))          //if calling wall on the boundary
      {return true;} 
  if(flag==1&&(i==0||i==row-1||j==0||j==col-1)&&maze[i][j]=='.')          //if dot on the boundary
      {return true; }
  if(flag==1&&maze[i][j]=='#')                           //blocked by outer wall.
     {visit_check[i][j]=true;  return false;} 
  
  if(reach_boundary(maze,visit_check,i+1,j,1)||reach_boundary(maze,visit_check,i-1,j,1)||reach_boundary(maze,visit_check,i,j-1,1)||reach_boundary(maze,visit_check,i,j+1,1))
      {return true;}
  else
      {return false;}

}

bool** initialize(const int row,const int col)
{
  bool** visit_check=new bool*[row];
  for(int i=0;i<row;i++)
    visit_check[i]=new bool[col];
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
      visit_check[i][j]=false;
  return visit_check;
}

class TroytownKeeper {
public:
    int limeLiters(vector <string> maze)
    {  
      int paint_wall=0;
       const int row=maze.size();
       const int col=maze[0].length();
       for(int i=0;i<row;i++)
       {
         
        for(int j=0;j<col;j++)
        {
           if(maze[i][j]=='.')                   //we are processing only walls
            continue;
           //check if wall is reachable from boundary
           
           if(reach_boundary(maze,initialize(row,col),i,j,0))
           {
               if(reach_boundary(maze,initialize(row,col),i,j-1,1)) paint_wall++;
               if(reach_boundary(maze,initialize(row,col),i,j+1,1)) paint_wall++;
               if(reach_boundary(maze,initialize(row,col),i-1,j,1)) paint_wall++;
               if(reach_boundary(maze,initialize(row,col),i+1,j,1)) paint_wall++;
           }
        }
       }
       return paint_wall;
    }
};
int main()
    {
        TroytownKeeper a;
        vector<string> b;
        b.push_back("#.#.#.#");
        b.push_back(".#.#.#.");
        b.push_back("#.#.#.#");
        b.push_back(".#.#.#.");
      
      //  b.push_back("#.#.#");
       // b.push_back("#####");
        cout<<a.limeLiters(b)<<endl;
        return 0;
    }
