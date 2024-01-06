#include<bits/stdc++.h>
using namespace std;

struct QuatBan {
    string ten_hang;
    string mau_sac;
    int gia_ban;
};

bool soSanhTheoGia(const QuatBan& quat1, const QuatBan& quat2) {
    return quat1.gia_ban < quat2.gia_ban;
}

vector<QuatBan> chonQuatBan(int p, vector<QuatBan>& danh_sach_quat_ban) {
    sort(danh_sach_quat_ban.begin(), danh_sach_quat_ban.end(), soSanhTheoGia);
    
    vector<QuatBan> danh_sach_duoc_chon;
    int tong_gia = 0;

    for (const QuatBan& quat : danh_sach_quat_ban) {
        if (tong_gia + quat.gia_ban <= p) {
            danh_sach_duoc_chon.push_back(quat);
            tong_gia += quat.gia_ban;
        }
    }

    return danh_sach_duoc_chon;
}

int main() {
    int p = 1000000;  
    int n = 8;  

    vector<QuatBan> danh_sach_quat = {
        {"Hang A", "Ðen", 200000},
        {"Hang B", "Trang", 150000},
        {"Hang C", "Xanh", 300000},
        {"Hang D", "Ðo", 180000},
        {"Hang E", "Vang", 250000},
        {"Hang F", "Nau", 220000},
        {"Hang G", "Hong", 270000},
        {"Hang H", "Xam", 230000},
    };

    vector<QuatBan> ket_qua = chonQuatBan(p, danh_sach_quat);
    cout << "So tien toi da " << p << " co the mua duoc " << ket_qua.size() << " chiec quat ban:" << endl;
    for (const QuatBan& quat : ket_qua) {
        cout << "Hang: " << quat.ten_hang << ", gia ban: " << quat.gia_ban << endl;
    }

    return 0;
}

