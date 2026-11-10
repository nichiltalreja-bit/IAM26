#include <iostream>
#include <fstream>
#include <cmath>

int main()
{
std :: ifstream fin("sums.txt");
double a;
double sum = 0.0;
int n = 0;
while(fin >> a){
    n++;
    sum += a;
}
double average = sum / n;
std :: cout << "Average = " << average << std :: endl;

double Variance = 0.0
;
std :: ifstream fin2("sums.txt");
while(fin2>>a){
    Variance += (a-average) * (a-average);
}
Variance /= n;
std :: cout << "Variance = " << Variance << std :: endl;

double Standard_Deviation = sqrt(Variance);
std :: cout << "Standard Deviation = " << Standard_Deviation << std :: endl;

}