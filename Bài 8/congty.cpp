#include"congty.h"
int cListNhanVienSX::dem=0;
cListNhanVienSX::~cListNhanVienSX(){
    --dem;
    if(a!=nullptr){
        delete[] a;
        a=nullptr;
        n=0;
    }
}
cListNhanVienSX::cListNhanVienSX(){
    a=nullptr; n=0;
    ++dem;
}
cListNhanVienSX::cListNhanVienSX(int n){
    while(n<=0){
        cout<<"So luong nhan vien phai > 0!";
        cout<<"Moi ban nhap lai: " ;
        cin>>n;
    }
    this->n=n;
    a=new cNhanVienSX[this->n];
    ++dem;
}
cListNhanVienSX::cListNhanVienSX(int n, cNhanVienSX ts){
    while(n<=0){
        cout<<"So luong nhan vien phai > 0!";
        cout<<"Moi ban nhap lai: " ;
        cin>>n;
    }
    this->n=n;
    a=new cNhanVienSX[this->n];
    for(int i=0; i<this->n; i++) a[i]=ts;
    ++dem;
}
cListNhanVienSX::cListNhanVienSX(const cNhanVienSX* arr, int n){
    this->n=n;
    a=new cNhanVienSX[n];
    for(int i=0; i<n; i++) a[i]=arr[i];
    ++dem;
}
cListNhanVienSX::cListNhanVienSX(const cListNhanVienSX& nums){
    if(!nums.n){
        a=nullptr;
        this->n=0;
    }
    else{
        n=nums.n;
        a=new cNhanVienSX[n];
        for(int i=0; i<n; i++) a[i]=nums.a[i];
    }
    ++dem;
}
int cListNhanVienSX::GetN() const{
    return this->n;
}
cNhanVienSX* cListNhanVienSX::GetA() const{
    return this->a;
}
int cListNhanVienSX::GetDem(){
    return dem;
}
void cListNhanVienSX::SetN(int n){
    if(!n) this->~cListNhanVienSX();
    else{
        while(n<=0){
            cout<<"So luong nhan vien phai > 0!";
            cout<<"Moi ban nhap lai: " ;
            cin>>n;
        }
        cListNhanVienSX nums(n);
        for(int i=0; i<this->n; i++) nums.a[i]=a[i];
        this->~cListNhanVienSX();
        *this=nums;
    }
}
void cListNhanVienSX::SetA(const cListNhanVienSX& nums){
    *this=nums;
}
void cListNhanVienSX::Nhap(){
    if(a!=nullptr) this->~cListNhanVienSX();
    cout<<"Nhap so luong nhan vien: "; cin>>n;
    while(n<=0){
        cout<<"So luong nhan vien phai > 0!";
        cout<<"Moi ban nhap lai: " ;
        cin>>n;
    }
    a=new cNhanVienSX[n];
    for(int i=0; i<n; i++) a[i].Nhap();
}
void cListNhanVienSX::Xuat() const{
    if(a==nullptr) cout<<"Khong co nhan vien nao"<<endl;
    else{
        for(int i=0; i<n; i++) a[i].Xuat();
        cout<<endl;
    }
}
int partition(cNhanVienSX* &a, int l, int r){
    cNhanVienSX pivot=a[r];
    double pivot_luong=a[r].GetSoLuong()*a[r].GetDonGia();
    int i=l-1;
    for(int j=l; j<r; j++){
        double sum=a[j].GetSoLuong()*a[j].GetDonGia();
        if(sum<=pivot_luong){
            ++i; cNhanVienSX temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    ++i;
    swap(a[i], a[r]);
    return i;
}
void QuickSort(cNhanVienSX* &a, int l, int r){
    if(l>=r) return;
    int p=partition(a, l, r);
    QuickSort(a, l, p-1);
    QuickSort(a, p+1, r);
}
cNhanVienSX cListNhanVienSX::LuongThapNhat() const{
    cNhanVienSX luongthap=a[0];
    double nmin=a[0].GetSoLuong()*a[0].GetDonGia();
    for(int i=1; i<n; i++){
        if(a[i].GetSoLuong()*a[i].GetDonGia()<nmin){
            nmin=a[i].GetSoLuong()*a[i].GetDonGia();
            luongthap=a[i];
        }
    }
    return luongthap;
}
double cListNhanVienSX::TraTienNhanVien() const{
    double tratien=0;
    for(int i=0; i<n; i++) tratien+=a[i].GetSoLuong()*a[i].GetDonGia();
    return tratien;
}
cNhanVienSX cListNhanVienSX::NhanVienLonTuoi() const{
    cNhanVienSX lontuoi=a[0];
    for(int i=1; i<n; i++){
        if(a[i].GetNam()<lontuoi.GetNam()) lontuoi=a[i];
        else if(a[i].GetNam()==lontuoi.GetNam()&&a[i].GetThang()<lontuoi.GetThang())
        lontuoi=a[i];
        else if(a[i].GetNam()==lontuoi.GetNam()&&a[i].GetThang()==lontuoi.GetThang()
        &&a[i].GetNgay()<lontuoi.GetNgay())
        lontuoi=a[i];
    }
    return lontuoi;
}
void cListNhanVienSX::SapXepTangDan(){
    QuickSort(a, 0, n-1);
}