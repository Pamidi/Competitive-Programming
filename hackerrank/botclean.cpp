#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
/* Head ends here */
string get_xstring(bool right)
{
    if(right)return "RIGHT";
    else return "LEFT";
}
string get_ystring(bool top)
{
if(top) return "UP";
    else return "DOWN";
}


void next_move(int posx, int posy, vector <string> board)
{
    int p,i,j,x_diff,y_diff;
    bool right,top;
    if(board[posy][posx]=='d')
        cout<<"CLEAN"<<endl;
    else
    {
        for(i=0;i<board.size();i++)
        {   
            p=board[i].find('d');
            if(p!=string::npos)
                break;
        }
        if(i==board.size()) return;
        x_diff=p-posx;//2
        y_diff=i-posy;//0
        if(x_diff>=0)
            right=true;
        else right=false;
        if(y_diff>=0)
            top=false;
        else top=true;

        if(x_diff!=0)
            cout<<get_xstring(right);
        else if(y_diff!=0)
            cout<<get_ystring(top);

    }
}
/* Tail starts here */
int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}