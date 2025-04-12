#include<iostream>
#include<cmath>
using namespace std;
class cDaThuc{
    private:
        int n; 
        double* heSo;
        static int dem;
    public:
        ~cDaThuc();
        cDaThuc();
        cDaThuc(int);
        cDaThuc(int, double*);
        cDaThuc(const cDaThuc&);
        int GetN() const;
        double* GetHeSo() const;
        static int GetDem();
        void SetN(int);
        void SetHeSo(const cDaThuc&);
        void Nhap();
        void Xuat() const;
        double TinhGiaTri(double) const;
        cDaThuc Tong(const cDaThuc&) const;
        cDaThuc Hieu(const cDaThuc&) const;
};