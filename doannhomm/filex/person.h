#include<bits/stdc++.h>
using namespace std;
class PerSon {
	public:
		int  birtday ;
		string name , address, id, tel;
		void input()
	{
	fflush(stdin);
	cout<<"|  Nhap name : ";
	getline(cin, name);
	fflush(stdin);
	cout<<"|  Nhap address : ";
	getline(cin, address);
	cout<<"|  Nhap id : ";cin>>id;
	cout<<"|  Nhap birtday : ";cin>>birtday;
	cout<<"|  Nhap tel : ";cin>>tel;
	}
	void output()
	{
	cout<<"+---------------------------------------------------------------+\n";
	cout << "|" << left << setw(35) << "ID:" << setw(20) << this->id << right << setw(10) << " |" << endl;
	cout << "|" << left << setw(35) << "Name:" << setw(20) << this->name << right << setw(10) << " |" << endl;
	cout << "|" << left << setw(35) << "Address:" << setw(20) << this->address << right << setw(10) << " |" << endl;
	cout << "|" << left << setw(35) << "Tel:" << setw(20) << this->tel << right << setw(10) << " |" << endl;
	cout << "|" << left << setw(35) << "Birthday:" << setw(20) << this->birtday << right << setw(10) << " |" << endl;
	cout<<"--  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  --\n";
	}
//=============================================================================================================
};
