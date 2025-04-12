#include"dathuc.h"
int cDaThuc::dem=0;
cDaThuc::~cDaThuc(){
    --dem;
    if(heSo!=nullptr){
        delete[] heSo;
        heSo=nullptr;
        n=0;
    }
}
cDaThuc::cDaThuc(){
    n=0;
    heSo=new double[1]{0};
    ++dem;
}
cDaThuc::cDaThuc(int n){
    this->n=n;
    heSo=new double[this->n+1]{0};
    ++dem;
}
cDaThuc::cDaThuc(int n, double* hs){
    this->n=n;
    heSo=new double[this->n+1];
    for(int i=0; i<=n; i++) heSo[i]=hs[i];
    ++dem;
}
cDaThuc::cDaThuc(const cDaThuc& dt){
    n=dt.n;
    heSo=new double[n+1];
    for(int i=0; i<=n; i++) heSo[i]=dt.heSo[i];
    ++dem;
}
int cDaThuc::GetN() const{
    return this->n;
}
double* cDaThuc::GetHeSo() const{
    return this->heSo;
}
int cDaThuc::GetDem(){
    return dem;
}
void cDaThuc::SetN(int n){
    delete[] heSo;
    this->n=n;
    heSo=new double[this->n+1]{0};
}
void cDaThuc::SetHeSo(const cDaThuc& dt){
    if(n!=dt.n){
        delete[] heSo;
        n=dt.n;
        heSo=new double[n+1];
    }
    for(int i=0; i<=n; i++) heSo[i]=dt.heSo[i];
}
void cDaThuc::Nhap(){
    cout<<"Nhap bac cua da thuc: "; cin>>n;
    delete[] heSo;
    heSo=new double[n+1];
    for(int i=n; i>=0; i--){
        cout<<"Nhap he so a"<<i<<": ";
        cin>>heSo[i];
    }
}
void cDaThuc::Xuat() const{
    cout<<"P(x) = ";
    bool fi=true;
    for(int i=n; i>=0; i--){
        if(heSo[i]){
            if(!fi&&heSo[i]>0) cout<<" + ";
            if(heSo[i]<0) cout<<" - ";
            if(abs(heSo[i])!=1||i==0) cout<<abs(heSo[i]);
            if(i>0) cout<<"x";
            if(i>1) cout<<"^"<<i;
            fi=false;
        }
    }
    if(fi) cout<<"0";
    cout<<endl;
}
double cDaThuc::TinhGiaTri(double x) const{
    double res=0;
    for(int i=0; i<=n; i++){
        res+=heSo[i]*pow(x, i);
    }
    return res;
}
cDaThuc cDaThuc::Tong(const cDaThuc& dt) const{
    int BacMax=max(n, dt.n);
    cDaThuc sum(BacMax);
    for(int i=0; i<=BacMax; i++){
        double hs1=(i<=n)?heSo[i]:0;
        double hs2=(i<=dt.n)?dt.heSo[i]:0;
        sum.heSo[i]=hs1+hs2;
    }
    return sum;
}
cDaThuc cDaThuc::Hieu(const cDaThuc& dt) const{
    int BacMax=max(n, dt.n);
    cDaThuc tru(BacMax);
    for(int i=0; i<=BacMax; i++){
        double hs1=(i<=n)?heSo[i]:0;
        double hs2=(i<=dt.n)?dt.heSo[i]:0;
        tru.heSo[i]=hs1-hs2;
    }
    return tru;
}