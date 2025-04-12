#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class cCandidate{
    private:
        string id;
        string name;
        int ngay, thang, nam;
        double toan, van, anh;
        static int dem;
    public:
        ~cCandidate();
        cCandidate();
        cCandidate(string);
        cCandidate(string, string);
        cCandidate(string, string, int, int, int, double, double, double);
        cCandidate(int, int, int);
        cCandidate(double, double, double);
        cCandidate(const cCandidate&);
        string GetID() const;
        string GetName() const;
        int GetNgay() const;
        int GetThang() const;
        int GetNam() const;
        double GetToan() const;
        double GetVan() const;
        double GetAnh() const;
        static int GetDem();
        void SetID(string);
        void SetName(string);
        void SetNgay(int);
        void SetThang(int);
        void SetNam(int);
        void SetNgayThangNam(int, int, int);
        void SetToan(double);
        void SetVan(double);
        void SetAnh(double);
        void SetToanVanAnh(double, double, double);
        void Nhap();
        void Xuat() const;
        bool KiemTraHopLe() const;
};