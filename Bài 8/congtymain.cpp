#include"congty.cpp"
int main(){
    cListNhanVienSX danhsachNV;
    cout<<"\n=====NHAP DANH SACH NHAN VIEN=====\n";
    danhsachNV.Nhap();
    cout<<"\n=====DANH SACH NHAN VIEN=====\n";
    danhsachNV.Xuat();
    cout<<"\n=====NHAN VIEN CO LUONG THAP NHAT=====\n";
    danhsachNV.LuongThapNhat().Xuat();
    cout<<"\nTONG LUONG PHAI TRA: "<<danhsachNV.TraTienNhanVien()<<endl;
    cout<<"\n=====NHAN VIEN CO TUOI CAO NHAT=====\n";
    danhsachNV.NhanVienLonTuoi().Xuat();
    cout<<"\n=====SAP XEP TANG DAN THEO LUONG=====\n";
    danhsachNV.SapXepTangDan(); danhsachNV.Xuat();
    return 0;
}