#include"nhanvienvp.h"
int cNhanVienVP::dem=0;
bool NamNhuan(int nam){
    return (nam%4==0&&nam%100!=0)||(nam%400==0);
}
int SoNgayTrongThang(int thang, int nam){
    int nThang[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(thang==2&&NamNhuan(nam)) return 29;
    return nThang[thang];
}
bool cNhanVienVP::KiemTraHopLe() const{
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
cNhanVienVP::~cNhanVienVP(){
    --dem;
}
cNhanVienVP::cNhanVienVP():id(""), name(""), ngay(12), thang(4), nam(2025), luong(0){
    //id=name="";
    //ngay=thang=nam=0;
    //luong=0;
    ++dem;
}
cNhanVienVP::cNhanVienVP(string id):id(id){
    name="";
    ngay=thang=nam=0;
    luong=0;
    ++dem;
}
cNhanVienVP::cNhanVienVP(string id, string name):id(id), name(name){
    this->id=id;
    luong=0;
    if(!KiemTraHoTen(name)) this->name="";
    ++dem;
}
cNhanVienVP::cNhanVienVP(string id, string name, int ngay, int thang, int nam, double luong){
    this->id=id; this->name=name;
    if(!KiemTraHoTen(name)) this->name="";
    this->luong=luong;
    this->ngay=ngay; this->thang=thang; this->nam=nam;
    if(!KiemTraHopLe()){
        this->ngay=12; this->thang=4; this->nam=2025;
    }
    ++dem;
}
cNhanVienVP::cNhanVienVP(int ngay, int thang, int nam):ngay(ngay), thang(thang), nam(nam){
    id=name="";
    luong=0;
    if(!KiemTraHopLe()){
        this->ngay=12; this->thang=4; this->nam=2025;
    }
    ++dem;
}
cNhanVienVP::cNhanVienVP(double luong):luong(luong){
    id=name="";
    ngay=12; thang=4; nam=2025;
    //this->luong=luong;
    ++dem;
}
cNhanVienVP::cNhanVienVP(const cNhanVienVP& nv){
    this->id=nv.id; this->name=nv.name;
    this->ngay=nv.ngay; this->thang=nv.thang; this->nam=nv.nam;
    this->luong=nv.luong;
    ++dem;
}
string cNhanVienVP::GetID() const{
    return this->id;
}
string cNhanVienVP::GetName() const{
    return this->name;
}
int cNhanVienVP::GetNgay() const{
    return this->ngay;
}
int cNhanVienVP::GetThang() const{
    return this->thang;
}
int cNhanVienVP::GetNam() const{
    return this->nam;
}
double cNhanVienVP::GetLuong() const{
    return this->luong;
}
int cNhanVienVP::GetDem(){
    return dem;
}
void cNhanVienVP::SetID(string id){
    this->id=id;
}
void cNhanVienVP::SetName(string name){
    while(!KiemTraHoTen(name)){
        cout<<"Ho ten vua nhap khong hop le!";
        cout<<"Moi ban nhap lai: "; 
        getline(cin, name);
    }
    this->name=name;
}
void cNhanVienVP::SetNgay(int ngay){
    int ngay_tam=this->ngay;
    this->ngay=ngay;
    if(!KiemTraHopLe()) this->ngay=ngay_tam;
}
void cNhanVienVP::SetThang(int thang){
    int thang_tam=this->thang;
    this->thang=thang;
    if(!KiemTraHopLe()) this->thang=thang_tam;
}
void cNhanVienVP::SetNam(int nam){
    int nam_tam=this->nam;
    this->nam=nam;
    if(!KiemTraHopLe()) this->nam=nam_tam;
}
void cNhanVienVP::SetNgayThangNam(int ngay, int thang, int nam){
    SetNgay(ngay);
    SetThang(thang);
    SetNam(nam);
}
void cNhanVienVP::SetLuong(double luong){
    this->luong=luong;
}
void cNhanVienVP::Nhap(){
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
    cout<<"Nhap luong nhan vien: "; cin>>luong;
}
void cNhanVienVP::Xuat() const{
    cout<<"Ma nhan vien: "<<id<<endl;;
    cout<<"Ho va ten nhan vien: "<<name<<endl;
    cout<<"Ngay thang nam sinh: ";
    if(ngay<10) cout<<"0"<<ngay;
    else cout<<ngay;
    cout<<"/";
    if(thang<10) cout<<"0"<<thang;
    else cout<<thang;
    cout<<"/"<<nam<<endl;
    cout<<"Luong nhan vien: "<<fixed<<setprecision(2)<<luong<<endl;
}