#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
#include<fstream>
using namespace std;
int main(){
    
    // Defining Simulation Parameters and constants

    int const nx = 81;
    int const ny = 81;
    int const nt = 100;
    int const c = 1;
    double dx = 2.0/(nx-1);
    double dy = 2.0/(ny-1);
    double sigma = 0.2;
    double dt = sigma*dx;

    // Initialization
    double x , y;

    vector<vector<double>> u(ny,vector<double>(nx,1.0));
    vector<vector<double>> un(ny,vector<double>(nx,1.0));
    vector<vector<double>> s(ny,vector<double>(nx,1.0));
    
    int start = static_cast <int> (0.5/dx);
    int end = static_cast <int> (1/dx + 1);
    int startc = static_cast <int> (0.5/dy);
    int endc = static_cast <int> (1/dy + 1);

    for (int j = startc; j < endc; j++)
    {
        for (int i = start; i < end; i++)
        {
            u[i][j] = 2.0;
        }
    
    }    

    s=u;
    // Time update

    for (int t = 0; t < nt; t++)
    {   
        // Grid update
        un = u;
        for (int i = 1; i < nx-1; i++)
        {
            for (int j = 1; j < ny-1; j++)
            {
                u[i][j] = un[i][j] - (c*(dt/dx))*(un[i][j] - un[i-1][j]) - (c*(dt/dy))*(un[i][j] - un[i][j-1]);
            }
            
        }
        

    }
    
    ofstream outfile("2D_linear_convection.csv");

    outfile<<scientific << setprecision(15);

    outfile<< "x,y,u,s \n";

    // Loop for writing the data


    for (int j = 0; j < ny; j++)
    {        
        double y = j*dy;
        for (int i = 0; i < nx; i++)
        {   
            double x = i*dx;
            
            outfile << x << "," << y << "," 
                    << u[i][j]
                    << "," << s[i][j] << "\n";
        }
    
    }
    
    outfile.close();

    return 0;
}