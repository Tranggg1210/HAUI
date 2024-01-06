using System;
using System.Collections.Generic;

namespace DEMOBANHANG2.MoHinhDuLieu;

public partial class LoaiSp
{
    public string MaLoai { get; set; } = null!;

    public string? TenLoai { get; set; }

    public virtual ICollection<SanPham> SanPhams { get; set; } = new List<SanPham>();
}
