using DEMOBANHANG.MoHinhDuLieu;
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

namespace DEMOBANHANG
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        QlbanHangContext dp = new QlbanHangContext();
        public MainWindow()
        {
            InitializeComponent();
        }


        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            hienThiDuLieu();
            var queryLoaiSP = from lsp in dp.LoaiSps
                              select lsp;
            cbLoaiSP.ItemsSource = queryLoaiSP.ToList();
            cbLoaiSP.DisplayMemberPath = "TenLoai";
            cbLoaiSP.SelectedValuePath = "MaLoai";
            cbLoaiSP.SelectedIndex = 0;

        }

        private void hienThiDuLieu()
        {
            var mangSP = from sp in dp.SanPhams
                         orderby sp.DonGia descending
                         select new { 
                            sp.MaSp,
                            sp.TenSp,
                            sp.MaLoaiNavigation.TenLoai,
                            sp.DonGia,
                            sp.SoLuongCo,
                            ThanhTien = sp.SoLuongCo*sp.DonGia
                         };

            dtgSP.ItemsSource = null;
            dtgSP.ItemsSource = mangSP.ToList();

        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            if(isCheck())
            {
                SanPham sanPham = new SanPham();
                sanPham.MaSp = txtMaSP.Text;
                sanPham.TenSp = txtTenSP.Text;
                sanPham.DonGia = int.Parse(txtDonGia.Text);
                sanPham.MaLoai = cbLoaiSP.SelectedValue.ToString();
                sanPham.SoLuongCo = int.Parse(txtSoLuongCo.Text);
                
                dp.SanPhams.Add(sanPham);
                dp.SaveChanges();
                hienThiDuLieu();
            }    
            
        }

        private bool isCheck()
        {
            if(txtMaSP.Text.Trim() == "")
            {
                MessageBox.Show("Bạn chưa nhập mã sản phẩm", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                return false;
            }
            var querySP = from sp in dp.SanPhams
                          select sp;
            List<SanPham> mangSp = querySP.ToList();
            bool checkMasp = mangSp.Any(e => e.MaSp.Equals(txtMaSP.Text.Trim(), StringComparison.OrdinalIgnoreCase));
            if(checkMasp)
            {
                MessageBox.Show("Mã sản phẩm bị trùng", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                return false;
            }
            if (txtTenSP.Text.Trim() == "")
            {
                MessageBox.Show("Bạn chưa nhập tên sản phẩm", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                return false;
            }
            if (txtTenSP.Text.Trim() == "")
            {
                MessageBox.Show("Bạn chưa nhập tên sản phẩm", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                return false;
            }
            if (txtDonGia.Text.Trim() == "")
            {
                MessageBox.Show("Bạn chưa nhập đơn giá", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                return false;
            }
            try
            {
                int dongia = int.Parse(txtDonGia.Text);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Đơn giá bạn nhập không phải số", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                return false;
            }
            if (txtSoLuongCo.Text.Trim() == "")
            {
                MessageBox.Show("Bạn chưa nhập số lượng có", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                return false;
            }
            try
            {
                int dongia = int.Parse(txtSoLuongCo.Text);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Số lượng có bạn nhập không phải số", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                return false;
            }
            return true;
        }
        private bool isCheck2()
        {
            if (txtMaSP.Text.Trim() == "")
            {
                MessageBox.Show("Bạn chưa nhập mã sản phẩm để sửa", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                return false;
            }
            if (txtTenSP.Text.Trim() == "")
            {
                MessageBox.Show("Bạn chưa nhập tên sản phẩm", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                return false;
            }
            if (txtTenSP.Text.Trim() == "")
            {
                MessageBox.Show("Bạn chưa nhập tên sản phẩm", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                return false;
            }
            if (txtDonGia.Text.Trim() == "")
            {
                MessageBox.Show("Bạn chưa nhập đơn giá", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                return false;
            }
            try
            {
                int dongia = int.Parse(txtDonGia.Text);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Đơn giá bạn nhập không phải số", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                return false;
            }
            if (txtSoLuongCo.Text.Trim() == "")
            {
                MessageBox.Show("Bạn chưa nhập số lượng có", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                return false;
            }
            try
            {
                int dongia = int.Parse(txtSoLuongCo.Text);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Số lượng có bạn nhập không phải số", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                return false;
            }
            return true;
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            if(isCheck2())
            {
                var queryPham = from sp in dp.SanPhams
                                where sp.MaSp == txtMaSP.Text
                                select sp;
                SanPham sanPham = queryPham.First();
                sanPham.TenSp = txtTenSP.Text;
                sanPham.DonGia = int.Parse(txtDonGia.Text);
                sanPham.MaLoai = cbLoaiSP.SelectedValue.ToString();
                sanPham.SoLuongCo = int.Parse(txtSoLuongCo.Text);
                dp.SaveChanges();
                hienThiDuLieu();
            }    
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            if (txtMaSP.Text.Trim() == "")
            {
                MessageBox.Show("Bạn chưa nhập mã sản phẩm để xóa", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }
            else
            {
                var queryXoa = from sp in dp.SanPhams
                               where sp.MaSp == txtMaSP.Text
                               select sp;
                
               
                if(queryXoa.Count() > 0  )
                {
                    SanPham sanPhamXoa = queryXoa.First();
                    dp.SanPhams.Remove( sanPhamXoa );
                    dp.SaveChanges();
                    hienThiDuLieu();
                }
                else
                {
                    MessageBox.Show("Không có mã sản phẩm bạn muốn xóa", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                    return;
                }   

            }
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            var query = from cthd in dp.ChiTietHoaDons
                        select new
                        {
                            cthd.MaSp,
                            cthd.MaSpNavigation.TenSp,
                            cthd.MaSpNavigation.MaLoaiNavigation.TenLoai,
                            cthd.SoLuongMua,
                            ThanhTien = cthd.DonGia*cthd.SoLuongMua
                        };
            Window2 screen = new Window2();
            screen.Show();
            screen.dtgSPW2.ItemsSource = query.ToList();
            
        }
    }
}
