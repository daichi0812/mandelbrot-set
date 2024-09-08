// -2 <= x, y <= 2 の中でマンデルブロ集合を満たす集合をテキストファイルで出力する。
// comlexライブラリは使用しない

#include <bits/stdc++.h>
using namespace std;

double complex_absolute_value(double real, double imag){
    return sqrt(real * real + imag * imag);
}

double complex_mul_real(double real1, double imag1, double real2, double imag2){
    return real1 * real1 - imag1 * imag1 + real2;
}

double complex_mul_imag(double real1, double imag1, double real2, double imag2){
    return 2 * real1 * imag1 + imag2;
}


bool meet_madelbrot_set(double real, double imag){
    double z_real = 0.0;
    double z_imag = 0.0;

    for(int i = 0; i < 20; i++){
        if(complex_absolute_value(z_real, z_imag) >= 2.0){
            return false;
        }
        z_real = complex_mul_real(z_real, z_imag, z_real, z_imag) + real;
        z_imag = complex_mul_imag(z_real, z_imag, z_real, z_imag) + imag;
    }

    return true;
}

int main(){
    int nx = 400;
    int ny = 400;
    double min_x = -2.0;
    double max_x = 2.0;
    double min_y = -2.0;
    double max_y = 2.0;
    double dx = (max_x - min_x) / (double)nx;
    double dy = (max_y - min_y) / (double)ny;

    // ファイルを出力ストリームとして開く
    ofstream file("ex1.txt");

    if(!file.is_open()){
        // ファイルオープンに失敗した場合のエラー処理
        cerr << "Cannot open file: ex1.txt" << endl;
        return 1; // エラーの場合、終了コードとして 1 を返す
    }

    file << "mandelbrot set" << "\n";

    for(int i = 0; i < ny; i++){
        for(int j = 0; j < nx; j++){
            double x = min_x + dx * (double)j;
            double y = min_y + dy * (double)i;

            if(meet_madelbrot_set(x, y)){
                file << "real: "<< fixed << setprecision(2) << x << "  " << "imag: " << y << "\n";
            }
        }
    }

    file.close();

    return 0;
}