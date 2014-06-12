#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
  int n=2;
  //cin>>n;
  //cin.ignore();
  unordered_map<string,int> tag_row;
  vector<list<string> > tag_list;
  vector<string> all_tags;
      
  //while(n--)
  //{
      string s="<p><a href=http://www.quackit.com/html/tutorial/html_links.cfm>Example Link</a></p><div class=more-info><a href=http://www.quackit.com/html/examples/html_links_examples.cfm>More Link Examples...</a></div>";
      //getline(cin,s);
      unordered_map<string,int> tag_hash;
      int row_list=0;
      int k=s.length();
      for(long i=0;i<k;)
      {   
          if(s[i]=='<')
          {
             i++;
             while(isspace(s[i]))
                i++;    
             if(s[i]=='/')
             {
                 i++;
                 continue;
             }
             string cur_tag="";
             while(s[i]!=' '&&s[i]!='/'&&s[i]!='>')
                cur_tag+=s[i++];

             if(tag_hash[cur_tag]!=1)
             {
                tag_hash[cur_tag]=1;
                all_tags.push_back(cur_tag);
                list<string> cur_tag_attr;
                tag_list.push_back(cur_tag_attr);
                tag_row[cur_tag]=row_list;
                row_list++;
             }
             if(s[i]=='/')
               i++; 
            
             while(s[i]!='>')
             {
                 string cur_attr="";
                 while(s[i]==' ')
                    i++;
                 while(s[i]!='=')
                    cur_attr+=s[i++];
                 while(s[i]!=' '&&s[i]!='>')
                    i++;
                 
                 //we have one attribute here..just check it with already existing attributes
                 bool flag=true;
                 int row=tag_row[cur_tag];
                 for(list<string>::iterator it=tag_list[row].begin();it!=tag_list[row].end();++it)
                 {
                    if(*it==cur_attr)
                    {
                        flag=false;
                        break;
                    }
                 }  
                 
                 //insert cur_attr into the appropriate list
                 if(flag)
                      tag_list[tag_row[cur_tag]].push_front(cur_attr);
             }  //while             
      } //if
      i++;
   } //for
 //} //while
  sort(all_tags.begin(),all_tags.end());
  for(int i=0;i<all_tags.size();i++)
  {
      string tag=all_tags[i];
      //print tag_list[tag_row[tag]] list
      cout<<tag<<":";
      list<string>::iterator it;
      for(it=tag_list[tag_row[tag]].begin();it!=tag_list[tag_row[tag]].end();++it)
         cout<<*it<<","<<endl;
  }
}