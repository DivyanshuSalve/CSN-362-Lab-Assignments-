#include<iostream>
#include<string>

using namespace std;

int main()
	{
		string String;
		cout<<"please enter the string \n";
		getline(cin,String);
		bool a,ab,abb; //a* , a*b+ , abb//
		a = true;
		ab = abb = false;
		bool b = false;		// remains false until we encounter first b in the string;
		int count_a = 0;
		int count_b = 0;
		if(!String.size())
			/*do nothing*/;
		else{
			for(int i=0;i<String.size();i++)
				{
					if(String[i] == 'a')
						{
							if(b==true)
								{
									a = ab = abb = false;
									break;
								}
							count_a++;
							if(count_a>1)
								abb = false;
						}
					else
						{
							ab = true;
							b = true;
							a = false;
							count_b++;
							if(count_a==1&&count_b==2)
								abb = true;
							else
								abb = false;
						}
				}
			}
		cout<<"The given string is";
		if(!a&&!ab&&!abb)
			cout<<" not acceptable under any of the given rules";
		else if(a)
			cout<<" acceptable under a*";
		else if(abb)
			cout<<" acceptable under a*b+ and abb";
		else
			cout<<" acceptable under a*b+";
	}