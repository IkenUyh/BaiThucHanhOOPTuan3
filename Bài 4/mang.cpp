#include"mang.h"
int cArray::dem=0;
cArray::~cArray(){
    --dem;
    if(a!=nullptr){
        delete[] a;
        a=nullptr;
        n=0;
    }
}
cArray::cArray(){
    a=nullptr; n=0;
    ++dem;
}
cArray::cArray(int n){
    while(n<=0){
        cout<<"Nhap lai so phan tu mang > 0: "; 
        cin>>n;
    }
    this->n=n;
    a=new int[this->n];
    for(int i=0; i<this->n; i++) a[i]=0;
    ++dem;
}
cArray::cArray(int n, int m){
    while(n<=0){
        cout<<"Nhap lai so phan tu mang > 0: "; 
        cin>>n;
    }
    this->n=n;
    a=new int[this->n];
    for(int i=0; i<this->n; i++) a[i]=m;
    ++dem;
}
cArray::cArray(const cArray& nums){
    if(!nums.n){
        a=nullptr;
        this->n=0;
    }
    else{
        n=nums.n;
        a=new int[n];
        for(int i=0; i<n; i++) a[i]=nums.a[i];
    }
    ++dem;
}
int cArray::GetN() const{
    return this->n;
}
int* cArray::GetA() const{
    return this->a;
}
int cArray::GetDem(){
    return dem;
}
void cArray::SetN(int n){
    if(!n) this->~cArray();
    else{
        while(n<=0){
            cout<<"Nhap lai so phan tu mang > 0: ";
            cin>>n;
        }
        cArray nums(n);
        int min=n<this->n?n:this->n;
        for(int i=0; i<min; i++) nums.a[i]=a[i];
        for(int i=min; i<n; i++) nums.a[i]=0;
        this->~cArray();
        *this=nums;
    }
}
void cArray::SetA(const cArray& nums){
    *this=nums;
}
void cArray::Nhap(){
    if(a!=nullptr) this->~cArray();
    cout<<"Nhap so phan tu cua mang: "; cin>>n;
    while(n<=0){
        cout<<"So phan tu cua mang phai lon hon 0! ";
        cout<<"Moi ban nhap lai"; cin>>n;
    }
    a=new int[n];
    for(int i=0; i<n; i++){
        cout<<"a["<<i<<"] = "; 
        cin>>a[i];
    }
}
void cArray::Xuat() const{
    if(a==nullptr) cout<<"Mang rong"<<endl;
    else{
        for(int i=0; i<n; i++) cout<<a[i]<<" ";
        cout<<endl;
    }
}
int cArray::DemX(int x) const{
    int cnt=0;
    for(int i=0; i<n; i++){
        if(a[i]==x) cnt++;
    }
    return cnt;
}
bool cArray::KiemTraTangDan() const{
    for(int i=1; i<n; i++){
        if(a[i-1]>a[i]) return false;
    }
    return true;
}
bool isPrime(int n){
    if(n<2) return false;
    for(int i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return true;
}
int partition(int* &a, int l, int r){
    int pivot=a[r];
    int i=l-1;
    for(int j=l; j<r; j++){
        if(a[j]<=pivot){
            ++i; int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    ++i;
    swap(a[i], a[r]);
    return i;
}
void QuickSort(int* &a, int l, int r){
    if(l>=r) return;
    int p=partition(a, l, r);
    QuickSort(a, l, p-1);
    QuickSort(a, p+1, r);
}
void cArray::TimLeBeNhat() const{
    int min_le=INT_MAX;
    for(int i=0; i<n; i++){
        if(a[i]%2!=0&&a[i]<min_le) min_le=a[i];
    }
    if(min_le==INT_MAX) cout<<"Khong co so le trong mang"<<endl;
    else cout<<"So le nho nhat trong mang: "<<min_le<<endl;
}
void cArray::TimSNTLonNhat() const{
    int max_SNT=-1;
    for(int i=0; i<n; i++){
        if(isPrime(a[i])&&a[i]>max_SNT) max_SNT=a[i];
    }
    if(max_SNT==-1) cout<<"Khong co so nguyen to trong mang"<<endl;
    else cout<<"So nguyen to lon nhat trong mang: "<<max_SNT<<endl;
}
void cArray::SapXepMangTang(){
    QuickSort(a, 0, n-1);
}
void cArray::SapXepMangGiam(){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j]<a[j+1]) swap(a[j], a[j+1]);
        }
    }
}