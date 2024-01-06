using NhanVien.MoHinhDuLieu;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using NhanVien.MoHinhDuLieu;

namespace NhanVienDemo
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        QlnhanSuContext db = new QlnhanSuContext();
        public MainWindow()
        {
            InitializeComponent();
            Window_Loaded();
        }

        private void Window_Loaded()
        {
            throw new NotImplementedException();
        }

        private void btnThem_Click(object sender, RoutedEventArgs e)
        {
            // Trước khi thêm vào cơ sở dữ liệu, kiểm tra giá trị hợp lệ
            if (!string.IsNullOrEmpty(txtMaNV.Text) && !string.IsNullOrEmpty(txtHoTen.Text) && dtpNgaySinh.SelectedDate != null && cboMaPhongBan.SelectedValue != null)
            {
                NhanVien nvMoi = new NhanVien();
                nvMoi.MaNv = txtMaNV.Text;
                nvMoi.HoTen = txtHoTen.Text;
                nvMoi.Gioitinh = radNam.IsChecked == true ? "Nam" : "Nữ";

                string nn = "";
                if (ckbAnh.IsChecked == true)
                {
                    nn = "Anh";
                }
                if (ckbPhap.IsChecked == true)
                {
                    nn += ", Phap";
                }
                if (ckbTrung.IsChecked == true)
                {
                    nn += ", Trung";
                }

                
                if (!string.IsNullOrEmpty(nn))
                {
                 
                    if (nn.StartsWith(","))
                    {
                        nn = nn.Substring(1);
                    }
                    nvMoi.NgoaiNgu = nn;
                }

                nvMoi.NgaySinh = (DateTime)dtpNgaySinh.SelectedDate;
                nvMoi.MaPb = cboMaPhongBan.SelectedValue.ToString();

             
                if (db != null)
                {
                    db.NhanViens.Add(nvMoi);
                    db.SaveChanges();
                    HienThi();
                }
            }

        }

        private void HienThi()
        {
            var queryNhanVien = from nv in db.NhanViens
                                select nv;
            dtgNhanVien.ItemsSource = queryNhanVien.ToList();
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            HienThi();
        }

    }
}
