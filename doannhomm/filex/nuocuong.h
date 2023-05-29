#include<bits/stdc++.h>
using namespace std;
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