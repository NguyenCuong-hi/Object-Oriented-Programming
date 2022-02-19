#include<iostream.h>
#include<string.h>
#include<iomanip.h>
#include<fstream.h>
struct Ngaysinh
{
	int dd;
	int mm;
	int yyyy;
};
typedef struct Ngaysinh NS;
class KHACHHANG
{
	protected:
	char ht[30];
	NS Ngsinh;
	int cmnd;
	char hk[15];
	public:
	
	
KHACHHANG(const char ht[30]="\0",NS Ngsinh,const int cmnd=0,const char hk[15]="\0")
	{
		strcpy(this->ht,ht);
		this->Ngsinh.dd=Ngsinh.dd;
		this->Ngsinh.mm=Ngsinh.mm;
		this->Ngsinh.yyyy=Ngsinh.yyyy;
		this->cmnd=cmnd;
		strcpy(this->hk,hk);
	}
	KHACHHANG()
	{
		
	}
	~KHACHHANG()
	{
		
	}
	
	 void nhap ()
	{
		cout<<"HO VA TEN:";
		cin.ignore();
		cin.getline(ht,30);
		cout<<"NGAY SINH(dd/mm/yyyy) :\n";
		cin>>this->Ngsinh.dd;
		while(Ngsinh.dd > 32  || Ngsinh.dd <=0)
		{
			{
				cout<<"Nhap lai ngay :\n";
				cin>>this->Ngsinh.dd;
			}
		}
		cout<<"Thang sinh:\n";
		cin>>this->Ngsinh.mm;
		while( Ngsinh.mm >= 13 || Ngsinh.mm <=0 )
		{
			cout<<"Nhap lai thang :\n";
			cin>>this->Ngsinh.mm;
		}
		cout<<"Nam sinh:\n";
		cin>>this->Ngsinh.yyyy;
		while(Ngsinh.yyyy < 0 )
		{
			cout<<"Nhap lai nam :\n";
			cin>>this->Ngsinh.yyyy;
		}
		cout<<"CCCD :";
		cin>>cmnd;
		cout<<"HO KHAU:";
		cin.ignore();
		cin.getline(hk,15);
	} 
	void xuat()
	{
		cout<<setw(30)<<left<<ht;
		cout<<left<<Ngsinh.dd<<"/"<<left<<Ngsinh.mm<<"/"<<left;
		cout<<setw(16)<<left<<Ngsinh.yyyy;
		cout<<setw(20)<<cmnd<<left;
		cout<<setw(20)<<left<<hk;
	}
	char *get_hk()
	{
		return hk;
	}
	char *get_ht()
	{
		return ht;
	}
	
	int get_ngsinh()
	{
		return this->Ngsinh.dd; 
	}
	int get_tsinh()
	{
		return this->Ngsinh.mm; 
	}
	int get_nmssinh()
	{
		return this->Ngsinh.yyyy; 
	}
	virtual void ghi_tep()
	{
		ofstream fileout;
		fileout.open("NguyenVanCuong_433.TXT",ios::app);
		fileout<<setw(30)<<left<<ht;
		fileout<<Ngsinh.dd<<left<<"/"<<Ngsinh.mm<<"/";
		fileout<<setw(16)<<left<<Ngsinh.yyyy;
		fileout<<setw(20)<<left<<cmnd;
		fileout<<setw(20)<<left<<hk;
		fileout.close();
	}
	virtual void doc_tep(ifstream &filein)
	{
		
		filein.open("DATA_INPUT.TXT",ios::in);
		
		filein.getline(ht,30);
		filein.seekg(2,ios::cur);
		filein>>Ngsinh.dd;
		filein.seekg(1,ios::cur);
		filein>>Ngsinh.mm;
		filein.seekg(1,ios::cur);
		filein>>Ngsinh.yyyy;
		filein.seekg(1,ios::cur);
		filein>>cmnd;
		filein.seekg(2,ios::cur);
		filein.getline(hk,15);
		filein.close();
	}
};
class KHTIENGUI : public KHACHHANG
{
	private:
	float tgui;
	int tg;
	public:
	KHTIENGUI(const float tgui, const int tg): KHACHHANG(ht,Ngsinh,cmnd,hk)
	{
		this->tgui=tgui;
		this->tg=tg;
	}
	KHTIENGUI()
	{
	}
	~KHTIENGUI()
	{
	}
	void nhap()
	{
		
		KHACHHANG :: nhap();
		cout<<"SO TIEN GUI:";
		cin>>tgui;
		cout<<"THOI GIAN (thang):";
		cin>>tg;
		cout<<"==================================="<<endl; 
	}
	void doc_tep(ifstream &filein)
	{
		
		filein.open("NguyenVanCuong_433.TXT",ios:: in);
		KHACHHANG :: doc_tep(filein);
		filein.seekg(2,ios::cur);
		filein>>tgui;
		filein.seekg(2,ios::cur);
		filein>>tg;
		filein.close();
		
	}
	friend istream &operator >> (istream &is, KHTIENGUI &kh)
	{
 		kh.nhap();
		return is;
	}
	
	float tinh_TL()
	{
		return  ((tg * tgui * 0.06) / 12)*1.0;
	}
	
	 bool operator > (KHTIENGUI &kh1)
		{
			return tg > kh1.tg;
		}
	void hienthi()
	{
		KHACHHANG :: xuat();
		cout<<setw(20)<<left<<tgui;
		cout<<setw(20)<<left<<tg;
		cout<<setw(20)<<left<<tinh_TL()<<endl;
	}
	friend ostream &operator << (ostream &os , KHTIENGUI kh)
	{
		kh.hienthi();
		return os;
	}
	int get_thanggui()
	{
		return tg;
	}
	void ghi_tep()
	{
		ofstream fileout;
		fileout.open("NguyenVanCuong_433.TXT",ios::app);
		KHACHHANG :: ghi_tep();
		fileout<<setw(20)<<left<<tgui;
		fileout<<setw(20)<<left<<tg;
		fileout<<setw(20)<<tinh_TL()<<endl;
		fileout.close();
	}
		
};
void title()
{
	cout<<left<<setw(5)<<"STT";
	cout<<setw(30)<<"HO VA TEN";
	cout<<setw(20)<<"NGAY SINH";
	cout<<setw(20)<<"CCCD";
	cout<<setw(20)<<"HO KHAU";
	cout<<setw(20)<<"SO TIEN";
	cout<<setw(20)<<"THOI HAN";
	cout<<setw(20)<<"TIEN LAI"<<endl;
}
// ===================MENU==========================//
void menu()
{
	cout<<right<<setw(82)<<"*** QUAN LY KHACH HANG ***"<<endl;
	cout<<setw(88)<<"		   ======================================================"<<endl;  
	cout<<setw(45)<<"|	"<<"1.HIEN THI TOAN BO DANH SACH"<<"			|"<<endl;
	cout<<setw(45)<<"|	"<<"2.DANH SACH KHACH HANG O NAM DINH"<<"		|"<<endl;
	cout<<setw(45)<<"|	"<<"3.DANH SACH TANG DAN THEO SO THANG GUI"<<"		|"<<endl;
	cout<<setw(45)<<"|	"<<"4.KIEM TRA VA CHEN BUI TIEN MINH"<<" 		|"<<endl;
	cout<<setw(45)<<"|	"<<"5.XOA KHACH HANG SINH TRUOC 01/01/1922"<<"		|"<<endl;
	cout<<setw(45)<<"|	"<<"0.THOAT				"<<"		|"<<endl;
	
	cout<<setw(88)<<"		   ======================================================"<<endl;
}
class Nganhang
{
	public:
	KHTIENGUI kh[100];
	int n;
	void nhap_ds_kh()
	{
		cout<<"SO LUONG KHACH HANG :";
		cin>>n;
		for(int i=0; i<n; i++)
		{
			cout<<"KHACH HANG THU "<<i+1<<endl;
			cin>>kh[i];
		}
	}
	void doc_ds()
	{
		ifstream filein;
		filein.open("NGUYENVANCUONG_433_INPUT.TXT",ios::in);
		filein >> n;
		for(int i=0; i<n; i++)
		{
			kh[i].doc_tep(filein);
		}
		filein.close();
	} 
	void ds_KH_ND()
	{
		int danhdau=0;
		for(int i=0; i<n; i++)
		{
			cout<<left<<setw(5)<<i+1;
			if(strcmpi(kh[i].get_hk(),"Nam Dinh")==0)
				{
					cout<<kh[i];
					danhdau = 1;
				}
		}
		if(danhdau = 0)
		{
			cout<<"\n\tKHONG CO KHACH HANG NAO\n"<<endl;
		}
	}
	void sap_xepds()
	{
		for(int i=0; i<n; i++)
		{
			for(int j=i+1; j<n; j++)
			{
				if(kh[i].get_thanggui() > kh[j].get_thanggui())
				{
				KHTIENGUI temp = kh[i];
					kh[i]= kh[j];
					kh[j] = temp; 
				}
			}
		 cout<<left<<setw(5)<<i+1;
		 cout<<kh[i];
		}
	}
void xuat_ds()
	{
		for(int i=0; i<n; i++)
		{
			cout<<left<<setw(5)<<i+1;
			cout<<kh[i];
		}
	}	
void ghi_tep_danhsach()
	{
		ofstream fileout;
		fileout.open("NguyenVanCuong_433.TXT",ios::out);
		fileout<<left<<setw(30)<<"HO VA TEN";
		fileout<<setw(20)<<"NGAY SINH";
		fileout<<setw(20)<<"CCCD";
		fileout<<setw(20)<<"HO KHAU";
		fileout<<setw(20)<<"SO TIEN";
		fileout<<setw(20)<<"THOI HAN";
		fileout<<setw(20)<<"TIEN LAI"<<endl;
		for(int i=0; i<n; i++)
		{
			
			kh[i].ghi_tep();
		}
		fileout.close();
	}
	// Ham kiem tra va chen KH
	
	void chen_kh()
	{
		int danhdau =0;
		for(int i=0; i<n; i++)
		{
			if(strcmpi(kh[i].get_ht(),"Bui Tien Minh")==0)
			 {
			 	danhdau = 1;
			 	cout<<"Da Co Khach Hang Bui Tien Minh ";
			 }
			 if(danhdau == 1 )
			 break;
		}
		if(danhdau == 0)
 			{
			 	int k;
				do
				{
					cout<<"Vi tri chen vao danh sach :";
					cin>>k;
				} while(k>n+1);
				KHTIENGUI khchen[1];
					cin>>khchen[1];
					if(strcmpi(khchen[1].get_ht(),"Bui Tien Minh")!=0)
					{
						cout<<"Sai ten! HINT : Bui Tien Minh! \n";	
					}
					else
					{	
					
    					n++;
						for(int i= n-1; i>=k; i--)
							{
								kh[i]= kh[i-1]; 
							}
						kh[k-1] = khchen[1];
						cout<<"\n\tTHEM THANH CONG !\n";
					}
		}
 }	
	// Ham xoa khach hang
	void tim_xoa_ngaysinh()
	{
		for(int i=0; i<n; i++)
		{
			if(kh[i].get_nmssinh() < 1922) 
			{
				for(int j = i; j<n-1; j++)
				{
 					kh[j] = kh[j+1];
 				}
				--n;
				--i;
			}
		} 
		cout<<"XOA THANH CONG !"<<endl;
	} 
	void luachon_menu()
	{
	
	int select;
	cout<<"NHAP LUA CHON :";
	cin>>select;
	while(select<0 || select>5)
	{
		cout<<"ERROR ! NHAP LAI :";
		cin>>select;
		
	}
	
	switch (select) 
	{
		case 1:
			{
				system("cls");
			cout<<"\n\tDANH SACH KHACH HANG\n";
			title();
			xuat_ds();
			ghi_tep_danhsach();
			cout<<"\n\tDa luu tep DS.TXT\n"; 
			system("PAUSE"); 
			system("cls"); 
			menu(); 
			luachon_menu();
			system("PAUSE");
			}break;
		case 2:
			{
			cout<<"\n\tDANH SACH KHACH HANG TAI NAM DINH \n";
			title();
			ds_KH_ND();
			system("PAUSE");
			system("cls"); 
			menu(); 
			luachon_menu();
			system("PAUSE");
			}break;
			
		case 3:
			{
			system("cls");
			cout<<"\n\tDANH SACH KHACH HANG TANG THEO THOI HAN\n";
			title();
			sap_xepds();
			system("PAUSE"); 
			system("cls"); 
			menu(); 
			luachon_menu();	
			}
			break;
		case 4:
			{
			cout<<"\n\tKHACH HANG BUI TIEN MINH \n";
			chen_kh();
			system("PAUSE");	
			system("cls"); 
			menu(); 
			luachon_menu();
			}
			break;
		case 5:
			{
			tim_xoa_ngaysinh();
			system("PAUSE"); 
			system("cls");	
			menu(); 
			luachon_menu();
			}break;
		default:
			{
			//system("cls");
			cout<<"\n\tTHOAT\n";
			}
			break;
	}
	} 
 
	
};
main()
{
	Nganhang nh;
	nh.nhap_ds_kh();
//	q.doc_ds();
	menu();
	nh.luachon_menu();
	
}