#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

double n_mean = 3.11538;
double standard_deviation = 1.65365;
double Poisson(double mu, int k){
        return((std::pow(mu, k) * std::exp(-mu)))/std::tgamma(k + 1);}

double prob(const std::vector<int>&data, double mu){
    double product = 1.0;
    for (int k : data){
        product *= Poisson(mu, k);
    }
    return product;
}

double nll(const std::vector<int>&data,double mu){
    double sum = 0.0;
    for (int k : data){
        sum += std::log(Poisson(mu, k));
    }
    return -2*sum;
}

double lamda_times_minus_2(const std::vector<int>&data,double mu){
    double expression = 0;
    for (int k : data){
        if (k == 0){
            expression += std::log(Poisson(mu, k));
        }
        else{
            expression += std::log(Poisson(mu, k));
            expression -= std::log(Poisson(k, k));
        }
    }
    return -2*expression;
}

int main(){
std::ifstream fin1("sums.txt");
std::vector<int> data;
int number;
while(fin1>>number){
    data.push_back(number);}
std::cout << prob(data, n_mean) << std::endl;

std::ofstream fout("likelihood.txt");
for (double mu = 0.0; mu <= 6.0; mu += 0.1){
    fout << mu << " " << prob(data, mu) << std::endl;
}

std:: ofstream fout2("nll.txt");
for (double mu = 0.0; mu <= 6.0; mu += 0.1){
    fout2 << mu << " " << nll(data, mu) << std::endl;
}

std::ofstream fout3("deltanll.txt");
for (double mu = 2.0; mu <= 4.0; mu += 0.001){
    if ((nll(data, mu-0.001) - nll(data, n_mean)-1)*(nll(data, mu) - nll(data, n_mean)-1)<0){
        std::cout << "mu: " << mu << std::endl;}
    fout3 << mu << " " << nll(data, mu) - nll(data, n_mean) << std::endl;
}
double mu_hat = 3.115;
std::cout << "intervall for delta mu<1" << ": " << 3.233-3.002 << std::endl;
std::cout << "sigma/sqrt(n): " << standard_deviation/std::sqrt(data.size()) << std::endl;
std::cout << std::sqrt(mu_hat/data.size()) << std::endl;

int n_dof = data.size() - 1;
double z = (lamda_times_minus_2(data, n_mean) - n_dof)/std::sqrt(2*n_dof);
std::cout << "z-score: " << z << std::endl;
}

