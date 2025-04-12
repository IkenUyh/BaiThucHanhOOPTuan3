#include"thisinh.cpp"
class cListCandidate{
    private:
        int n; 
        cCandidate* a;
        static int dem;
    public:
        ~cListCandidate();
        cListCandidate();
        cListCandidate(int);
        cListCandidate(int, cCandidate);
        cListCandidate(const cCandidate*, int);
        cListCandidate(const cListCandidate&);
        int GetN() const;
        cCandidate* GetA() const;
        static int GetDem();
        void SetN(int);
        void SetA(const cListCandidate&);
        void Nhap();
        void Xuat() const;
        cCandidate ThuKhoa() const;
        void SapXepGiamDan();
};