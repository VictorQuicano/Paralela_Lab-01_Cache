#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;
using namespace std::chrono;

int main(){
    vector<int> MAX_ARRAY;

    for(int i = 2; i <= 20; i+=2){
        MAX_ARRAY.push_back(i*100);
    }
    ofstream file("Tres_bucles.txt");
    ofstream file2("Bloques.txt");
    for(int &MAX:MAX_ARRAY){
        cout<<"[====================="<<MAX<<"=====================]"<<endl;
        vector<vector<double>> A(MAX, vector<double>(MAX));
        vector<vector<double>> B(MAX, vector<double>(MAX));
        vector<vector<double>> result(MAX, vector<double>(MAX,0.0));
        //Llenar las matrices A y B
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                A[i][j] = rand() % 1000;
                B[i][j] = rand() % 1000;
            }
        }
        //MULTIPLICACIÓN POR 3 LOOPS
        auto start = high_resolution_clock::now();
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                for(int k = 0; k < MAX; k++){
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        auto end = high_resolution_clock::now();
        cout << "Time: " << duration_cast<microseconds>(end - start).count() << " microseconds" << endl;
        file << duration_cast<microseconds>(end - start).count() << endl;
        
        //MULTIPLICACIÓN POR BLOQUES
        int blockSize = (MAX <= 100) ? 16 :
                (MAX <= 200) ? 32 :
                (MAX <= 400) ? 64 :
                (MAX <= 800) ? 128 : 256;
        start = high_resolution_clock::now();
        // Recorrer las matrices por bloques
        for (int i = 0; i < MAX; i += blockSize) {
            for (int j = 0; j < MAX; j += blockSize) {
                for (int k = 0; k < MAX; k += blockSize) {

                    // Multiplicar los bloques A(i:k) * B(k:j) y sumarlos en C(i:j)
                    for (int ii = i; ii < min(i + blockSize, MAX); ++ii) {
                        for (int jj = j; jj < min(j + blockSize, MAX); ++jj) {
                            for (int kk = k; kk < min(k + blockSize, MAX); ++kk) {
                                result[ii][jj] += A[ii][kk] * B[kk][jj];
                            }
                        }
                    }
                }
            }
        }
        
        end = high_resolution_clock::now();
        cout << "Time: " << duration_cast<microseconds>(end - start).count() << " microseconds" << endl;
        file2 << duration_cast<microseconds>(end - start).count() << endl;
    }
    file.close();
    file2.close();
}