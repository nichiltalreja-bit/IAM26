#include <iostream>
#include <fstream>
#include <cmath>

int main()
{
double a;
double sum = 0.0;
double mean;
int n = 0;
std::ifstream fin("sums.txt");
std::ofstream fout1("means.txt");
while (fin >> a)
{
    sum += a;
    n++;
    if (n == 9)
    {
        mean = sum / n;
        fout1 << mean << std::endl;
        sum = 0.0;
        n = 0;
    }
}

std::ifstream fin2("sums.txt");
std::ifstream fin3("means.txt");
std::ofstream fout2("variances.txt");
sum = 0.0;
n = 0;
while (fin2 >> a)
{
    if (n == 0)
    {
        fin3 >> mean;
    }
    sum += (a - mean) * (a - mean);
    n++;
    if (n == 9)
    {
        double variance = sum / n;

        fout2 << variance << std::endl;

        sum = 0.0;
        n = 0;
    }
}

std::ifstream fin4("means.txt");
std::ifstream fin5("variances.txt");
double sum_of_means = 0.0;
double n_means = 0;
double sum_of_variances = 0.0;
double n_variances = 0;
while (fin4 >> a)
{
    sum_of_means += a;
    n_means += 1;
}
double mean_of_means = sum_of_means / n_means;
std::cout << "Mean of means = " << mean_of_means << std::endl;

while (fin5 >> a)
{
    sum_of_variances += a;
    n_variances += 1;
}
double mean_of_variances = sum_of_variances / n_variances;

std::ifstream fin6("variances.txt");
double sum_of_variances_for_bessel = 0.0;
double n_variances_for_bessel = 0;
while (fin6 >> a)
{
    double corrected_variance = a * 9.0 / 8.0;

    sum_of_variances_for_bessel += corrected_variance;
    n_variances_for_bessel++;
}

double bessel_correction =
    sum_of_variances_for_bessel / n_variances_for_bessel;

std::cout << "Bessel's correction = "
          << bessel_correction << std::endl;

std::ifstream fin7("means.txt");
double V = 0.0;
double counter = 0;
while(fin7>>a){
    V += (a-mean_of_means) * (a-mean_of_means);
    counter += 1;}
V /= counter;
double Standard_Deviation = sqrt(V);
std::cout << "Standard Deviation = " << Standard_Deviation << std::endl;
std::cout << "Standard Deviation = " << Standard_Deviation*3 << std::endl;
}
