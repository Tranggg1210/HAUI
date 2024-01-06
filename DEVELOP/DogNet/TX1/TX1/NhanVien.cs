using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TX1
{
    abstract class NhanVien
    {
        private string _maNV;
        private string _hoTen;
        private bool _gioiTinh;

        //contructor
        public NhanVien()
        {
            
        }

        public NhanVien(string maNV, string hoTen, bool gt)
        {
            this._maNV = maNV;
            this._hoTen = hoTen;
            this._gioiTinh = gt;
        }

        //getter and setter
        public string MaNV()
        {
            return _maNV;
        }

        public void MaNV(string maNV)
        {
            this._maNV = maNV;
        }

        public string HoTen()
        {
            return _hoTen;
        }

        public void HoTen(string hoTen)
        {
            this._hoTen = hoTen;
        }

        public bool GioiTinh()
        {
            return _gioiTinh;
        }

        public void GioiTinh(bool gt)
        {
            this._gioiTinh = gt;
        }

      
        public override string ToString()
        {
            return (
                "\nMa nhan vien: " + _maNV
                +"\nHo ten: " + _hoTen+
                "\nGioiTinh: " + _gioiTinh
                );
        }

        public override bool Equals(object? obj)
        {
            if (obj == null || GetType() != obj.GetType()) return false;
            NhanVien other = (NhanVien)obj;
            return MaNV() == other.MaNV();
        }
    }
}
