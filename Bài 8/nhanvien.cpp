#include"nhanvien.h"
int cNhanVienSX::dem=0;
bool NamNhuan(int nam){
    return (nam%4==0&&nam%100!=0)||(nam%400==0);
}
int SoNgayTrongThang(int thang, int nam){
    int nThang[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(thang==2&&NamNhuan(nam)) return 29;
    return nThang[thang];
}
bool cNhanVienSX::KiemTraHopLe() const{
    return thang>=1&&thang<=12&&nam>=1&&ngay>=1&&ngay<=SoNgayTrongThang(thang, nam);
}
bool isName(char x){
    return (x>='a'&&x<='z')||(x>='A'&&x<='Z')||(x==' ');
}
bool KiemTraHoTen(const string& name){
    if(name.empty()) return false;
    for(const auto& x:name){
        if(!isName(x)) return false;
    }
    return true;
}
cNhanVienSX::~cNhanVienSX(){
    --dem;
}
cNhanVienSX::cNhanVienSX():id(""), name(""), ngay(12), thang(4), nam(2025), soluong(0){
    //id=name="";
    //ngay=thang=nam=0;
    //soluong=0;
    dongia=0;
    ++dem;
}
cNhanVienSX::cNhanVienSX(string id):id(id){
    name="";
    ngay=thang=nam=0;
    soluong=dongia=0;
    ++dem;
}
cNhanVienSX::cNhanVienSX(string id, string name):id(id), name(name){
    this->id=id;
    soluong=dongia=0;
    if(!KiemTraHoTen(name)) this->name="";
    ++dem;
}
cNhanVienSX::cNhanVienSX(string id, string name, int ngay, int thang, int nam, double dongia){
    this->id=id; this->name=name;
    if(!KiemTraHoTen(name)) this->name="";
    soluong=0;
    this->dongia=dongia;
    this->ngay=ngay; this->thang=thang; this->nam=nam;
    if(!KiemTraHopLe()){
        this->ngay=12; this->thang=4; this->nam=2025;
    }
    ++dem;
}
cNhanVienSX::cNhanVienSX(int ngay, int thang, int nam):ngay(ngay), thang(thang), nam(nam){
    id=name="";
    soluong=dongia=0;
    if(!KiemTraHopLe()){
        this->ngay=12; this->thang=4; this->nam=2025;
    }
    ++dem;
}
cNhanVienSX::cNhanVienSX(double dongia):dongia(dongia){
    id=name="";
    ngay=12; thang=4; nam=2025;
    soluong=0;
    ++dem;
}
cNhanVienSX::cNhanVienSX(const cNhanVienSX& nv){
    this->id=nv.id; this->name=nv.name;
    this->ngay=nv.ngay; this->thang=nv.thang; this->nam=nv.nam;
    this->soluong=nv.soluong;
    this->dongia=nv.dongia;
    ++dem;
}
string cNhanVienSX::GetID() const{
    return this->id;
}
string cNhanVienSX::GetName() const{
    return this->name;
}
int cNhanVienSX::GetNgay() const{
    return this->ngay;
}
int cNhanVienSX::GetThang() const{
    return this->thang;
}
int cNhanVienSX::GetNam() const{
    return this->nam;
}
int cNhanVienSX::GetSoLuong() const{
    return this->soluong;
}
double cNhanVienSX::GetDonGia() const{
    return this->dongia;
}
int cNhanVienSX::GetDem(){
    return dem;
}
void cNhanVienSX::SetID(string id){
    this->id=id;
}
void cNhanVienSX::SetName(string name){
    while(!KiemTraHoTen(name)){
        cout<<"Ho ten vua nhap khong hop le!";
        cout<<"Moi ban nhap lai: "; 
        getline(cin, name);
    }
    this->name=name;
}
void cNhanVienSX::SetNgay(int ngay){
    int ngay_tam=this->ngay;
    this->ngay=ngay;
    if(!KiemTraHopLe()) this->ngay=ngay_tam;
}
void cNhanVienSX::SetThang(int thang){
    int thang_tam=this->thang;
    this->thang=thang;
    if(!KiemTraHopLe()) this->thang=thang_tam;
}
void cNhanVienSX::SetNam(int nam){
    int nam_tam=this->nam;
    this->nam=nam;
    if(!KiemTraHopLe()) this->nam=nam_tam;
}
void cNhanVienSX::SetNgayThangNam(int ngay, int thang, int nam){
    SetNgay(ngay); SetThang(thang); SetNam(nam);
}
void cNhanVienSX::SetSoLuong(int soluong){
    this->soluong=soluong;
}
void cNhanVienSX::SetDonGia(double dongia){
    this->dongia=dongia;
}
void cNhanVienSX::Nhap(){
    cin.ignore();
    cout<<"Nhap ma nhan vien: "; getline(cin, id);
    cout<<"Nhap ho ten nhan vien: "; getline(cin, name);
    while(!KiemTraHoTen(name)){
        cout<<"Ho ten vua nhap khong hop le!";
        cout<<"Moi ban nhap lai: "; 
        getline(cin, this->name);
    }
    cout<<"Nhap ngay: "; cin>>ngay;
    cout<<"Nhap thang: "; cin>>thang;
    cout<<"Nhap nam: "; cin>>nam;
    while(!KiemTraHopLe()){
        cout<<"Ngay sinh ban nhap khong hop le!";
        cout<<"Moi ban nhap lai: "; 
        cout<<"Nhap ngay: "; cin>>ngay;
        cout<<"Nhap thang: "; cin>>thang;
        cout<<"Nhap nam: "; cin>>nam;
    }
    cout<<"Nhap so san pham da gia cong: "; cin>>soluong;
    cout<<"Nhap don gia san pham: "; cin>>dongia;
}
void cNhanVienSX::Xuat() const{
    cout<<"Ma nhan vien: "<<id<<endl;;
    cout<<"Ho va ten nhan vien: "<<name<<endl;
    cout<<"Ngay thang nam sinh: ";
    if(ngay<10) cout<<"0"<<ngay;
    else cout<<ngay;
    cout<<"/";
    if(thang<10) cout<<"0"<<thang;
    else cout<<thang;
    cout<<"/"<<nam<<endl;
    cout<<"So san pham da gia cong: "; cout<<soluong<<endl;
    cout<<"Don gia san pham: "; cout<<dongia<<endl;
    cout<<"Luong nhan vien: "<<fixed<<setprecision(2)<<soluong*dongia<<endl;
}