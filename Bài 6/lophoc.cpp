#include"lophoc.h"
int cListCandidate::dem=0;
cListCandidate::~cListCandidate(){
    --dem;
    if(a!=nullptr){
        delete[] a;
        a=nullptr;
        n=0;
    }
}
cListCandidate::cListCandidate(){
    a=nullptr; n=0;
    ++dem;
}
cListCandidate::cListCandidate(int n){
    while(n<=0){
        cout<<"So luong thi sinh phai > 0!";
        cout<<"Moi ban nhap lai: " ;
        cin>>n;
    }
    this->n=n;
    a=new cCandidate[this->n];
    ++dem;
}
cListCandidate::cListCandidate(int n, cCandidate ts){
    while(n<=0){
        cout<<"So luong thi sinh phai > 0!";
        cout<<"Moi ban nhap lai: " ;
        cin>>n;
    }
    this->n=n;
    a=new cCandidate[this->n];
    for(int i=0; i<this->n; i++) a[i]=ts;
    ++dem;
}
cListCandidate::cListCandidate(const cCandidate* arr, int n){
    a=new cCandidate[n];
    for(int i=0; i<n; i++) a[i]=arr[i];
    ++dem;
}
cListCandidate::cListCandidate(const cListCandidate& nums){
    if(!nums.n){
        a=nullptr;
        this->n=0;
    }
    else{
        n=nums.n;
        a=new cCandidate[n];
        for(int i=0; i<n; i++) a[i]=nums.a[i];
    }
    ++dem;
}
int cListCandidate::GetN() const{
    return this->n;
}
cCandidate* cListCandidate::GetA() const{
    return this->a;
}
int cListCandidate::GetDem(){
    return dem;
}
void cListCandidate::SetN(int n){
    if(!n) this->~cListCandidate();
    else{
        while(n<=0){
            cout<<"So luong thi sinh phai > 0!";
            cout<<"Moi ban nhap lai: " ;
            cin>>n;
        }
        cListCandidate nums(n);
        for(int i=0; i<this->n; i++) nums.a[i]=a[i];
        this->~cListCandidate();
        *this=nums;
    }
}
void cListCandidate::SetA(const cListCandidate& nums){
    *this=nums;
}
void cListCandidate::Nhap(){
    if(a!=nullptr) this->~cListCandidate();
    cout<<"Nhap so luong thi sinh: "; cin>>n;
    while(n<=0){
        cout<<"So luong thi sinh phai > 0!";
        cout<<"Moi ban nhap lai: " ;
        cin>>n;
    }
    a=new cCandidate[n];
    for(int i=0; i<n; i++) a[i].Nhap();
}
void cListCandidate::Xuat() const{
    if(a==nullptr) cout<<"Khong co thi sinh nao"<<endl;
    else{
        for(int i=0; i<n; i++){
            int sum=a[i].GetToan()+a[i].GetVan()+a[i].GetAnh();
            if(sum>15) a[i].Xuat();
        }
        cout<<endl;
    }
}
int partition(cCandidate* &a, int l, int r){
    cCandidate pivot=a[r];
    int pivot_sum=a[r].GetToan()+a[r].GetVan()+a[r].GetAnh();
    int i=l-1;
    for(int j=l; j<r; j++){
        int sum=a[j].GetToan()+a[j].GetVan()+a[j].GetAnh();
        if(sum>=pivot_sum){
            ++i; cCandidate temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    ++i;
    swap(a[i], a[r]);
    return i;
}
void QuickSort(cCandidate* &a, int l, int r){
    if(l>=r) return;
    int p=partition(a, l, r);
    QuickSort(a, l, p-1);
    QuickSort(a, p+1, r);
}
cCandidate cListCandidate::ThuKhoa() const{
    cCandidate thukhoa=a[0];
    int nmax=a[0].GetToan()+a[0].GetVan()+a[0].GetAnh();
    for(int i=1; i<n; i++){
        int sum=a[i].GetToan()+a[i].GetVan()+a[i].GetAnh();
        if(sum>nmax){
            nmax=sum;
            thukhoa=a[i];
        }
    }
    return thukhoa;
}
void cListCandidate::SapXepGiamDan(){
    QuickSort(a, 0, n-1);
}