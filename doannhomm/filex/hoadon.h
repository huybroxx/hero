#include<bits/stdc++.h>
#include"khachhang.h"
#include"person.h"
#include"nuocuong.h"
#include"amthanhh.h"
using namespace std;
class HoaDon
{
	public:
		KhachHang kh;
		ListKhachHang dskhach;
		ListNuocUong listNuocUong;
		vector<NuocUong> dsNuocUong;
		vector<int> soLuong;
		int tienbill=0;
		int tiengiamgia=0;
		HoaDon(ListKhachHang c, KhachHang a, ListNuocUong b){
			this->kh=a;
			this->listNuocUong=b;
			this->dskhach=c;
		}
		void Tienbilll(NuocUong nuoc, int soluong){
    	this->tienbill+=(nuoc.gia*soluong);
		}
		bool themNuocUong(NuocUong nuocUong, int soLuongMua) {
        if (nuocUong.soluong >= soLuongMua) {
            dsNuocUong.push_back(nuocUong);
            soLuong.push_back(soLuongMua);
            Tienbilll(nuocUong, soLuongMua);
            nuocUong.xoakho(soLuongMua);
            return true;
        	}
        else 
			return false;
    	}
    	
		void taohoadon(){
		bool out;	
		char chon; 
		string id;
		cout<<"-Thong tin khach hang-";	
		cout<<"\nChon 'C' neu khach hang co san; 'K' neu khach hang moi: "; cin>>chon;
		switch (chon){
			case ('c'): {
				bool x;
				dskhach.danhSachKhachHang();
				do{
				cout<<"\nNhap id khach hang de xac thuc: "; cin>>id;
				khung();
				for(int i=0; i<dskhach.getsoluongkh(); i++){
					if(id==dskhach.dskh[i].id) {
					kh=dskhach.dskh[i] ;
					cout<<"\nXac thuc thong tin khach hang thanh cong!\n\n";
					//khung();
					x=true;
					break;
					}
					else {
					x=false;
					}
					}
					if (x==false) cout<<"\nXac thuc thong tin khach that bai!\n ";
				} while(x!=true);
				
				break;
			}
			case ('k'): {
				kh.input();
				dskhach.themKhachhang(kh);
				break;
			}
		}
		system("pause");
		system("cls");
		listNuocUong.hienThiDanhSachNuocUong();
		do{
			//listNuocUong.hienThiDanhSachNuocUong();
			int stt, soLuongMua;
            cout << "Nhap so thu tu cua nuoc uong can mua: ";
            cin>>stt;
            while (stt < 1 || stt > listNuocUong.getsoluongnuocuong()) {
            	cout << "So thu tu khong hop le. Ma so phai nam trong khoang tu 1 den " << listNuocUong.getsoluongnuocuong() << ".\n";
           	 	cout << "Nhap lai so thu tu cua nuoc uong can mua: ";
            	cin >> stt;
            }
			
            cout << "So luong nuoc uong can mua: ";
            cin >> soLuongMua;
            while (soLuongMua <= 0) {
                cout << "So luong nuoc uong khong hop le. Vui long nhap lai.\n";
                cout << "So luong nuoc uong can mua: ";
                cin >> soLuongMua;
            }
            if (themNuocUong(listNuocUong.dsNuocUong[stt-1], soLuongMua)) {
                cout << "Them nuoc uong vao hoa don thanh cong!\n";
                tienbill+=soLuongMua*listNuocUong.dsNuocUong[stt-1].gia;
            } else {
                cout << "Khong the them nuoc uong nay vao hoa don.\n";
            }
            char chon2;
            cout<<"Nhap 'T' neu muon tiep tuc mua; 'K' neu muon hoan tat!\n   -->  ";
			do{
				cin>>chon2;
				amthanh();
				switch(chon2)
				{
            		case ('t'): {
            			out=true;   
						break;
					}
					case ('k'): {
						out= false;
						break;
					}
					default: {
                	cout << "\nLua chon khong hop le. Vui long nhap lai.\n";
                	break;
            		}
				}
			} while(chon2!='t'&&chon2!='k');
		} while (out==true);
		system("pause");
		system("cls");
		//============
		char chon3;
		int diem;
		cout<<"\n    Ban co muon ap dung 'Diem tich luy' cho hoa don khong? \n     (luu y ban dang co "<<kh.tichDiem<<" diem | 10 diem = 1000 VND)";
		cout<<"\n    Nhap 'C' neu co | Nhap 'K' neu khong\n    -->  ";
		do{
				cin>>chon3;
				amthanh();
				switch(chon3)
				{
            		case ('c'): {
            		bool p;
            		do{
            			cout<<"Moi ban nhap so diem muon su dung: ";
						cin>>diem;
						if (diem>=10&&diem<=kh.tichDiem) {
							kh.tichDiem-=diem;
							tiengiamgia=diem/10*1000;
							p=true;
							cout<<"\n\nHoan tat hoa don! ";
						}
						else{
							cout<<"So diem ban nhap khong hop le!";
							p=false;
						}
					}while(p!=true);
						break;
					}
					case ('k'): {
						cout<<"\n\nHoan tat hoa don! ";
						break;
					}
					default: {
                	cout << "\nLua chon khong hop le. Vui long nhap lai.\n";
                	break;
            		}
				}
			} while(chon3!='c'&&chon3!='k');
		//===============
	}
	void inHoaDon(){
		kh.output();
		cout << "+================================================================+\n";
		cout<<" STT | Ten nuoc uong           | Gia ban | So luong | Thanh tien |\n";
        cout << "+================================================================+\n";
        for (int i = 0; i < dsNuocUong.size(); i++) {
            cout << left << setw(2)<<" "<<i+1<<"  | "<<setw(24)<<dsNuocUong[i].name<<"| "<< setw(8)<<dsNuocUong[i].gia<<"| " << setw(9) <<soLuong[i]<< "| " << setw(10) <<dsNuocUong[i].gia*soLuong[i]<<" |\n";
			cout << "|-  -|  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  +\n";
        }
        cout << "+================================================================+\n";
        cout << " Tong tien: " << setw(43) << right << "|  "<<this->tienbill/2 <<" VND |"<< endl;
        cout << " Diem tich luy cong them : " << setw(28) << right << "|   "<<this->tienbill/20 <<"     |"<< endl;
        kh.tichDiem+=this->tienbill/20;
        //cout << "------------------------------------------------------------------\n";
        cout << " Giam gia : " << setw(43) << right << "|   "<<tiengiamgia <<" VND |"<< endl;
        cout << "------------------------------------------------------------------\n";
        cout << " Thanh toan :" << setw(42) << right << "|  "<<this->tienbill/2-tiengiamgia <<" VND |"<< endl;
        cout << "+================================================================+\n";
	}
		
};
class ListHoaDon{
	public:
		vector<HoaDon> listhoadon;
		void themHoaDon(HoaDon hoadon){
			listhoadon.push_back(hoadon);
		}
		void xoaHoaDon(int index){
			listhoadon.erase(listhoadon.begin() + index);			
		}
		void xoaAllHoaDon(){
			listhoadon.clear();
		}
		int Tongtienhoadon(){
			int sum=0;
			for(int i=0; i<listhoadon.size(); i++){
				sum+=((listhoadon[i].tienbill)-(listhoadon[i].tiengiamgia));
			}
			return sum/2;
		}
		void inHoaDonMoi(){
			listhoadon[listhoadon.size()-1].inHoaDon();
		}
		void inDanhSachHoaDon(){
			for(int i=0; i<listhoadon.size(); i++){
				cout<<"\n\t-HOA DON ["<<i+1<<"]\n";
				listhoadon[i].inHoaDon();
			}
		}
};