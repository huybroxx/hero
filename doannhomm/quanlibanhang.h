#include<bits/stdc++.h>
#include <Windows.h>
using namespace std;
class PerSon {
	public:
		int  birtday ;
		string name , address, id, tel;
		virtual void input();
		virtual void output();
};
void PerSon::input()
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
void PerSon::output()
{
	cout<<" id "<<id<<endl;
	cout<<" name : "<<name<<endl;
	cout<<" address : "<<address<<endl;
	cout<<" tel : "<<tel<<endl;
	cout<<" birtday : "<<birtday<<endl;
}
//=============================================================================================================
class KhachHang:public PerSon{
	public:
	string loaiKhachHang;
	double  tichDiem, tienKhachHang;

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
	cout<<" nhap tich diem : ";cin>>tichDiem;
	fflush(stdin);
	cout<<" nhap loai khach hang : ";
	getline(cin, loaiKhachHang);
	cout<<" nhap tien khach hang : ";cin>>tienKhachHang;
}
void KhachHang::output()
{
	PerSon::output();
	cout<<" tich diem : "<<tichDiem<<endl;
	cout<<" loai khach hang : "<<loaiKhachHang<<endl;
	cout<<" tien khach hang : "<<tienKhachHang<<endl;
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
    
    int getsoluongkh(){
    	return dskh.size();
	}
	void danhSachKhachHang(){
		cout << "+================================================================+\n";
        for (int i = 0; i < dskh.size(); i++) {
        	cout<<"\nThong tin khach hang thu "<<i+1<<": \n";
           	dskh[i].output();
			cout << "\n+-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  +\n";
        }
        cout << "+================================================================+\n";
	}
};
//===================================================================================================================
//=============================================================================================
class CongThuc {
public:
    string nguyenlieu;
    double nuoc;
    double gam;
    CongThuc(string nl = "", double g = 0, double n = 0) {
        nguyenlieu = nl;
        nuoc = n;
        gam = g;
    }
    void incongthuc(){
		cout<<"     | Cong thuc: \t\t"<<this->nguyenlieu<<": "<<this->gam<<"(g) - Nuoc: "<<this->nuoc<<"(ml)\n";
	}
	void nhapcongthuc(){
		cout<<"\n|  - Nhap cong thuc - "; 
		cout<<"\n|   +Nhap nguyen lieu: "; 
		cin.ignore();
		getline(cin, this->nguyenlieu);
		cout<<"|   +Nhap (gam) nguyen lieu: ";
		cin>>this->gam;
		cout<<"|   +Nhap luong nuoc(ml): ";
		cin>>this->nuoc;
	}
};
class NuocUong
{
	public:
		string name;
        double gia;
        int soluong;
        CongThuc x;
        
        NuocUong(){
            
        }
        NuocUong(string ten, double gia, int soLuong = 0, CongThuc x = CongThuc()){
			this->name = ten;
 		 	this->gia = gia;
   			this->soluong = soLuong;
   			this->x = x;
		}
		void input(){
			cout<<"\n|  Nhap ten nuoc uong: ";
			cin.ignore();
			getline(cin, this->name);
			cout<<"|  Nhap so luong: ";
			cin>>this->soluong;
			x.nhapcongthuc();
			cout<<"|  Nhap gia: ";
			cin>>this->gia;
		}
		
		void themVaoKho(int s){
			this->soluong+=s;
		}
		void output(){
				   		
//			cout<<"================================================================\n";
//			cout<<"    | Ten nuoc uong           | Gia ban | So luong | Thanh tien |\n";
//			cout<<"================================================================\n";
			cout << left << setw(4)<<"    | "<<setw(24)<<this->name<<"| "<< setw(8)<<this->gia<<"| " << setw(9) <<this->soluong<< "| " << setw(10) <<this->gia*this->soluong<<" |\n";
			x.incongthuc();
		}
		double tinhtien(int soluongmua){
			return gia*soluongmua;
		}
		void xoakho(int n){
			this->soluong-=n;
		}
};
class ListNuocUong {
public:
    vector<NuocUong> dsNuocUong;
    
    void themNuocUong(NuocUong nuocUong) {
        dsNuocUong.push_back(nuocUong);
    }
	
    void xoaNuocUong(int index) {
        dsNuocUong.erase(dsNuocUong.begin() + index);
    }
    
	int getsoluongnuocuong(){
   	return dsNuocUong.size();
	}
    void themSLnuocuong(){
  		int stt, soLuong;
        cout << "Nhap so thu tu cua nuoc uong can them so luong: ";
        cin >> stt;
        while (stt < 1 || stt > dsNuocUong.size()) {
        	cout << "So thu tu khong hop le. Phai nhap trong khoang tu 1 den " << dsNuocUong.size() << ".\n";
            cout << "Nhap lai so thu tu: ";
            cin >> stt;
        }

        cout << "Nhap so luong can them: ";
        cin >> soLuong;
        while (soLuong < 0) {
        	cout << "So luong khong hop le. Phai nhap so khong am.\n";
            cout << "Nhap lai so luong: ";
            cin >> soLuong;
            }
        dsNuocUong[stt-1].themVaoKho(soLuong); 
        cout<<"So luong trong kho cua "<<dsNuocUong[stt-1].name<<" bay gio la: "<<dsNuocUong[stt-1].soluong<<endl;    
    }
    
    
    void hienThiDanhSachNuocUong() {

        cout << "+================================================================+\n";
		cout<<" STT | Ten nuoc uong           | Gia ban | So luong | Thanh tien |\n";
        cout << "+================================================================+\n";
        for (int i = 0; i < dsNuocUong.size(); i++) {
            cout << left << setw(2)<<" "<<i+1<<"  | "<<setw(24)<<dsNuocUong[i].name<<"| "<< setw(8)<<dsNuocUong[i].gia<<"| " << setw(9) <<dsNuocUong[i].soluong<< "| " << setw(10) <<dsNuocUong[i].gia*dsNuocUong[i].soluong<<" |\n";
			dsNuocUong[i].x.incongthuc();
			cout << "|-  -|  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  +\n";
        }
        cout << "+================================================================+\n";
    }
	void xoanuocuongtrongkho(){
		int stt;
                cout << "Nhap so thu tu cua nuoc uong can xoa: ";
                cin >> stt;
                while (stt < 1 || stt > dsNuocUong.size() ) {
                    cout << "So thu tu khong hop le. Phai nhap trong khoang tu 1 den " << dsNuocUong.size() << ".\n";
                    cout << "Nhap lai so thu tu: ";
                    cin >> stt;
                }
                dsNuocUong.erase(dsNuocUong.begin()+stt-1);
                cout << "Xoa nuoc uong thanh cong!\n";
	}
	
};
//class Hoadonnho{
//	public:
//		
//};
void khung(){
        cout<<"+-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  +\n";
    //    this_thread::sleep_for(chrono::seconds(1)); // Tạm dừng 1 giây 
        Beep(500, 1000);
}
void amthanh(){
		Beep(1000, 500);
	}
   

class HoaDon
{
	public:
		KhachHang kh;
		ListKhachHang dskhach;
		ListNuocUong listNuocUong;
		vector<NuocUong> dsNuocUong;
		vector<int> soLuong;
		int tienbill=0;
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
				cout<<"Nhap id khach hang de xac thuc: "; cin>>id;
				khung();
				for(int i=0; i<dskhach.getsoluongkh(); i++){
					if(id==dskhach.dskh[i].id) {
					kh=dskhach.dskh[i] ;
					cout<<"\nXac thuc thong tin khach hang thanh cong!\n";
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
            cout<<"Nhap 'T' neu muon tiep tuc mua; 'K' neu muon hoan tat hoa don!\n";
			do{
				cin>>chon2;
            	switch(chon2){
            		case ('t'): {
            			amthanh();
            			out=true;
						break;
					}
					case ('k'): {
						amthanh();
						out= false;
						break;
					}
					default: {
                	cout << "\nLua chon khong hop le. Vui long nhap lai.\n";
                	break;
            		}
				}
			} while(chon2!='t'&&chon2!='k');
            
		} while(out!=false);

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
        cout << " Tong tien: " << setw(47) << right << "|  "<<this->tienbill/2 <<"VND |"<< endl;
        cout << "=============================================================\n";
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
				sum+=listhoadon[i].tienbill;
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