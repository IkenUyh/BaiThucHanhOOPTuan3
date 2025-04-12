#include<iostream>
#include<iomanip>
#include<climits>
using namespace std;
class cArray{
    private:
        int* a;
        int n; 
        static int dem;
    public:
        ~cArray();
        cArray();
        cArray(int);
        cArray(int, int);
        cArray(const cArray&);
        int GetN() const;
        int* GetA() const;
        static int GetDem();
        void SetN(int);
        void SetA(const cArray&);
        void Nhap();
        void Xuat() const;
        int DemX(int) const;
        bool KiemTraTangDan() const;
        void TimLeBeNhat() const;
        void TimSNTLonNhat() const;
        void SapXepMangTang();
        void SapXepMangGiam();
};