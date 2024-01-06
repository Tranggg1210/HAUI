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

namespace Bai1
{
    public partial class MainWindow : Window
    {
        // Khai báo khởi tạo List chứa các nhân viên
        List<NhanVien> list = new List<NhanVien>();
        public List<NhanVien> listNVCaoTuoiNhat = new List<NhanVien>();
        public MainWindow()
        {
            InitializeComponent();
        }

        private void btnNhap_Click_1(object sender, RoutedEventArgs e)
        {
            if(isCheck())
            {
                NhanVien newNV = new NhanVien();
                newNV.MaNV = txtMa.Text;
                newNV.HoTen = txtHoTen.Text;
                newNV.NgaySinh = (DateTime)dtpNgaySinh.SelectedDate;
                newNV.GioiTinh = radNam.IsChecked == true ? "Nam" : "Nữ";
                newNV.PhongBan = cboPhongBan.Text;
                newNV.HeSoLuong = double.Parse(txtHeSoLuong.Text);

                list.Add(newNV);
                dtgNhanVien.ItemsSource = null;
                dtgNhanVien.ItemsSource = list;
            }    
        }

        private void btnWindown2_Click(object sender, RoutedEventArgs e)
        {
            // tìm tuổi cao nhất 
            int tuoi = list[0].Tuoi;
            foreach(NhanVien vi in list)
            {
                if(vi.Tuoi > tuoi) {
                    tuoi = vi.Tuoi;
                }
            }

            // thêm nhân viên có độ tuổi = độ tuổi cao nhất vào mảng listNVCaoTuoiNhat
            foreach(NhanVien vi in list)
            {
                if(vi.Tuoi == tuoi)
                {
                    listNVCaoTuoiNhat.Add(vi);
                }    
            } 
            
            // hiển thị windown 2
            Window2 myWindown = new Window2();
            myWindown.dgNVCT.ItemsSource = listNVCaoTuoiNhat;
            myWindown.Show();
        }
        
        private bool isCheck()
        {
            // Người dùng phải nhập tất cả các trường dữ liệu
            if(txtMa.Text.Trim() == "")
            {
                MessageBox.Show("Bạn chưa nhập mã nhân viên!!!", "VALID DATA", MessageBoxButton.OK, MessageBoxImage.Error);
                txtMa.Focus();
                return false;
            }

            if (txtHoTen.Text.Trim() == "")
            {
                MessageBox.Show("Bạn chưa nhập họ tên!!!", "VALID DATA", MessageBoxButton.OK, MessageBoxImage.Error);
                txtHoTen.Focus();
                return false;
            }

            if (txtHeSoLuong.Text.Trim() == "")
            {
                MessageBox.Show("Bạn chưa nhập hệ số lương!!!", "VALID DATA", MessageBoxButton.OK, MessageBoxImage.Error);
                txtHeSoLuong.Focus();
                return false;
            }

            DateTime ns = (DateTime)dtpNgaySinh.SelectedDate;
            if((DateTime.Now.Year - ns.Year) < 18)
            {
                MessageBox.Show("Tuổi của nhân viên phải lớn hơn hoặc bằng 18", "VALID DATA", MessageBoxButton.OK, MessageBoxImage.Error);
                txtHeSoLuong.Focus();
                return false;
            }
            try
            {
                double hsl = double.Parse(txtHeSoLuong.Text);
                if (hsl <= 0)
                {
                    MessageBox.Show("Hệ số lương phải lớn hơn 0", "VALID DATA", MessageBoxButton.OK, MessageBoxImage.Error);
                    txtHeSoLuong.Focus();
                    return false;
                }
            }catch (Exception ex)
            {
                MessageBox.Show("Hệ số lương phải là số", "VALID DATA", MessageBoxButton.OK, MessageBoxImage.Error);
                return false;
            }

            return true;
        }
    }
}
