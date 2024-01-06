#include <bits/stdc++.h>
using namespace std;

struct Quat {
    string tenHang;
    string mauSac;
    double giaBan;
};

bool compareToPrice(const Quat& quat1, const Quat& quat2) {
    return quat1.giaBan > quat2.giaBan;
}

vector<Quat> chonQuatBan(int p, vector<Quat>& danh_sach) {
    sort(danh_sach.begin(), danh_sach.end(), compareToPrice);
    vector<Quat> danh_sach_quat_chon;
    double tongGia = 0;

    for (const Quat& quat : danh_sach) {
    	danh_sach_quat_chon.push_back(quat);
            tongGia += quat.giaBan;
        if (tongGia > p) {
            return danh_sach_quat_chon;
        }
    }

    
}

int main() {
    int p = 1000000;
    int n = 8;

    vector<Quat> d = {
        {"Hang A", "Den", 200000},
        {"Hang B", "Trang", 150000},
        {"Hang C", "Xanh", 300000},
        {"Hang D", "Do", 180000},
        {"Hang E", "Vang", 250000},
        {"Hang F", "Nau", 220000},
        {"Hang G", "Hong", 270000},
        {"Hang H", "Xam", 230000},
    };

    vector<Quat> ket_qua = chonQuatBan(p, d);
    cout << "So tien " << p << " co the mua duoc " << ket_qua.size() << " chiec quat ban:" << endl;
    for (const Quat& quat : ket_qua) {
        cout << "Hang: " << quat.tenHang << ", gia ban: " << quat.giaBan << endl;
    }
    return 0;
}

