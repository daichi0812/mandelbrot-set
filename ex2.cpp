// -2 <= x, y <= 2 の中でマンデルブロ集合を満たす集合をテキストファイルで出力する。
// complex ライブラリを使用してみる
#include <bits/stdc++.h>
using namespace std;

bool meet_mandelbrot_set(complex<double> c){
    complex<double> z(0.0, 0.0);
    for(int i = 0; i < 20; i++){
        if(abs(z) >= 2.0){
            return false;
        }
        z = z * z + c;
    }
    return true;
}

int main(){
    int nx = 400;
    int ny = 400;
    double xmin = -2.0;
    double xmax = 2.0;
    double ymin = -2.0;
    double ymax = 2.0;
    double dx = (xmax - xmin) / (double)nx;
    double dy = (ymax - ymin) / (double)ny;

    ofstream file("ex2.txt");

    if(!file.is_open()){
        cerr << "Cannot open file" << endl;
        return 1;
    }

    for(int i = 0; i < ny; i++){
        for(int j = 0; j < nx; j++){
            double x = xmin + dx * (double)j;
            double y = ymin + dy * (double)i;
            complex<double> c(x, y);

            if(meet_mandelbrot_set(c)){
                file << "real: "<< fixed << setprecision(2) << x << "  " << "imag: " << y << "\n";
            }
        }
    }

    file.close();
    return 0;
}