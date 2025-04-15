#include"congtyvp.cpp"
int main(){
    cListNhanVienVP danhsachNV;
    cout<<"\n=====NHAP DANH SACH NHAN VIEN=====\n";
    danhsachNV.Nhap();
    cout<<"\n=====DANH SACH NHAN VIEN=====\n";
    danhsachNV.Xuat();
    cout<<"\n=====NHAN VIEN CO LUONG CAO NHAT=====\n";
    danhsachNV.LuongCaoNhat().Xuat();
    cout<<"\nTONG LUONG PHAI TRA: "<<danhsachNV.TraTienNhanVien()<<endl;
    cout<<"\n=====NHAN VIEN CO TUOI CAO NHAT=====\n";
    danhsachNV.NhanVienLonTuoi().Xuat();
    cout<<"\n=====SAP XEP TANG DAN THEO LUONG=====\n";
    danhsachNV.SapXepTangDan(); danhsachNV.Xuat();
    return 0;
}