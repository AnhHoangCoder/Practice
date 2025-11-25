#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

using namespace std;
using ll = long long;

int idx_kh = 0, idx_mh = 0 , idx_hd = 0;

class HoaDon;

class KhachHang{
    string id , name , gender , date , addr;
public:
    static KhachHang dskh[25];
    static int n;
    
    friend istream& operator >> (istream &in , KhachHang &a){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idx_kh;
        a.id = "KH" + tmp.str();
        if(in.peek() == '\n') in.ignore();
        getline(in , a.name);
        in >> a.gender >> a.date;
        in.ignore(numeric_limits<streamsize>::max() , '\n');
        getline(in , a.addr);
        dskh[n++] = a;
        return in;
    }
    string get_id(){
        return id;
    }
    string get_name(){
        return name;
    }
    string get_addr(){
        return addr;
    }
    friend class HoaDon;
};

KhachHang KhachHang::dskh[25];
int KhachHang::n = 0;

class MatHang{
    string id , name , dvt;
    int buy , pass;
public:
    static MatHang dsmh[45];
    static int n;
    
    friend istream& operator >> (istream &in , MatHang &a){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idx_mh;
        a.id = "MH" + tmp.str();
        if(in.peek() == '\n') in.ignore();
        getline(in , a.name);
        in >> a.dvt >> a.buy >> a.pass;
        in.ignore(numeric_limits<streamsize>::max() , '\n');
        dsmh[n++] = a;
        return in;
    }
    string get_id(){
        return id;
    }
    string get_name(){
        return name;
    }
    string get_dvt(){
        return dvt;
    }
    int get_buy(){
        return buy;
    }
    int get_pass(){
        return pass;
    }
    friend class HoaDon;
};

MatHang MatHang::dsmh[45];
int MatHang::n = 0;

class HoaDon{
    string id_hd , id_kh , id_mh;
    int sl;
public:
    friend istream& operator >> (istream &in , HoaDon &a){
        ostringstream tmp;
        tmp << setw(3) << setfill('0') << ++idx_hd;
        a.id_hd = "HD" + tmp.str();
        in >> a.id_kh >> a.id_mh >> a.sl;
        return in;
    }
    friend ostream& operator << (ostream &out , HoaDon a){
        KhachHang *kh = nullptr;
        MatHang *mh = nullptr;

        for(int i=0;i<KhachHang::n;i++){
            if(a.id_kh == KhachHang::dskh[i].get_id()){
                kh = &KhachHang::dskh[i];
                break;
            }
        }

        for(int i=0;i<MatHang::n;i++){
            if(a.id_mh == MatHang::dsmh[i].get_id()){
                mh = &MatHang::dsmh[i];
                break;
            }
        }

        ll sum = a.sl * mh->get_pass();

        out << a.id_hd << " " << kh->get_name() << " " <<
        kh->get_addr() << " " << mh->get_name() << " " <<
        mh->get_dvt() << " " << mh->get_buy() << " " <<
        mh->get_pass() << " " << a.sl << " " << sum
        << endl;
        return out;
    }
};

int main(){
    KhachHang dskh[25];
    MatHang dsmh[45];
    HoaDon dshd[105];
    int N,M,K,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> dskh[i];
    cin >> M;
    for(i=0;i<M;i++) cin >> dsmh[i];
    cin >> K;
    for(i=0;i<K;i++) cin >> dshd[i];
    
    for(i=0;i<K;i++) cout << dshd[i];
    return 0;
}