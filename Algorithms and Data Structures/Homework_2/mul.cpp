#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

double mul_time_average(int** a, int** b, int** c, int m, int n, int p);
void mul(int** a, int** b, int** c, int m, int n, int p);

int main(void) {
    ofstream fout;
    fout.open("mul.csv", ofstream::out);
    fout << "n, time(ms)\n";
    
    int** a = new int* [3000]();
    int** b = new int* [3000]();
    int** c = new int* [3000]();
    for (int i = 0; i < 3000; ++i) {
        a[i] = new int [3000]();
        b[i] = new int [3000]();
        c[i] = new int [3000]();
    }
    
    for (int n = 100; n <= 3000; n += 100) {
        double time = mul_time_average(a, b, c, n, n, n);
        fout << n << ", " << time << endl;
        cout << n << ": " << time << endl;
    }
    
    for (int i = 0; i < 3000; ++i) {
        delete [] a[i];
        delete [] b[i];
        delete [] c[i];
    }
    delete [] a;
    delete [] b;
    delete [] c;
    
    fout.close();
    return 0;
}

double mul_time_average(int** a, int** b, int** c, int m, int n, int p) {
    steady_clock::time_point begin, end;
    double total_time = 0;
    for (int i = 0; i < 100; ++i) {
        begin = steady_clock::now();
        mul(a, b, c, m, n, p);
        end = steady_clock::now();
        total_time += duration_cast<milliseconds>(end - begin).count();
    }
    return total_time / 100;
}

void mul(int** a, int** b, int** c, int m, int n, int p) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][j] * b[i][j];
        }
}
