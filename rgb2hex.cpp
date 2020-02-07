#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

int r,g,b,a=0,c,n=0;
int mas[768]={};

int main()
{
	ifstream input("data.rgb");
	ofstream output("splash.hex");
	cout<<"Creating ColorTable..."<<endl;
	for (int i=0;i<768;i+=3)
	{
		a++;
		cout<<"Color "<<a<<"."<<endl;
		skippp:
		n++;
		if (n>64000)
		{
			goto skipppp;
		}
		input>>r;
		input>>g;
		input>>b;
		for (int j=0;j<768;j+=3)
		{
			if (mas[j]==r)
			{
				if (mas[j+1]==g)
				{
					if (mas[j+2]==b)
					{
						goto skippp;
					}
				}
			}
		}
		skipppp:
		mas[i]=r;
		mas[i+1]=g;
		mas[i+2]=b;
		c=(r*64)/256;
		if (c<16)
		{
			output<<"0"<<hex<<c<<endl;
		}
		else
		{
			output<<hex<<c<<endl;
		}
		c=(g*64)/256;
		if (c<16)
		{
			output<<"0"<<hex<<c<<endl;
		}
		else
		{
			output<<hex<<c<<endl;
		}
		c=(b*64)/256;
		if (c<16)
		{
			output<<"0"<<hex<<c<<endl;
		}
		else
		{
			output<<hex<<c<<endl;
		}
	}
	n=0;
	input.close();
	input.clear();
	input.open("data.rgb");
	cout<<"Processing..."<<endl;
	while (!input.eof())
	{
		skip:
		n++;
		if (n>64000)
		{
			goto skipp;
		}
		a=0;
		input>>r;
		input>>g;
		input>>b;
		for (int i=0;i<768;i+=3)
		{
			if (mas[i]==r)
			{
				if (mas[i+1]==g)
				{
					if (mas[i+2]==b)
					{
						if (a<16)
						{
							output<<"0"<<hex<<a<<endl;
						}
						else
						{
							output<<hex<<a<<endl;
						}
						goto skip;
					}
				}
			}
			a++;
		}
	}
	skipp:
	input.close();
	output.close();
}
