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

namespace Ontap1
{
    public partial class MainWindow : Window
    {
        // Khai báo khởi tạo List chứa các nhân viên
        List<Nhanvien> list = new List<Nhanvien>();
        List<Nhanvien> listNVCaoTuoi = new List<Nhanvien>(); 
        public MainWindow()
        {
            InitializeComponent();
        }

        private void btnNhap_Click(object sender, RoutedEventArgs e)
        {
            try
            {
               if(isCheck())
                {
                    // Thêm nhân viên vào danh sách
                    Nhanvien nvMoi = new Nhanvien();
                    nvMoi.MaNhanVien = txtMNV.Text;
                    nvMoi.HoTen = txtName.Text;
                    nvMoi.NgaySinh = (DateTime)ngaySinh.SelectedDate;
                    if (gtNam.IsChecked == true)
                        nvMoi.GioiTinh = "Nam";
                    else nvMoi.GioiTinh = "Nữ";
                    nvMoi.PhongBan = phongBan.Text;
                    nvMoi.HeSoLuong = double.Parse(txtHSL.Text);
                    list.Add(nvMoi);

                    // hiển thị lên dataGrid
                    dataNhanVien.ItemsSource = null;
                    dataNhanVien.ItemsSource = list;
                }    
            }
            catch(Exception ex) {
                Console.WriteLine("Lỗi: " + ex.ToString());
            }
        }

        private void btnOpenTab_Click(object sender, RoutedEventArgs e)
        {
            try {
                int max = list[0].Tuoi;
                foreach(Nhanvien item in list)
                {
                    if(item.Tuoi > max) max = item.Tuoi;
                }
                foreach (Nhanvien item in list)
                {
                    if (item.Tuoi == max) listNVCaoTuoi.Add(item);
                }
                Window2 newWi = new Window2();
                newWi.dataNVLT.ItemsSource = listNVCaoTuoi;
                newWi.Show();
            } catch(Exception ex) { 
                Console.WriteLine(ex.ToString()); 
            }
        }

        private bool isCheck()
        {
            if(txtMNV.Text.Trim() == "")
            {
                MessageBox.Show("Bạn chưa nhập mã nhân viên","Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
                return false;
            }
            if (txtName.Text.Trim() == "")
            {
                MessageBox.Show("Bạn chưa nhập họ tên nhân viên", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
                return false;
            }
            if (txtHSL.Text.Trim() == "")
            {
                MessageBox.Show("Bạn chưa nhập hệ số lương", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
                return false;
            }
            if(DateTime.Now.Year - ((DateTime)ngaySinh.SelectedDate).Year < 18)
            {
                MessageBox.Show("Tuổi của nhân viên phải lớn hơn hoặc bằng 18", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
                return false;
            }
            try
            {
                double hsl = double.Parse(txtHSL.Text.Trim());
                if (hsl <= 0)
                {
                    MessageBox.Show("Hệ số lương phải lớn hơn 0", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
                    return false;
                }
            }catch(FormatException ex)
            {
                MessageBox.Show("Hệ số lương phải là số thực", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
                return false;
            }

            // Bắt lỗi trùng mã nhân viên
            bool isTrungMa = list.Any(e => e.MaNhanVien.Equals(txtMNV.Text, StringComparison.OrdinalIgnoreCase));
            if(isTrungMa)
            {
                MessageBox.Show("Mã nhân viên bạn nhập bị trùng", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
                return false;
            }
            return true;
        }
    }

     class Nhanvien
    {
        public string MaNhanVien { get; set; }
        public string HoTen { get; set; }
        public DateTime NgaySinh { get; set; }
        public string GioiTinh { get; set; }
        public string PhongBan { get; set; }
        public double HeSoLuong { get; set; }
        public int Tuoi
        {
            get
            {
                return DateTime.Now.Year - NgaySinh.Year;
            }
        }
    }
}
