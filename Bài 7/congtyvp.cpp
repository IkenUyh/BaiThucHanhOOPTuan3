#include"congtyvp.h"
int cListNhanVienVP::dem=0;
cListNhanVienVP::~cListNhanVienVP(){
    --dem;
    if(a!=nullptr){
        delete[] a;
        a=nullptr;
        n=0;
    }
}
cListNhanVienVP::cListNhanVienVP(){
    a=nullptr; n=0;
    ++dem;
}
cListNhanVienVP::cListNhanVienVP(int n){
    while(n<=0){
        cout<<"So luong nhan vien phai > 0!";
        cout<<"Moi ban nhap lai: " ;
        cin>>n;
    }
    this->n=n;
    a=new cNhanVienVP[this->n];
    ++dem;
}
cListNhanVienVP::cListNhanVienVP(int n, cNhanVienVP ts){
    while(n<=0){
        cout<<"So luong nhan vien phai > 0!";
        cout<<"Moi ban nhap lai: " ;
        cin>>n;
    }
    this->n=n;
    a=new cNhanVienVP[this->n];
    for(int i=0; i<this->n; i++) a[i]=ts;
    ++dem;
}
cListNhanVienVP::cListNhanVienVP(const cNhanVienVP* arr, int n){
    this->n=n;
    a=new cNhanVienVP[n];
    for(int i=0; i<n; i++) a[i]=arr[i];
    ++dem;
}
cListNhanVienVP::cListNhanVienVP(const cListNhanVienVP& nums){
    if(!nums.n){
        a=nullptr;
        this->n=0;
    }
    else{
        n=nums.n;
        a=new cNhanVienVP[n];
        for(int i=0; i<n; i++) a[i]=nums.a[i];
    }
    ++dem;
}
int cListNhanVienVP::GetN() const{
    return this->n;
}
cNhanVienVP* cListNhanVienVP::GetA() const{
    return this->a;
}
int cListNhanVienVP::GetDem(){
    return dem;
}
void cListNhanVienVP::SetN(int n){
    if(!n) this->~cListNhanVienVP();
    else{
        while(n<=0){
            cout<<"So luong nhan vien phai > 0!";
            cout<<"Moi ban nhap lai: " ;
            cin>>n;
        }
        cListNhanVienVP nums(n);
        for(int i=0; i<this->n; i++) nums.a[i]=a[i];
        this->~cListNhanVienVP();
        *this=nums;
    }
}
void cListNhanVienVP::SetA(const cListNhanVienVP& nums){
    *this=nums;
}
void cListNhanVienVP::Nhap(){
    if(a!=nullptr) this->~cListNhanVienVP();
    cout<<"Nhap so luong nhan vien: "; cin>>n;
    while(n<=0){
        cout<<"So luong nhan vien phai > 0!";
        cout<<"Moi ban nhap lai: " ;
        cin>>n;
    }
    a=new cNhanVienVP[n];
    for(int i=0; i<n; i++) a[i].Nhap();
}
void cListNhanVienVP::Xuat() const{
    if(a==nullptr) cout<<"Khong co nhan vien nao"<<endl;
    else{
        for(int i=0; i<n; i++) a[i].Xuat();
        cout<<endl;
    }
}
int partition(cNhanVienVP* &a, int l, int r){
    cNhanVienVP pivot=a[r];
    double pivot_luong=a[r].GetLuong();
    int i=l-1;
    for(int j=l; j<r; j++){
        double sum=a[j].GetLuong();
        if(sum<=pivot_luong){
            ++i; cNhanVienVP temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    ++i;
    swap(a[i], a[r]);
    return i;
}
void QuickSort(cNhanVienVP* &a, int l, int r){
    if(l>=r) return;
    int p=partition(a, l, r);
    QuickSort(a, l, p-1);
    QuickSort(a, p+1, r);
}
cNhanVienVP cListNhanVienVP::LuongCaoNhat() const{
    cNhanVienVP luongcao=a[0];
    double nmax=a[0].GetLuong();
    for(int i=1; i<n; i++){
        if(a[i].GetLuong()>nmax){
            nmax=a[i].GetLuong();
            luongcao=a[i];
        }
    }
    return luongcao;
}
double cListNhanVienVP::TraTienNhanVien() const{
    double tratien=0;
    for(int i=0; i<n; i++) tratien+=a[i].GetLuong();
    return tratien;
}
cNhanVienVP cListNhanVienVP::NhanVienLonTuoi() const{
    cNhanVienVP lontuoi=a[0];
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
void cListNhanVienVP::SapXepTangDan(){
    QuickSort(a, 0, n-1);
}