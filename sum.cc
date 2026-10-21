#include <iostream>
#include <fstream>

int main()
{
std :: ifstream fin ("data.txt");
float a;
float b;
std :: ofstream fout ("sums.txt");

while(fin >> a >> b){
    fout << a+b << std :: endl;
}
fout.close();
}