   M S B A M L   `   `   `  ����F  BDEMOBANHANG, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null)clr-namespace:DEMOBANHANGDEMOBANHANG  5   	       DEMOBANHANG.MainWindow   5   	   W SPresentationCore, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   +localclr-namespace:DEMOBANHANG     5   	   -   5          � Title$  Quản lý bán hàng��5	   	   $��20(�6"   $	��650��60   $	��800��6=   .��5
      � $��10q�6    � ColumnDefinitions 5   
   �� 5      $
��auto �6   �� 5       � RowDefinitions 5   
   �� 5      $
��auto �6   �� 5      $
��auto �6   �� 5      $
��auto �6   �� 5      $
��auto �6   �� 5      $
��auto �6   �� 5      �� 5      $
��auto �6   .+�5   
   �� $��Mã sản phẩm:��6   $��0��6'   $��0��64      
styleLabel#��[  6D   �� 5   
   -   5         ��Name$ txtMaSP��5      $��0��6#   $��1��60     styleTextBox#��[ 6A   �� 5   
   $��Tên sản phẩm:��6   $��1��6(   $��0��65   #��[  6E   �� 5    
   -   5        $ txtTenSP��5       $��1��6$   $��1��61   #��[ 6A   �� 5#   
   $��Loại sản phẩm:��6   $��2��6)   $��0��66   #��[  6F   �� 5$   
   -   5         ��Name$ cbLoaiSP��5$      $��2��6%   $��1��62   $	��300��6B   $
��Left=�6N   $��30��6i   $��	10,5,10,5q�6u   6�   �� 5'   
   $��Đơn giá:��6   $��3��6#   $��0��60   #��[  6@   �� 5(   
   -   5        $ 	txtDonGia��5(      $��3��6%   $��1��62   #��[ 6B   �� 5+   
   $��Số lượng có:��6   $��4��6'   $��0��64   #��[  6D   �� 5,   
   -   5        $ txtSoLuongCo��5,      $��4��6(   $��1��65   #��[ 6E   &   System.Windows.Controls.DataGrid  5/   
   -   5          Name$ dtgSP��5/   E     styleHeading   ColumnHeaderStyle# [ 6   $��0��6T   $��2��6d   $��5��6x      AutoGenerateColumns$ False��6�      Columns 50      0  *System.Windows.Controls.DataGridTextColumn  51      ,  &System.Windows.Controls.DataGridColumn	   Header$	 Mã SP��6&   1  +System.Windows.Controls.DataGridBoundColumn
   Binding
 65   �� *MaSp+  52      $	 Tên SP��6%   
 65   �� *TenSp+  53      $	 Tên loại SP��6%   
 6:   �� *	TenLoai+4  .System.Windows.Controls.DataGridTemplateColumn  54      $	 
Đơn giá��6)     templateHeading   CellTemplate# [ 6:     55      $	 Số lượng có��6)     template# [ 6>     56         Width5  /System.Windows.Controls.DataGridLengthConverter$ * 6%   $	 Thành tiền��6/   
 6C   �� *	ThanhTien+58      �� 5:   
   $��0��6   $��2��6#   $��6��67   .��5;      �� $��Center=�6   $��Center=�66    �� Orientation$ 
Horizontal=�6Q   .+�5<      �� -   5          templateButton#��[ 5<        styleButton#��[ 6D   .��6~   Thêm6�   �� 5=      -	   5        #��[ 5=      #��[ 6D   .��6�   Sửa6�   �� 5>      -
   5        #��[ 5>      #��[ 6D   .��6�   Xóa6�   �� 5?      -   5        #��[ 5?      #��[ 6D   .��6�   Nhìn6�   5@      5A      5B      5C      