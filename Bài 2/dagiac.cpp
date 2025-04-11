#include"dagiac.h"
int cDaGiac::dem=0;
cDaGiac::~cDaGiac(){
    --dem;
    delete[] dsDiem;
}
cDaGiac::cDaGiac() : soDinh(3){
    dsDiem=new DIEM[soDinh];
    ++dem;
}
cDaGiac::cDaGiac(int soDinh) : soDinh(soDinh>2?soDinh:3){
    dsDiem=new DIEM[this->soDinh];
    ++dem;
}
cDaGiac::cDaGiac(const DIEM* arr, int soDinh) : soDinh(soDinh>2?soDinh:3){
    dsDiem=new DIEM[this->soDinh];
    for(int i=0; i<this->soDinh; i++){
        dsDiem[i]=arr[i];
    }
    ++dem;
}
cDaGiac::cDaGiac(const cDaGiac& dg) : soDinh(dg.soDinh){
    dsDiem=new DIEM[soDinh];
    for(int i=0; i<soDinh; i++){
        dsDiem[i]=dg.dsDiem[i];
    }
    ++dem;
}
int cDaGiac::GetSoDinh() const{
    return this->soDinh;
}
DIEM cDaGiac::GetDinh(int index) const{
    if(index>=0&&index<soDinh) return dsDiem[index];
    cout<<"Chi so khong hop le!"<<endl;
    return DIEM();
}
int cDaGiac::GetDem(){
    return dem;
}
void cDaGiac::SetDinh(int index, const DIEM& diem){
    if(index>=0&&index<soDinh) dsDiem[index]=diem;
    else cout<<"Chi so khong hop le!"<<endl;
}
void cDaGiac::SetDiem(const DIEM* arr, int n){
    if(n<3){
        cout<<"So dinh phai lon hon 3!"<<endl;
        return;
    }
    delete[] dsDiem;
    soDinh=n;
    dsDiem=new DIEM[soDinh];
    for(int i=0; i<soDinh; i++){
        dsDiem[i]=arr[i];
    }
}
void cDaGiac::Nhap(){
    cout<<"Nhap so dinh: "; cin>>soDinh;
    while(soDinh<3){
        cout<<"So dinh phai lon hon 3! Moi ban nhap lai: "<<endl;
        cout<<"Nhap so dinh: "; cin>>soDinh;
    }
    delete[] dsDiem;
    dsDiem=new DIEM[soDinh];
    for(int i=0; i<soDinh; i++){
        cout<<"Nhap dinh thu "<<i+1<<": "<<endl;
        dsDiem[i].Nhap();
    }
}
void cDaGiac::Xuat() const{
    cout<<"Da giac co "<<soDinh<<" dinh: "<<endl;
    for(int i=0; i<soDinh; i++){
        cout<<"Dinh "<<i+1<<": ";
        dsDiem[i].Xuat();
        cout<<endl;
    }
    cout<<endl;
}
double cDaGiac::TinhChuVi() const{
    double chuvi=0;
    for(int i=0; i<soDinh; i++){
        chuvi+=dsDiem[i].TinhKhoangCach(dsDiem[(i+1)%soDinh]);
    }
    return chuvi;
}
double cDaGiac::TinhDienTich() const{
    // Sử dụng công thức Shoelace để tính diện tích đa giác
    double dientich=0;
    for(int i=0; i<soDinh-1; i++){
        dientich+=dsDiem[i].GetX()*dsDiem[i+1].GetY()-dsDiem[i+1].GetX()*dsDiem[i].GetY();
    }
    dientich+=dsDiem[soDinh-1].GetX()*dsDiem[0].GetY()-dsDiem[0].GetX()*dsDiem[soDinh-1].GetY();
    return fabs(dientich)/2.0;
}
string cDaGiac::KiemTraDaGiacLoi() const{
    if(soDinh<3) return "Khong phai da giac";
    bool huongDuong=true;
    bool daXacDinhHuong=false;
    for (int i=0;i<soDinh; i++) {
        DIEM p1=dsDiem[i];
        DIEM p2=dsDiem[(i + 1)%soDinh]; 
        DIEM p3=dsDiem[(i + 2)%soDinh];
        double v1_x=p2.GetX()-p1.GetX();
        double v1_y=p2.GetY()-p1.GetY();
        double v2_x=p3.GetX()-p2.GetX();
        double v2_y=p3.GetY()-p2.GetY();
        double TichCheo=v1_x*v2_y-v1_y*v2_x;
        if(!daXacDinhHuong){
            huongDuong=(TichCheo>0);
            daXacDinhHuong=true;
        }
        else if((TichCheo>0)!=huongDuong) return "Da giac khong loi";
    }
    return "Da giac loi";
}
bool cDaGiac::KiemTraDiemNamTrong(const DIEM& diem) const{
    // Sử dụng thuật toán ray casting
    int cnt=0;
    for(int i=0; i<soDinh; i++){
        DIEM p1=dsDiem[i];
        DIEM p2=dsDiem[(i+1)%soDinh];
        if (p1.GetY()==diem.GetY()&&p2.GetY()==diem.GetY() &&
            ((p1.GetX()<=diem.GetX()&&diem.GetX()<=p2.GetX()) ||
             (p2.GetX()<=diem.GetX()&&diem.GetX()<=p1.GetX()))){ 
            return true;
        }
        if((diem.GetY()>p1.GetY())!=(diem.GetY()>p2.GetY())){
            double intersectX=p1.GetX()+(diem.GetY()-p1.GetY())*(p2.GetX()-p1.GetX())/(p2.GetY()-p1.GetY());
            if(diem.GetX()<intersectX) {
                cnt++;
            }
        }
    }
    return cnt%2==1;
}
void cDaGiac::TinhTien(double dx, double dy){
    for(int i=0; i<soDinh; i++) dsDiem[i].TinhTien(dx, dy);
}
void cDaGiac::Quay(int alpha){
    for(int i=0; i<soDinh; i++) dsDiem[i].Quay(alpha);
}
void cDaGiac::PhongTo(double scale){
    if(scale<=0){
        cout<<"He so phong to phai duong!"<<endl;
        return;
    }
    for(int i=0; i<soDinh; i++) dsDiem[i].PhongTo(scale);
}
void cDaGiac::ThuNho(double scale){
    if(scale<=0){
        cout<<"He so thu nho phai duong!"<<endl;
        return;
    }
    for(int i=0; i<soDinh; i++) dsDiem[i].ThuNho(scale);
}
void cDaGiac::DoiXungOx(){
    for(int i=0; i<soDinh; i++) dsDiem[i].DoiXungOx();
}
void cDaGiac::DoiXungOy(){
    for(int i=0; i<soDinh; i++) dsDiem[i].DoiXungOy();
}
void cDaGiac::DoiXungGoc(){
    for(int i=0; i<soDinh; i++) dsDiem[i].DoiXungGoc();
}