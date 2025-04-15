#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class cNhanVienVP{
    private:
        string id;
        string name;
        int ngay, thang, nam;
        double luong;
        static int dem;
    public:
        ~cNhanVienVP();
        cNhanVienVP();
        cNhanVienVP(string);
        cNhanVienVP(string, string);
        cNhanVienVP(string, string, int, int, int, double);
        cNhanVienVP(int, int, int);
        cNhanVienVP(double);
        cNhanVienVP(const cNhanVienVP&);
        string GetID() const;
        string GetName() const;
        int GetNgay() const;
        int GetThang() const;
        int GetNam() const;
        double GetLuong() const;
        static int GetDem();
        void SetID(string);
        void SetName(string);
        void SetNgay(int);
        void SetThang(int);
        void SetNam(int);
        void SetNgayThangNam(int, int, int);
        void SetLuong(double);
        void Nhap();
        void Xuat() const;
        bool KiemTraHopLe() const;
};