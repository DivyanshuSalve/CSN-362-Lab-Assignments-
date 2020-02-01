#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main()
	{
		ifstream in;
		ofstream out;
		in.open("input.txt");
		out.open("output.txt");
		//if(in.is_open())
		bool prev_line_is_a_comment = false;
		bool consider_comment = true;	// cout<<" // this should not be ignored as it is not a comment";
		string String,Output;
		char prev='a';
		if(!in.is_open())
			cout<<"Error!! input file not opened";
		else if(!out.is_open())
			cout<<"Error!! output file not opened";
		else
		{
			while(!(in.eof()))
			{
				Output="";
				getline(in,String);
				int i;
				for(i=0;i<String.size();i++)
				{
					if(prev_line_is_a_comment)
					{
						while(i<String.size()&&String[i]!='*')
						{
							i++;
						}
						while(i<String.size()&&String[i]!='/')
						{
							i++;
						}
						if(i<String.size())
							prev_line_is_a_comment = false;
					}
					while(i<String.size()&&(String[i]!='/'||consider_comment == false))
					{
						if(String[i]!=' ')
							{
								if(String[i]=='"')
									consider_comment = !consider_comment;
								Output+=String[i];
								prev=String[i];
							}
						// else
						// 	prev=' ';
						i++;
					}
					if(i<String.size()&&String[i]=='/')
					{
						if(++i<String.size()&&String[i]=='/')
							{
								// while(String[++i]!='\n'||String[i]!='\n')
								// 	{
								// 		// increasing i until we get a new line
								// 	}
								break;
							}
						else if(String[i]=='*')
							{
								prev_line_is_a_comment = true;
								while(i+1<String.size()&&String[i+1]!='*')
								{
									i++;
								}
								while(i+1<String.size())
								{
									i++;
									if(i<String.size()&&String[i]=='/')
									{
										prev_line_is_a_comment = false;
										//i++;
										break;
									}
								}
							}
								
					}
				}
				out<<Output;
			}
		}
		in.close();
		out.close();
		return 0;
	}