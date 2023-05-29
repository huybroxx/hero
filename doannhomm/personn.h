#include<iostream>
using namespace std;
class PerSonn {
	public:
		int id , birtday , tel ;
		string name , address;
		virtual void input();
		virtual void output();
};
void PerSonn::input()
{
	fflush(stdin);
	cout<<" nhap name : ";
	getline(cin, name);
	fflush(stdin);
	cout<<" nhap address : ";
	getline(cin, address);
	cout<<" nhap id : ";cin>>id;
	cout<<" nhap birtday : ";cin>>birtday;
	cout<<" nhap tel : ";cin>>tel;
}
void PerSonn::output()
{
	cout<<" id "<<id<<endl;
	cout<<" name : "<<name<<endl;
	cout<<" address : "<<address<<endl;
	cout<<" tel : "<<tel<<endl;
	cout<<" birtday : "<<birtday<<endl;
}

