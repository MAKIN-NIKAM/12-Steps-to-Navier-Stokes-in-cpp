#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;
int main(){
    
    // Simulation Parameters

    int const nx = 31;
    int const ny = 31;
    int const nt = 17;
    double nu = 0.05;
    double dx = 2.0/(nx-1);
    double dy = 2.0/(ny-1);
    double sigma = 0.25;
    double dt = (sigma*dx*dy)/(nu);

    // Initialization

    vector<vector<double>> u(ny, vector<double>(nx, 1.0));  // Final Wave
    vector<vector<double>> un(ny, vector<double>(nx, 1.0)); // Utilized to calculate u in the time step update loop
    vector<vector<double>> s(ny, vector<double>(nx, 1.0));  // Original Wave

    int start = static_cast<int> (0.5/dx);
    int end = static_cast<int>(1.0/dx + 1);
    int startc = static_cast<int>(0.5/dy);
    int endc = static_cast<int>(1.0/dy + 1);

    // Initial condition
    for (int j = startc; j < endc; j++)
    {
        for (int i = start; i < end; i++)
        {
            u[j][i] = 2.0;
        } 
        
    }
    s = u;
    
    // Time step update

    for (int t = 0; t < nt; t++)
    {   un = u;
        for (int j = 1; j < ny-1; j++)
        {   
            for (int i = 1; i < nx-1; i++)
            {
                u[j][i] = un[j][i] + nu*(dt/(dx*dx))*(un[j][i+1] - 2*un[j][i] + un[j][i-1]) + nu*(dt/(dy*dy))*(un[j+1][i] -2*un[j][i] + un[j-1][i]);    
            }
            
        }
        
    }
    
    ofstream outfile("2D_Diffusion.csv");

    outfile<<scientific << setprecision(15);

    outfile<<"x,y,u,s \n";

    // Loop for writing outfile

    for (int j = 0; j < ny; j++)
    {
        double y = j*dy;
        for (int i = 0; i < nx; i++)
        {
            double x = i*dx;
            outfile << x << ","
                    << y << ","
                    << u[j][i] << ","
                    << s[j][i] <<"\n";
        }
        
    }

    outfile.close();

    return 0;
}