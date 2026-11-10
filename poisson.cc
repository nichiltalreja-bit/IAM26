#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

double Poisson(double mu, int k){
        return(std::pow(mu, k) * std::exp(-mu))/std::tgamma(k + 1);
    }

int main(){
    std::vector<int> counts(11);
    std::ifstream fin("sums.txt");
    std::ofstream fout("hist.txt");
    int a;
    int n = 0;
    double sum = 0;
    while (fin>>a){
        counts.at(a) += 1;
        n +=1;
        sum += a;
    }
    double mean = sum/n;
    std::cout << "Mean: " << mean << std :: endl;
    std::cout << "n: " << n << std :: endl;
    for (unsigned int k = 0 ; k < counts.size(); ++ k ) {
    fout << k << " " << counts[k]<<std::endl;
    std::cout << k << " " << counts[k]<<std::endl;
    }


    std::ofstream fout2("histpoi.txt");
    for (unsigned int k = 0 ; k < counts.size(); ++ k ) {
    fout2 << k << " " << counts[k]<< " "<< n*Poisson(mean, k) <<std::endl;
    }
}