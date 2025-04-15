#include"nhanvienvp.cpp"
class cListNhanVienVP{
    private:
        int n; 
        cNhanVienVP* a;
        static int dem;
    public:
        ~cListNhanVienVP();
        cListNhanVienVP();
        cListNhanVienVP(int);
        cListNhanVienVP(int, cNhanVienVP);
        cListNhanVienVP(const cNhanVienVP*, int);
        cListNhanVienVP(const cListNhanVienVP&);
        int GetN() const;
        cNhanVienVP* GetA() const;
        static int GetDem();
        void SetN(int);
        void SetA(const cListNhanVienVP&);
        void Nhap();
        void Xuat() const;
        cNhanVienVP LuongCaoNhat() const;
        double TraTienNhanVien() const;
        cNhanVienVP NhanVienLonTuoi() const;
        void SapXepTangDan();
};