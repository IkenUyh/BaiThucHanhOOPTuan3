#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class cNhanVienSX{
    private:
        string id;
        string name;
        int ngay, thang, nam;
        int soluong;
        double dongia;
        static int dem;
    public:
        ~cNhanVienSX();
        cNhanVienSX();
        cNhanVienSX(string);
        cNhanVienSX(string, string);
        cNhanVienSX(string, string, int, int, int, double);
        cNhanVienSX(int, int, int);
        cNhanVienSX(double);
        cNhanVienSX(const cNhanVienSX&);
        string GetID() const;
        string GetName() const;
        int GetNgay() const;
        int GetThang() const;
        int GetNam() const;
        int GetSoLuong() const;
        double GetDonGia() const;
        static int GetDem();
        void SetID(string);
        void SetName(string);
        void SetNgay(int);
        void SetThang(int);
        void SetNam(int);
        void SetNgayThangNam(int, int, int);
        void SetSoLuong(int);
        void SetDonGia(double);
        void Nhap();
        void Xuat() const;
        bool KiemTraHopLe() const;
};