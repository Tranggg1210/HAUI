using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TX1
{
    internal class NhanVienThoiVu : NhanVien
    {
        private int _soNgayLV;

        // contructor
        public NhanVienThoiVu()
        {
            
        }
        public NhanVienThoiVu(string maNV, string hoTen, bool gt, int soNgayLV) : base(maNV, hoTen, gt)
        {
            this._soNgayLV = soNgayLV;
        }

        //getter and setter
        public int SoNgayLV()
        {
            return _soNgayLV;
        }

        public void SoNgayLV(int soNgayLV)
        {
            this._soNgayLV = soNgayLV;
        }

        //tinh tien luong
        public double TienLuong()
        {
            if (this._soNgayLV <= 10) return 200000 * SoNgayLV();
            return 200000 + (this._soNgayLV - 10)*400000;
        }

        public override string ToString()
        {
            return base.ToString() + $", Số ngày làm việc: {soNgayLamViec}, Tiền lương: {TinhLuong()} VND";
        }

       

    }
}
