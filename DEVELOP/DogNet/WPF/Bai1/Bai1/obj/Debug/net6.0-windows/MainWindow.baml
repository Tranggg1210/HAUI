   M S B A M L   `   `   `  ����?  ;Bai1, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullclr-namespace:Bai1Bai1  5   	       Bai1.MainWindow   5   	   W SPresentationCore, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   $localclr-namespace:Bai1     5   	     � Title$(  "Bài kiểm tra thường xuyên 2��5   	   $	��650��6-   $	��800��6:   $��20(�6F   .��5	      � $��10q�6    � ColumnDefinitions 5   
   �� 5      $
��auto �6   �� 5       � RowDefinitions 5   
   �� 5      $
��auto �6   �� 5      $
��auto �6   �� 5      $
��auto �6   �� 5      $
��auto �6   �� 5      $
��auto �6   �� 5      $
��auto �6   �� 5      $
��auto �6   �� 5      �� 5      $
��auto �6   .+�5   
   �� $��1��6   $��0��6   $��8��6/   $��2��6@   
��� � �$��1q�6h   
�������6|   �� 5   
   $��0��6   $��0��6   $��2��6-   $��30(�5       $'��!Quản lý thông tin nhân viên��6    $��Center=�5!      $��DemiBold"�5"      
����  �5#      �� 5'   
   $��1��5(      $��0��6   $��1��6*   $��Mã nhân viên: ��5)      $��
10 0 10 10q�6&   �� 5+   
   -   5         ��Name$ txtMa��5+      $
��Left=�6!   $��30��6<   $	��200��6H   $��1��6U   $��1��6b   $��10, 5, 0, 5q�6r   �� 5.   
   $��2��5/      $��0��6   $��1��6+   $��Họ tên: ��50      $��
10 0 10 10q�6!   �� 52   
   -   5        $ txtHoTen��52      $
��Left=�6$   $��30��6?   $	��400��6K   $��2��6X   $��1��6e   $��10, 5, 0, 5q�6u   �� 55   
   $��3��56      $��0��6   $��1��6+   $��Ngày sinh: ��57      $��
10 0 10 10q�6$   (  "System.Windows.Controls.DatePicker  59   
   -   5        $��dtpNgaySinh��59   H      SelectedDate 1/1/20006   $��Center=�6-   $
��Left=�6[   $	��200��6v   $��3��6�   $��1��6�   $��10 0 0 0q�6�   �� 5<   
   $��4��5=      $��0��6   $��1��6+   $��Giới tính: ��5>      $��
10 0 10 10q�6$   �� 5@   
   $��4��6   $��1��6"    �� Orientation$ 
Horizontal=�62   $��Center=�6K   .+�5A      	� -   5         	�Name$ radNam��5A   M    d� 	IsChecked$
 TrueY�6   $��Center=�6+   $	��Nam��6]   $��10 0 0 0q�6k   	� 5B      -   5        $ radNu��5B   <   $��Center=�6   $
��Nữ��6K   $��30 0 0 0q�6X   5C      �� 5F   
   $��5��5G      $��0��6   $��1��6+   $��Phòng ban: ��5H      $��
10 0 10 10q�6$   �� 5J   
   -   5        $��cboPhongBan��5J   %    �� SelectedIndex$ 0��6   $��1��68   $��5��6H   $	��400��6U   $��10 5 0 5q�6a   $
��Left=�6s   .@�5K      �� .��6   Tổ chức6$   �� 5L      .��6   Kế hoạch6%   �� 5M      .��6   	Vật tư6#   5N      �� 5P   
   $��6��5Q      $��0��6   $��1��6+   $��Hệ số lương: ��5R      $��
10 0 10 10q�6&   �� 5T   
   -   5        $ txtHeSoLuong��5T      $��6��6(   $��1��65   $
��Left=�6E   $��10 0 0 0q�6`   $��30��6r   $��Center=�6~   $	��200��6�   &   System.Windows.Controls.DataGrid  5W   
   -   5        	  Name$	 dtgNhanVien��5X      $��7��5Y      $��0��6   $��2��6-   $��
10 0 10 10q�5Z         dataGridHeader
   ColumnHeaderStyle#
 [  5[         AutoGenerateColumns$ False��5\         Columns 5^      0  *System.Windows.Controls.DataGridTextColumn  5_      ,  &System.Windows.Controls.DataGridColumn   Header$ Mã nhân viên��6%   1  +System.Windows.Controls.DataGridBoundColumn   Binding 5`   %   �� *MaNV+  5b      $ 	Họ tên��6%    5c   %   �� *HoTen+  5e      $ Giới tính��6%    5f   %   �� *
GioiTinh+  5h      $ 
Phòng ban��6%    5i   %   �� *
PhongBan+  5k      $ 
Ngày sinh��6%    5l   %   �� *
NgaySinh+ �� StringFormat$ dd-MMM-yyyy��4  .System.Windows.Controls.DataGridTemplateColumn  5n      $ Tuổi��6)     tuoiColumnTemplate   CellTemplate# [ 68      Width5  /System.Windows.Controls.DataGridLengthConverter$ * 6k   5q      �� 5t   
   $��8��5u      $��0��6   $��2��6+   $��
10 0 10 10q�5v      $ 
Horizontal=�5w      $��Center=�5x      .+�5z      �� -	   5         ��Name$ btnNhap��5z      $��Nhập��6&   $	��120��65   $��40��6A   $��	5 5 20 5 q�6M     buttonTemplate#��[ 5{        buttonStyle#��[ 6A   6f   �� 5|      -
   5        $ btnWindown2��5|      $��Window 2��6*   $	��120��6=   $��40��6I   $��	5 5 20 5 q�6U   #��[ 5}      #��[ 6A   6f   5~      5      5�      