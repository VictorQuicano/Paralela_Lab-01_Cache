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

    for(int i = 1; i <= 80; i++){
        MAX_ARRAY.push_back(i*10);
    }
    ofstream file("Tres_bucles.txt");
    for(int &MAX:MAX_ARRAY){
        vector<vector<double>> A(MAX, vector<double>(MAX));
        vector<vector<double>> B(MAX, vector<double>(MAX));
        vector<vector<double>> result(MAX, vector<double>(MAX,0.0));
        
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                A[i][j] = rand() % 1000;
                B[i][j] = rand() % 1000;
            }
        }
        //multiplate vector A and B
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
    }
    file.close();
}