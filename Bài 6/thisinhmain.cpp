#include"lophoc.cpp"
int main() {
    cout<<"\n=====CHUONG TRINH QUAN LY THI SINH=====\n";
    cout<<"1. Khoi tao thi sinh bang cac constructor khac nhau:\n";
    cCandidate ts1; 
    cCandidate ts2("TS002", "Nguyen Van B", 15, 5, 2000, 8.5, 7.0, 9.0); 
    cCandidate ts3("TS003", "Tran Thi C"); 
    cCandidate ts4(9.5, 8.0, 7.5); 
    cout<<"Thi sinh 1 (Constructor mac dinh):\n"; ts1.Xuat();
    cout<<"\nThi sinh 2 (Constructor day du tham so):\n"; ts2.Xuat();
    cout<<"\nThi sinh 3 (Constructor voi ID va ten):\n"; ts3.Xuat();
    cout<<"\nThi sinh 4 (Constructor voi diem):\n"; ts4.Xuat();
    cout<<"\n2. Thay doi thong tin thi sinh bang cac setter:\n";
    ts1.SetID("TS001");
    ts1.SetName("Le Van A");
    ts1.SetNgayThangNam(10, 8, 2001);
    ts1.SetToanVanAnh(7.5, 8.0, 6.5);
    cout<<"Thi sinh 1 sau khi thay doi thong tin:\n"; ts1.Xuat();
    cout<<"\n3. Tao danh sach thi sinh:\n";
    int n=3;
    cCandidate* arrTS=new cCandidate[n];
    arrTS[0]=ts1;
    arrTS[1]=ts2;
    arrTS[2]=ts3;
    cListCandidate danhSach(arrTS, n);
    cout<<"Danh sach thi sinh co diem tong > 15:\n";
    danhSach.Xuat();
    cout<<"\n4. Tim thi sinh thu khoa:\n";
    cCandidate thuKhoa=danhSach.ThuKhoa();
    cout<<"Thong tin thi sinh thu khoa:\n"; thuKhoa.Xuat();
    cout<<"\n5. Sap xep danh sach thi sinh theo diem giam dan:\n";
    danhSach.SapXepGiamDan();
    cout<<"Danh sach sau khi sap xep (chi hien thi nhung thi sinh co tong diem > 15):\n"; danhSach.Xuat();
    cout<<"\n6. Tao danh sach thi sinh moi tu ban phim:\n";
    cListCandidate danhSachMoi;
    danhSachMoi.Nhap();
    cout<<"\nDanh sach thi sinh vua nhap (chi hien thi nhung thi sinh co tong diem > 15):\n";
    danhSachMoi.Xuat();
    cout<<"\nSap xep danh sach theo diem giam dan:\n";
    danhSachMoi.SapXepGiamDan();
    danhSachMoi.Xuat();
    cout<<"\nThi sinh thu khoa cua danh sach:\n";
    danhSachMoi.ThuKhoa().Xuat();
    cout<<"\n7. Thong ke:\n";
    cout<<"So luong doi tuong thi sinh da tao: "<<cCandidate::GetDem()<<endl;
    cout<<"So luong danh sach thi sinh da tao: "<<cListCandidate::GetDem()<<endl;
    delete[] arrTS;
    return 0;
}