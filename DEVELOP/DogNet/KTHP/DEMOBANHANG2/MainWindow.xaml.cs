using DEMOBANHANG2.MoHinhDuLieu;
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

namespace DEMOBANHANG2
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        QlbanHangContext db = new QlbanHangContext();
        public MainWindow()
        {
            InitializeComponent();
        }

        private void them_Click(object sender, RoutedEventArgs e)
        {

        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            hienThi();
            var queryLoaiSP = from loai in db.LoaiSps
                              select loai;
            cbLoaiSP.ItemsSource = queryLoaiSP.ToList();
            cbLoaiSP.DisplayMemberPath = "TenLoai";
            cbLoaiSP.SelectedValuePath = "MaLoai";
            cbLoaiSP.SelectedIndex = 0;
        }

        private void hienThi()
        {
            var mangSP = from sp in db.SanPhams
                         select new
                         {
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
    }
}
