   M S B A M L   `   `   `  ����G  CDEMOBANHANG2, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null+clr-namespace:DEMOBANHANG2DEMOBANHANG2  5   	       DEMOBANHANG2.MainWindow   5   	   W SPresentationCore, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   ,localclr-namespace:DEMOBANHANG2     5   	   -   5          � Title$  
MainWindow��5	   	   $��20(�6   $	��650��6*   $	��800��67   .��5
      � $��10q�6    � ColumnDefinitions 5   
   �� 5      $
��Auto �6   $	��183��6,   �� 5       � RowDefinitions 5   
   �� 5      $
��Auto �6   �� 5      $
��Auto �6   �� 5      $
��Auto �6   �� 5      $
��Auto �6   �� 5      $
��Auto �6   �� 5      �� 5      $
��Auto �6   .+�5   
   �� $��Mã sản phẩm: ��6   $��0��6(   $��0��65      
styleLabel#��[  6E   $��	10,5,10,5q�6i   �� 5   
   -   5         ��Name$ txtMaSP��5      $��0��6#   $��1��60     styleTextBox#��[ 6@   $��10,7,0,8q�6f   $	��280��6x   �� 5   
   $��Tên sản phẩm: ��6   $��1��6)   $��0��66   #��[  6F   $��	10,5,10,5q�6j   �� 5   
   -   5        $ txtTenSP��5      $��1��6$   $��1��61   #��[ 6A   $��10,7,0,8q�6g   $	��280��6y   �� 5   
   $��Loại sản phẩm: ��6   $��2��6*   $��0��67   #��[  6G   $��	10,5,10,5q�6k   �� 5    
   -   5         ��Name$ cbLoaiSP��5       $��2��6%   $��1��62   $	��300��6B   $��10,7,0,8q�6N   $
��Left=�6`   �� 5"   
   $��Đơn giá: ��6   $��3��6$   $��0��61   #��[  6A   $��	10,5,10,5q�6e   �� 5#   
   -   5        $ 	txtDonGia��5#      $��3��6%   $��1��62   #��[ 6B   $��10,7,0,8q�6h   $	��280��6z   �� 5%   
   $��Số lượng có: ��6   $��4��6(   $��0��65   #��[  6E   $��	10,5,10,5q�6i   �� 5&   
   -   5        $ txtSoLuongCo��5&      $��4��6(   $��1��65   #��[ 6E   $��10,8,0,7q�6k   $	��280��6}   &   System.Windows.Controls.DataGrid  5(   
   -   5          Name$ dtgSP��5(        styleHeading   ColumnHeaderStyle# [ 6"   $��5��6T   $��0��6a   $��2��6q      AutoGenerateColumns$ False��6�      Columns 5)      0  *System.Windows.Controls.DataGridTextColumn  5*      ,  &System.Windows.Controls.DataGridColumn	   Header$	 Mã SP��6%   1  +System.Windows.Controls.DataGridBoundColumn
   Binding
 64   �� *MaSp+  5+      $	 Tên SP��6%   
 65   �� *TenSp+  5,      $	 Tên loại SP��6%   
 6:   �� *	TenLoai+  5-      $	 
Đơn giá��6%     styleHeading2   ElementStyle# [ 66   
 6d   �� *DonGia+  5.      $	 Số lượng có��6%   # [ 6:   
 6h   �� *	SoLuongCo+  5/         Width5  /System.Windows.Controls.DataGridLengthConverter$ * 6%   $	 Thành tiền��6/   
 6C   �� *	ThanhTien+51      �� 53   
   $��5��6   $��0��6"   $
��Left=�62   $��2��6M    �� Orientation$ 
Horizontal=�6a   $��110,341,0,0q�6z   $	��560��6�   .+�54      �� -   5         ��Name$
 them��54   f     styleButton#��[ 6     tempalteButton#��[ 6:   $
��Them��6t   6�   �� 55      -	   5        $	 sua��55   f   #��[ 6   #��[ 6:   $	��Sua��6s   �� 56      -
   5        $	 xoa��56   f   #��[ 6   #��[ 6:   $
��Xóa��6s   �� 57      -   5        $	 tim��57   f   #��[ 6   #��[ 6:   $
��Tìm��6s   58      59      5:      