   M S B A M L   `   `   `  ����?  ;Bai1, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullclr-namespace:Bai1Bai1  5   	       Bai1.Window2   5   	   W SPresentationCore, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089R NWindowsBase, Version=6.0.2.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=6.0.2.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   $localclr-namespace:Bai1     5   	     � Title$  Window2��5   	   $	��450��6   $	��800��6&   $��20(�5	   	   .��5      � $��10q�6    � RowDefinitions 5   
   �� 5      $
��auto �6   6,   �� 5      6   .+�5   
   �� $��30(�6   $��0��6   
��� � �$
��Bold"�6>   $*��$Bảng nhân viên cao tuổi nhất��6P   $��Center=�6w   6�   &   System.Windows.Controls.DataGrid  5   
   -   5          Name$ dgNVCT��5      $��1��6#      dataGridHeader   ColumnHeaderStyle# [  60      AutoGenerateColumns$ False��6d      Columns 5      0  *System.Windows.Controls.DataGridTextColumn  5      ,  &System.Windows.Controls.DataGridColumn   Header$ Mã nhân viên��6%   1  +System.Windows.Controls.DataGridBoundColumn   Binding 6;   �� *MaNV+  5      $ 	Họ tên��6%    65   �� *HoTen+  5      $ Giới tính��6%    68   �� *
GioiTinh+  5      $ 
Phòng ban��6%    68   �� *
PhongBan+  5      $ 
Ngày sinh��6%    68   �� *
NgaySinh+ �� StringFormat$ dd-MMM-yyyy��4  .System.Windows.Controls.DataGridTemplateColumn  5      $ Tuổi��6)   	   Width5  /System.Windows.Controls.DataGridLengthConverter$	 * 67     tuoiColumnTemplate
   CellTemplate#
 [ 6A   5      5!      5"      