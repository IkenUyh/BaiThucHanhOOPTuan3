#include"thisinh.h"
int cCandidate::dem=0;
bool NamNhuan(int nam){
    return (nam%4==0&&nam%100!=0)||(nam%400==0);
}
int SoNgayTrongThang(int thang, int nam){
    int nThang[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(thang==2&&NamNhuan(nam)) return 29;
    return nThang[thang];
}
bool cCandidate::KiemTraHopLe() const{
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
cCandidate::~cCandidate(){
    --dem;
}
cCandidate::cCandidate():id(""), name(""), ngay(12), thang(4), nam(2025), toan(0), van(0), anh(0){
    //id=name="";
    //ngay=thang=nam=0;
    //toan=van=anh=0;
    ++dem;
}
cCandidate::cCandidate(string id):id(id){
    name="";
    ngay=thang=nam=0;
    toan=van=anh=0;
    ++dem;
}
cCandidate::cCandidate(string id, string name):id(id), name(name){
    this->id=id;
    toan=van=anh=0;
    if(!KiemTraHoTen(name)) this->name="";
    ++dem;
}
cCandidate::cCandidate(string id, string name, int ngay, int thang, int nam, double toan, double van, double anh){
    this->id=id; this->name=name;
    if(!KiemTraHoTen(name)) this->name="";
    this->toan=toan; this->van=van; this->anh=anh;
    if(toan>10||toan<0) this->toan=0;
    if(van>10||van<0) this->van=0;
    if(anh>10||anh<0) this->anh=0;
    this->ngay=ngay; this->thang=thang; this->nam=nam;
    if(!KiemTraHopLe()){
        this->ngay=12; this->thang=4; this->nam=2025;
    }
    ++dem;
}
cCandidate::cCandidate(int ngay, int thang, int nam):ngay(ngay), thang(thang), nam(nam){
    id=name="";
    toan=van=anh=0;
    if(!KiemTraHopLe()){
        this->ngay=12; this->thang=4; this->nam=2025;
    }
    ++dem;
}
cCandidate::cCandidate(double toan, double van, double anh):toan(toan), van(van), anh(anh){
    id=name="";
    ngay=12; thang=4; nam=2025;
    if(toan>10||toan<0) this->toan=0;
    if(van>10||van<0) this->van=0;
    if(anh>10||anh<0) this->anh=0;
    ++dem;
}
cCandidate::cCandidate(const cCandidate& ps){
    this->id=ps.id; this->name=ps.name;
    this->ngay=ps.ngay; this->thang=ps.thang; this->nam=ps.nam;
    this->toan=ps.toan; this->van=ps.van; this->anh=ps.anh;
    ++dem;
}
string cCandidate::GetID() const{
    return this->id;
}
string cCandidate::GetName() const{
    return this->name;
}
int cCandidate::GetNgay() const{
    return this->ngay;
}
int cCandidate::GetThang() const{
    return this->thang;
}
int cCandidate::GetNam() const{
    return this->nam;
}
double cCandidate::GetToan() const{
    return this->toan;
}
double cCandidate::GetVan() const{
    return this->van;
}
double cCandidate::GetAnh() const{
    return this->anh;
}
int cCandidate::GetDem(){
    return dem;
}
void cCandidate::SetID(string id){
    this->id=id;
}
void cCandidate::SetName(string name){
    while(!KiemTraHoTen(name)){
        cout<<"Ho ten vua nhap khong hop le!";
        cout<<"Moi ban nhap lai: "; 
        getline(cin, this->name);
    }
    this->name=name;
}
void cCandidate::SetNgay(int ngay){
    int ngay_tam=this->ngay;
    this->ngay=ngay;
    if(!KiemTraHopLe()) this->ngay=ngay_tam;
}
void cCandidate::SetThang(int thang){
    int thang_tam=this->thang;
    this->thang=thang;
    if(!KiemTraHopLe()) this->thang=thang_tam;
}
void cCandidate::SetNam(int nam){
    int nam_tam=this->nam;
    this->nam=nam;
    if(!KiemTraHopLe()) this->nam=nam_tam;
}
void cCandidate::SetNgayThangNam(int ngay, int thang, int nam){
    SetNgay(ngay);
    SetThang(thang);
    SetNam(nam);
}
void cCandidate::SetToan(double toan){
    double toan_tam=this->toan;
    this->toan=toan;
    if(toan>10||toan<0) this->toan=toan_tam;
}
void cCandidate::SetVan(double van){
    double van_tam=this->van;
    this->van=van;
    if(van>10||van<0) this->van=van_tam;
}
void cCandidate::SetAnh(double anh){
    double anh_tam=this->anh;
    this->anh=anh;
    if(anh>10||anh<0) this->anh=anh_tam;
}
void cCandidate::SetToanVanAnh(double toan, double van, double anh){
    SetToan(toan);
    SetVan(van);
    SetAnh(anh);
}
void cCandidate::Nhap(){
    cin.ignore();
    cout<<"Nhap ma thi sinh: "; getline(cin, id);
    cout<<"Nhap ho ten thi sinh: "; getline(cin, name);
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
    cout<<"Nhap diem toan: "; cin>>toan;
    while(toan>10||toan<0){
        cout<<"Diem toan khong hop le!";
        cout<<"Moi ban nhap lai: "; cin>>toan;
    }
    cout<<"Nhap diem van: "; cin>>van;
    while(van>10||van<0){
        cout<<"Diem van khong hop le!";
        cout<<"Moi ban nhap lai: "; cin>>van;
    }
    cout<<"Nhap diem anh: "; cin>>anh;
    while(anh>10||anh<0){
        cout<<"Diem anh khong hop le!";
        cout<<"Moi ban nhap lai: "; cin>>anh;
    }
}
void cCandidate::Xuat() const{
    cout<<"Ma thi sinh: "<<id<<endl;;
    cout<<"Ho va ten thi sinh: "<<name<<endl;
    cout<<"Ngay thang nam sinh: ";
    if(ngay<10) cout<<"0"<<ngay;
    else cout<<ngay;
    cout<<"/";
    if(thang<10) cout<<"0"<<thang;
    else cout<<thang;
    cout<<"/"<<nam<<endl;
    cout<<"Diem toan: "<<fixed<<setprecision(2)<<toan<<endl;
    cout<<"Diem van: "<<fixed<<setprecision(2)<<van<<endl;
    cout<<"Diem anh: "<<fixed<<setprecision(2)<<anh<<endl;
}