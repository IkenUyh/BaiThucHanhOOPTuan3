#include"dathuc.cpp"
int main(){
    cout<<"=====CHUONG TRINH XU LY DA THUC====="<<endl<<endl;
    cout<<"So luong da thuc ban dau: "<<cDaThuc::GetDem()<<endl<<endl;
    cDaThuc dt1;
    cout<<"Da thuc 1 (mac dinh): "; dt1.Xuat();
    cDaThuc dt2(2);
    cout<<"Da thuc 2 (bac 2 voi he so mac dinh): "; dt2.Xuat();
    double hs[4] = {1, 2, 3, 4}; // 4x^3 + 3x^2 + 2x + 1
    cDaThuc dt3(3, hs);
    cout<<"Da thuc 3 (tu mang he so): "; dt3.Xuat();
    cDaThuc dt4(dt3);
    cout<<"Da thuc 4 (copy tu da thuc 3): "; dt4.Xuat();
    cout<<"\nSo luong da thuc hien tai: "<<cDaThuc::GetDem()<<endl<<endl;
    cout<<"Nhap da thuc moi:"<<endl;
    cDaThuc dt5;
    dt5.Nhap();
    cout<<"Da thuc vua nhap: "; dt5.Xuat();
    cout<<"Gan x bang: "; double x; cin>>x;
    cout<<"\nGia tri cua da thuc tai x = "<<x<<" la: "<<dt5.TinhGiaTri(x)<<endl<<endl;
    cout<<"Thay doi bac cua da thuc 2 thanh 3"<<endl;
    dt2.SetN(3);
    cout<<"Da thuc 2 sau khi thay doi: "; dt2.Xuat();
    cout<<"Gan gia tri cua da thuc 3 cho da thuc 2"<<endl;
    dt2.SetHeSo(dt3);
    cout<<"Da thuc 2 sau khi gan: "; dt2.Xuat();
    cout<<"Da thuc 3: "; dt3.Xuat();
    cout<<"\nPhep cong hai da thuc:"<<endl;
    cout<<"Nhap da thuc tiep theo: \n"; dt3.Nhap();
    cout<<"Da thuc 3: "; dt3.Xuat();
    cout<<"Da thuc 5: "; dt5.Xuat();
    cDaThuc tong=dt3.Tong(dt5);
    cout<<"Tong hai da thuc: "; tong.Xuat();
    cout<<"\nPhep tru hai da thuc:"<<endl;
    cout<<"Da thuc 3: "; dt3.Xuat();
    cout<<"Da thuc 5: "; dt5.Xuat();
    cDaThuc hieu = dt3.Hieu(dt5);
    cout<<"Hieu hai da thuc: "; hieu.Xuat();
    cout<<"\nSo luong da thuc hien tai: "<<cDaThuc::GetDem()<<endl;
    return 0;
}