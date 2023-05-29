#include<bits/stdc++.h>
using namespace std;
#include"person.h"

class KhachHang:public PerSon{
	public:
	string loaiKhachHang;
	int  tichDiem, tienKhachHang;
	KhachHang(string ten, int sn, string tel, string id, string addr, string loai, double tichdiem, double tien){
		this->name=ten;
		this->birtday=sn;
		this->tel=tel;
		this->id=id;
		this->address=addr;
		this->loaiKhachHang=loai;
		this->tichDiem=tichdiem;
		this->tienKhachHang=tien;
	}
	KhachHang(){
	}
	void input();
	void output();	
};
void KhachHang::input()
{
	
	PerSon::input();
	cout<<"|  Nhap tich diem mac dinh : ";cin>>tichDiem;
	fflush(stdin);
	cout<<"|  Nhap loai khach hang : ";
	getline(cin, loaiKhachHang);
	cout<<"|  Nhap tien khach hang mac dinh : ";cin>>tienKhachHang;
}
void KhachHang::output()
{
	PerSon::output();

	//cout << setfill(' ') << "+" << setw(22) << "" << setfill(' ') << setw(20) << "" << setfill(' ') << setw(25) << "" << "+" << endl;

	cout << "|" << left << setw(35) << "Tich diem:" << setw(20) << tichDiem << right << setw(10) << " |" << endl;
    cout << "|" << left << setw(35) << "Loai khach hang:" << setw(20) << loaiKhachHang << right << setw(10) << " |" << endl;
	cout << "|" << left << setw(35) << "Tien khach hang da mua:" << setw(20) << tienKhachHang << right << setw(10) << " |" << endl;
    //cout << setfill(' ') << "+" << setw(22) << "" << setfill(' ') << setw(18) << "" << setfill(' ') << setw(22) << "" << "+" << endl;
}
class ListKhachHang{
	public: 
	vector<KhachHang> dskh;
	
	void themKhachhang(KhachHang hk) {
        dskh.push_back(hk);
    }
	
    void xoaKhachHang(int index) {
        dskh.erase(dskh.begin() + index);
    }
    void xoaAllKhachHang(){
		dskh.clear();
	}
    int getsoluongkh(){
    	return dskh.size();
	}
	void inkhachhangnew(){
		dskh[dskh.size()-1].output();
	}
	void danhSachKhachHang(){
		cout << "+================================================================+\n";
        for (int i = 0; i < dskh.size(); i++) {
        	cout<<"\nThong tin khach hang thu "<<i+1<<": \n";
           	dskh[i].output();
			cout << "+---------------------------------------------------------------+\n";
        }
        //cout << "+================================================================+\n";
	}
	void khachHangVipNhat(){
		KhachHang vip= dskh[0];
		for(int i=0; i< dskh.size(); i++){
			if (dskh[i].tienKhachHang>vip.tienKhachHang)
				vip=dskh[i];
		}
		vip.output();
	}
};
//===================================================================================================================