int d;
cin>>d;

int cur_value=d;
bool first=true;
while(cur_value!=d||first)
{
	if(first) first=false;
	int sum=cur_value/10+cur_value%10;
	new_sum=sum%10+10*(d%10);
	cur_value=new_sum;
}
