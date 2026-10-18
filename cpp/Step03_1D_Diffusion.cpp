#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;
int main(){
    // Simulation Parameters
    const int nx = 41;
    const int nt = 25;
    const double x_max = 2.0; 
    const double x_min = 0;
    const double dx = ( x_max - x_min ) / (nx - 1);
    const double sigma = 0.2;
    const double nu = 0.3;
    const double dt = sigma*((dx*dx)/nu);

    // Initialization

    vector<double> u(nx, 1.0);
    vector<double> s(nx, 1.0);
    vector<double> un(nx, 1.0);

    
    int start = static_cast<int> (0.5/dx);
    int end = static_cast<int> (1/dx + 1);

    for (int i = start; i < end; i++)
    {
        /* code */
        u[i] = 2.0;

    }

    s = u;

    // Time step update

    for (int t = 1; t < (nt + 1); t++)
    {   
        un = u;
        /* code */
        for (int i = 1; i < (nx - 1); i++)
        {
            /* code */
            u[i] = un[i] + (nu*dt)/(dx*dx)*(un[i+1] -2*un[i] + un[i-1]);
        }
        

    }
    
    // cout<<"Final u(x,t) distribution: "<<endl;
    // for (int i = 0; i < nx; i++)
    // {
    //     double x = i * dx;
    //     cout << left 
    //          << setw(15) << x 
    //          << setw(15) << u[i] << endl;
    // }

ofstream outfile ("DIFFUSION.csv");

outfile << scientific << setprecision(15);

outfile << "x,u,s \n";

for (int i = 0; i < nx; i++)
{
    /* code */
    double x = i*dx;
    outfile << x <<","
            <<u[i]<< ","
            <<s[i]<<"\n";

}

outfile.close();

    return 0;  
} 


