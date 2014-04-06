#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int find_min_rotate_time(int start_index,int end_index,int col)
{
    return min(abs(end_index-start_index),col-abs(end_index-start_index));
}


class VendingMachine {
public:
	int motorUse(vector <string> prices, vector <string> purchases) 
	{
        vector<vector<int> > price_table(prices.size());  //setting row of table
        for(int i=0;i<prices.size();i++)
        {
        	//prices[i] extract prices and push_back
        	stringstream obj;
        	obj<<prices[i];
        	int temp;
        	while(obj>>temp)
        		price_table[i].push_back(temp);
        }	 

        //2d table created.
        int row=price_table.size();
        int col=price_table[0].size();;

       //setting the initial column prize array
        int max_column_index=0,max_column_price=INT_MIN;           //for finding out where to rotate to after each purchase
        vector<int> column_price(col);
        for(int i=0;i<col;i++)
        {
            for(int j=0;j<row;j++)
                column_price[i]+=price_table[j][i];
            if(column_price[i]>max_column_price)             //finding max_priced column.
            {
                max_column_index=i;
                max_column_price=column_price[i];
            }
        };

        int cur_column_index=0;                               //starting column;
        int tim=0;                                        //to measure total time
        int last_time=0;                                  //to calculate delay 

        //first,rotate to expensive column
        tim+=find_min_rotate_time(0,max_column_index,col);  //considering clock and anti-clock      
        cur_column_index=max_column_index;
        
        //cout<<"rotating initially to "<<max_column_index<<endl;
        //cout<<"time:"<<tim<<endl;

        //now consider each purchase query one by one
        for(int i=0;i<purchases.size();i++)
        {
            //consider ith query
            int shelf,column,call_time;
            char temp_char;               //to extract , and :
            stringstream obj1;
            obj1<<purchases[i];
            obj1>>shelf>>temp_char>>column>>temp_char>>call_time;

            //values extracted..
          //  cout<<"shelf:"<<shelf<<" column:"<<column<<" time:"<<call_time<<endl;
            
            //if delay greater than 5 minutes,rotate to expensive column..avoid this check for first purchase
            if(i!=0&&(call_time-last_time>=5))
            {
            //    cout<<"rotating to maximum column index :"<<max_column_index<<endl;
                tim+=find_min_rotate_time(cur_column_index,max_column_index,col);
            //    cout<<"time:"<<tim<<endl;
                cur_column_index=max_column_index;
            }
           
            //now rotate to the queried column
                tim+=find_min_rotate_time(cur_column_index,column,col);
             //   cout<<"rotating to queried column "<<column<<endl;
             //   cout<<"time:"<<tim<<endl;
                cur_column_index=column;
             
             //check if that shelf contains value 0 ,means already purchased
             if(price_table[shelf][column]==0)
                   return -1;

            //now we have to edit column_prize and max_column_price before purchasing it
            column_price[column]-=price_table[shelf][column];//sum changed
            if(max_column_price<column_price[column])        //editing max_value
            {
                max_column_index=column;
                max_column_price=column_price[column];
            }         
      //      cout<<"after this loop,maximum column sum is "<<max_column_price<<endl;
      //      cout<<"after this loop,maximum column index is "<<max_column_index<<endl;
            cout<<endl;         
            price_table[shelf][column]=0;                   //purchasing it;
            last_time=call_time;

        //after all purchase,go back to maximum value again
       // cout<<"after all transactions,rotating back to maximum column index:"<<max_column_index<<endl;
        tim+=find_min_rotate_time(cur_column_index,max_column_index,col);
       // cout<<" final time:"<<tim<<endl;
        cur_column_index=max_column_index;


        return tim; 
	}
    
};

int main()
{
	VendingMachine obj;
	
    vector<string> prices;
    const char *price_strings[]={"100 200 300","600 500 400"};
	prices.assign(price_strings,price_strings+sizeof(price_strings)/sizeof(price_strings[0]));
	
    vector<string> purchases;
	const char* purchase_queries[]={"0,0:0", "1,1:10", "1,2:20", "0,1:21", "1,0:22", "0,2:35"};
    purchases.assign(purchase_queries,purchase_queries+sizeof(purchase_queries)/sizeof(purchase_queries[0]));

	cout<<obj.motorUse(prices,purchases);
    return 0;
}