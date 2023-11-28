#include <iostream>
using namespace std;
class person{
	private:
		string hodem, ten, tuoi;
	public:
		void nhap(){
			cout<<"nhap ho dem: ";
			getline(cin,hodem);
			cin.ignore();
			cout<<"nhap ten: ";
			getline(cin,ten);
			cout<<"nhap tuoi: ";
			cin>>tuoi;
			}
		void xuat(){
			cout<<"Ho va ten"<<hodem<<" "<<ten<<endl;
			cout<<"tuoi: "<<tuoi;
			}
		bool operator > (person& ng){
			if (ten > ng.ten)
				return true;
			else if (ten == ng.ten)
				if (hodem > ng.hodem)
					return true;
			return false;
		}				
};
class student : public person{
	private:
		string masv, nganh;
		float diemtb;
	public:
		float getdiemtb(){
			return diemtb;}
		void nhap_sv(){
			cout<<"nhap vao ma sinh vien: ";
			cin.ignore();
			getline(cin,masv);
			cout<<"nhap vao nganh dao tao: ";
			getline(cin,nganh);
			cout<<"nhap diem trung binh: ";
			cin>> diemtb;
			}
		void xuat_sv(){
			cout<<"ma sinh vien: "<<masv<<endl;
			cout<<"nganh dao: "<<nganh<<endl;
			cout<<"diem trung binh: "<<diemtb<<endl;
			}
			void xeploai(){
			if (diemtb >= 5.0)
				cout << "Dat";
			else 
				cout << "Khong dat";
		}			
};
class quanly:public student{
	private:
		student sv[50];
		int n;
	public:
		quanly(){
			n=0;
			}
		void nhap_sv(){
			int n;
				do{
		cout<<"Nhap so luong sinh vien: ";
   		cin>>n;
   		if (n <= 0 or n >= 50)
   			cout << "So luong khong hop le!";
   }while(n > 50);
   
	cin.ignore();
	//nhap du lieu cho giang vien
   	for (int i = 0;i<n;i++){
   		cout << "Nhap thong tin cua sinh vien thu " << i+1 << endl;
   		sv[i].nhap_sv();
	}
		};
		void xuat_sv(){
			student::xuat();
			cout<<masv<<nganh<<diemtb<<endl;
		};
		void xapxep(){
		for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (sv[i] > sv[i]){
				student tam = sv[i];
				sv[i] = sv[j];
				sv[j] = tam;
			}
	for (int i = 0; i < n; i++)
		sv[i].xuat_sv();
		};
//		void sinhviendtbcaonhat(){
//		double maxtb = a[0].getdiemtb();
//		for(int i=1; i<n;i++)
//		{
//			if(a[i].getdiem>maxtb)
//				{
//					maxtb=a[i].getdiemtb();
//				}
//		}
//		for (int i=0;i<n;i++)
//		{
//			if(a[i].getdiemtb==maxtb)
//		}		
//			a[i].xuat();
//		};
		void inrasinhviendat();
		
};
int main() {
	quanly ob;
	ob.nhap_sv();
	ob.xuat_sv();
	ob.xapxep();
	return 0;
}
