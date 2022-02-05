#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

double add_time_average(int** a, int** b, int** c, int m, int n);
void add(int** a, int** b, int** c, int m, int n);

int main(void) {
    ofstream fout;
    fout.open("add.csv", ofstream::out);
    fout << "n, time\n";
    
    int** a = new int* [3000]();
    int** b = new int* [3000]();
    int** c = new int* [3000]();
    for (int i = 0; i < 3000; ++i) {
        a[i] = new int [3000]();
        b[i] = new int [3000]();
        c[i] = new int [3000]();
    }
    
    for (int n = 100; n <= 3000; n += 100) {
        double time = add_time_average(a, b, c, n, n);
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

double add_time_average(int** a, int** b, int** c, int m, int n) {
    steady_clock::time_point begin, end;
    double total_time = 0;
    for (int i = 0; i < 10000; ++i) {
        begin = steady_clock::now();
        add(a, b, c, m, n);
        end = steady_clock::now();
        total_time += duration_cast<microseconds>(end - begin).count();
    }
    return total_time / 10000;
}

void add(int** a, int** b, int** c, int m, int n) {
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            c[i][j] = a[i][j] + b[i][j];
}
