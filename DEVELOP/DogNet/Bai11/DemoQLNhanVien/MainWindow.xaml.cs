using DemoQLNhanVien.MoHinhDuLieu;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Intrinsics.Arm;
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

namespace DemoQLNhanVien
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
   
    public partial class MainWindow : Window
    {
        QlnhanSuContext dp = new QlnhanSuContext();
        public MainWindow()
        {
            InitializeComponent();
        }

        private void hienThiDuLieu()
        {
            txtMaNV.Text = "";
            txtHoTen.Text = "";
            var querySelect = from nv in dp.NhanViens
                              select nv;
            dtgNhanVien.ItemsSource = null;
            dtgNhanVien.ItemsSource = querySelect.ToList();
            var queryPhongBan = from pb in dp.PhongBans
                                select pb;
            cboMaPhongBan.ItemsSource = queryPhongBan.ToList();
            cboMaPhongBan.DisplayMemberPath = "TenPb";
            cboMaPhongBan.SelectedValuePath = "MaPb";
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            hienThiDuLieu();
        }

        private void btnThem_Click(object sender, RoutedEventArgs e)
        {
            if(isCheck())
            {
                NhanVien nv = new NhanVien();
                nv.MaNv = txtMaNV.Text;
                nv.HoTen = txtHoTen.Text;
                nv.NgaySinh = (DateTime)dtpNgaySinh.SelectedDate;
                nv.Gioitinh = radNam.IsChecked == true ? "Nam" : "Nữ";
                string nn = "";
                if(ckbAnh.IsChecked == true) { nn = "Anh"; }
                if(ckbTrung.IsChecked == true) { nn += ", Trung"; }
                if(ckbPhap.IsChecked == true) { nn += ", Pháp"; }
                if(nn.Substring(0,1) == ",")
                    nn = nn.Substring(2, nn.Length - 2).Trim();
                nv.NgoaiNgu = nn;
                nv.MaPb = cboMaPhongBan.SelectedValue.ToString();

                dp.NhanViens.Add(nv);
                dp.SaveChanges();

                hienThiDuLieu();
            }
        }

        private bool isCheck()
        {
            if(txtMaNV.Text.Trim() == "")
            {
                MessageBox.Show("Mã nhân viên không được trống", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Information);
                return false;
            }
            var query = from nv in dp.NhanViens
                        select nv;
            List<NhanVien> nhanVien = query.ToList();
            if (nhanVien.Any(nv => nv.MaNv == txtMaNV.Text))
            {
                MessageBox.Show("Mã nhân viên này đã tồn tại", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Information);
                return false;
            }
            if (txtHoTen.Text.Trim() == "")
            {
                MessageBox.Show("Họ tên nhân viên không được trống", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Information);
                return false;
            }    
            return true;
        }

        private void btnSua_Click(object sender, RoutedEventArgs e)
        {
            if (txtMaNV.Text.Trim() == "")
            {
                MessageBox.Show("Nhập mã nhân viên bạn cần sửa", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Information);
            }
            else
            {
                var querySua = from n in dp.NhanViens
                               where n.MaNv == txtMaNV.Text
                               select n;

                if (querySua.Count() > 0)
                {
                    NhanVien nv = querySua.First();
                    nv.HoTen = txtHoTen.Text;
                    nv.NgaySinh = (DateTime)dtpNgaySinh.SelectedDate;
                    nv.Gioitinh = radNam.IsChecked == true ? "Nam" : "Nữ";
                    string nn = "";
                    if (ckbAnh.IsChecked == true) { nn = "Anh"; }
                    if (ckbTrung.IsChecked == true) { nn += ", Trung"; }
                    if (ckbPhap.IsChecked == true) { nn += ", Pháp"; }
                    if (nn.Substring(0, 1) == ",")
                        nn = nn.Substring(2, nn.Length - 2);
                    nv.NgoaiNgu = nn;
                    nv.MaPb = cboMaPhongBan.SelectedValue.ToString();

                    dp.SaveChanges();

                    hienThiDuLieu();
                }
                else
                {
                    MessageBox.Show("Không tìm thấy nhân viên cần sửa", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Information);
                }
            }
        }

            private void btnXoa_Click(object sender, RoutedEventArgs e)
            {
                if (txtMaNV.Text.Trim() == "")
                {
                    MessageBox.Show("Nhập mã nhân viên bạn cần xóa", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Information);
                }
                else
                {
                    var queryXoa = from n in dp.NhanViens
                                   where n.MaNv == txtMaNV.Text
                                   select n;
                    if(queryXoa.Count() > 0)
                    {
                        NhanVien nv = queryXoa.First();
                        dp.NhanViens.Remove(nv);
                        dp.SaveChanges();
                        hienThiDuLieu();
                    }else
                    {
                        MessageBox.Show("Không tìm thấy nhân viên cần xóa", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Information);
                    }
                }
                           
            }

            private void dtgNhanVien_SelectionChanged(object sender, SelectionChangedEventArgs e)
            {
                try
                {
                    NhanVien selectedNhanVien = dtgNhanVien.SelectedItem as NhanVien;
                   if(selectedNhanVien != null)
                    {

                        txtMaNV.Text = selectedNhanVien.MaNv;
                        txtHoTen.Text = selectedNhanVien.HoTen;
                        dtpNgaySinh.SelectedDate = selectedNhanVien.NgaySinh;
                        if (selectedNhanVien.Gioitinh.Equals("Nam", StringComparison.OrdinalIgnoreCase)) radNam.IsChecked = true;
                        else radNu.IsChecked = true;

                        string[] nn = selectedNhanVien.NgoaiNgu.Split(", ");
                        if (nn.Length > 0)
                        {
                            foreach (string n in nn)
                            {
                                if (n.Equals("Anh", StringComparison.OrdinalIgnoreCase))
                                    ckbAnh.IsChecked = true;
                                else if (n.Equals("Trung", StringComparison.OrdinalIgnoreCase))
                                    ckbTrung.IsChecked = true;
                                else if (n.Equals("Pháp", StringComparison.OrdinalIgnoreCase)) ckbPhap.IsChecked = true;

                            }
                        }
                        else ckbAnh.IsChecked = false;
                        List<PhongBan> queryPhongBan = (from pb in dp.PhongBans
                                                        select pb).ToList();
                        cboMaPhongBan.ItemsSource = queryPhongBan.ToList();
                        cboMaPhongBan.DisplayMemberPath = "TenPb";
                        cboMaPhongBan.SelectedValuePath = "MaPb";
                        PhongBan select = (from pb in dp.PhongBans
                                           where pb.MaPb == selectedNhanVien.MaPb
                                           select pb).First();
                        int index = queryPhongBan.IndexOf(select);
                        if (index != -1)
                        {
                            cboMaPhongBan.SelectedIndex = index;
                        }
                }
            }
            catch(Exception ex)
                {
                    txtMaNV.Text = "";
                    txtHoTen.Text = "";
                }
            }
    }
}
