#include"diem.h"
class cDaGiac{
    private:
        DIEM* dsDiem;
        int soDinh;
        static int dem;
    public: 
        ~cDaGiac();
        cDaGiac();
        cDaGiac(int);
        cDaGiac(const DIEM*, int);
        cDaGiac(const cDaGiac&);
        int GetSoDinh() const;
        DIEM GetDinh(int) const;
        static int GetDem();
        void SetDinh(int, const DIEM&);
        void SetDiem(const DIEM*, int);
        void Nhap();
        void Xuat() const;
        double TinhChuVi() const;
        double TinhDienTich() const;
        string KiemTraDaGiacLoi() const;
        bool KiemTraDiemNamTrong(const DIEM&) const;
        void TinhTien(double, double);
        void Quay(int);
        void PhongTo(double);
        void ThuNho(double);
        void DoiXungOx();
        void DoiXungOy();
        void DoiXungGoc();
};