#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

#define v result[non_terminal]

map<char,vector<char>> result;

bool is_terminal(char c)
	{
		if('A'<=c&&c<='Z')
			return false;
		return true;
	}
void Find_terminals_for(char non_terminal, map<char,int> & done, map<char,vector<char>> &production_rule,int level) // 2 arguments;
	{
		// ** Remember ** when **done[non_terminal[i]** is 2 is is already explored
		if(done[non_terminal]==1 || level == 4)
		{
			return;
		}
		for(int i=0;i<production_rule[non_terminal].size();i++)
			{
				if(is_terminal(production_rule[non_terminal][i]))
					{
						if(find(v.begin(),v.end(),production_rule[non_terminal][i]) == v.end())	// v is defined on top
							{
								result[non_terminal].push_back(production_rule[non_terminal][i]);
							}
					}
				else
				{
					Find_terminals_for(production_rule[non_terminal][i], done, production_rule,level+1);
					/* map<char,vector<char>> production_rule */
					for(int j=0;j<result[production_rule[non_terminal][i]].size();j++)
						if(find(v.begin(),v.end(),result[production_rule[non_terminal][i]][j]) == v.end())
							result[non_terminal].push_back(result[production_rule[non_terminal][i]][j]);
				}
			}	
		done[non_terminal] = 1;
	}
int main()
	{
		cout<<"Enter number of production rules: ";
		int n;
		cin>>n;
		cout<<"Enter production rules: \n";
		string String[n];	// store all the production rules
		int temp = n;		
		map<char,int> done;	// if value is 1 then non-terminal, if 2 then non-terminal with all terminals resolved
		char non_terminal[n];	// array of not-terminals
		map<char,vector<char>> production_rule; // maps the non-terminals to production rules;
		while(n)
			{
				cin>>String[temp-n];
				non_terminal[temp-n] = String[temp-n][0];
				n--;
			}	
		n = temp;
		// **String** holds all the input lines
		// **production_rule** map non-terminals to every single production rule
		for(int i=0;i<n;i++)
			{
				for(int j=2;j<String[i].size();j++)
					{
						string single_rule = "";
						while(j<String[i].size()&&String[i][j]!='/')
							{
								single_rule+=String[i][j];
								j++;
							}
						production_rule[non_terminal[i]].push_back(single_rule[0]);
					}
			}
		// vector<vector<string>> result;
		for(int i=0;i<n;i++)
			{
				Find_terminals_for(non_terminal[i], done /*maps to 0 or 1*/, production_rule /* map nT to first_pos */,0); // 2 arguments
			}	
		for(int i=0;i<n;i++)
		{
			cout<<non_terminal[i]<<" - ";
			for(int j=0;j<result[non_terminal[i]].size();j++)
				cout<<result[non_terminal[i]][j]<<" ";
			cout<<"\n";
		}
	}