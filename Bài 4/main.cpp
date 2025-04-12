#include"mang.cpp"
int main(){
    cout<<"=====KIEM TRA CAC HAM KHOI TAO====="<<endl;
    cout<<"Tong so doi tuong: "<<cArray::GetDem()<<endl;
    cout<<"\n1. Ham khoi tao mac dinh:"<<endl;
    cArray arr1;
    cout<<"Noi dung mang: "; arr1.Xuat();
    cout<<"\n2. Ham khoi tao voi kich thuoc:"<<endl;
    cArray arr2(5);
    cout<<"Noi dung mang: "; arr2.Xuat();
    cout<<"\n3. Ham khoi tao voi kich thuoc va gia tri:"<<endl;
    cArray arr3(4, 7);
    cout<<"Noi dung mang: "; arr3.Xuat();
    cout<<"\n4. Ham khoi tao sao chep:"<<endl;
    cArray arr4(arr3);
    cout<<"Mang goc: "; arr3.Xuat();
    cout<<"Mang sao chep: "; arr4.Xuat();
    cout<<"\nTong so doi tuong sau khi khoi nao: "<<cArray::GetDem()<<endl;
    cout<<"\n=====KIEM TRA CAC PHUONG THUC====="<<endl;
    cout<<"\n1. Nhap va Xuat:"<<endl;
    cArray arr5;
    cout<<"Vui long nhap gia tri mang:" <<endl;
    arr5.Nhap();
    cout<<"Noi dung mang: "; arr5.Xuat();
    cout<<"\n4. DemX:"<<endl;
    cout<<"Kiem tra mot so xuat hien trong mang bao nhieu lan"<<endl;
    cout<<"Moi ban nhap mot so: "; int x; cin>>x;
    cout<<"Số lần xuất hiện của "<<x<<": "<< arr5.DemX(x)<<endl;
    cout<<"\n5. KiemTraTangDan:"<<endl;
    cout<<"Mang co tang dan khong? "<<(arr5.KiemTraTangDan() ? "Co" : "Khong")<<endl;
    cout<<"\n6. TimLeBeNhat:"<<endl;
    arr5.TimLeBeNhat();
    cout<<"\n7. TimSNTLonNhat:"<<endl;
    arr5.TimSNTLonNhat();
    cout<<"\n8. SapXepMangTang:"<<endl;
    arr5.SapXepMangTang();
    cout<<"Mang sau khi sap xep tang dan: "; arr5.Xuat();
    cout<<"Mang bay gio co tang dan khong? "<<(arr5.KiemTraTangDan() ? "Co" : "Khong")<<endl;
    cout<<"\n9. SapXepMangGiam:"<<endl;
    arr5.SapXepMangGiam();
    cout<<"Mang sau khi sap xep giam dan: "; arr5.Xuat();
    cout<<"\n=====KIEM TRA HAM HUY====="<<endl;
    {
        cArray temp(3, 9);
        cout<<"Da tao mang tam thoi: "; temp.Xuat();
        cout<<"Tong so doi tuong: " << cArray::GetDem() << endl;
    }
    cout<<"Sau khi huy mang tam thoi, tong so doi tuong: "<<cArray::GetDem()<<endl;
    cout<<"\n=====KET THUC CHUONG TRINH====="<<endl;
    return 0;
}