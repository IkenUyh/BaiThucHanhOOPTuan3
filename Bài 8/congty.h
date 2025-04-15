#include"nhanvien.cpp"
class cListNhanVienSX{
    private:
        int n; 
        cNhanVienSX* a;
        static int dem;
    public:
        ~cListNhanVienSX();
        cListNhanVienSX();
        cListNhanVienSX(int);
        cListNhanVienSX(int, cNhanVienSX);
        cListNhanVienSX(const cNhanVienSX*, int);
        cListNhanVienSX(const cListNhanVienSX&);
        int GetN() const;
        cNhanVienSX* GetA() const;
        static int GetDem();
        void SetN(int);
        void SetA(const cListNhanVienSX&);
        void Nhap();
        void Xuat() const;
        cNhanVienSX LuongThapNhat() const;
        double TraTienNhanVien() const;
        cNhanVienSX NhanVienLonTuoi() const;
        void SapXepTangDan();
};