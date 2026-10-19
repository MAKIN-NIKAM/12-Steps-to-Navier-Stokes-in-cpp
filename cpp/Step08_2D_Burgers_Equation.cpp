#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<fstream>
using namespace std;
int main(){
    // Simulation Parameters

    int const nx = 41;
    int const ny = 41;
    int const nt = 120;
    int const c = 1;
    double dx = 2.0/(nx-1);
    double dy = 2.0/(ny-1);
    double const sigma = 0.0009;
    double const nu = 0.01;
    double dt = sigma*dx*dy / nu;

    // Initialization

    vector<vector<double>> u(ny, vector<double>(nx, 1.0));
    vector<vector<double>> v(ny, vector<double>(nx, 1.0));
    vector<vector<double>> un(ny, vector<double>(nx, 1.0));
    vector<vector<double>> vn(ny, vector<double>(nx, 1.0));
    vector<vector<double>> s(ny, vector<double>(nx, 1.0));

    int start = static_cast<int>(0.5/dx);
    int end = static_cast<int>(1.0/dx + 1);
    int startc = static_cast<int>(0.5/dy);
    int endc = static_cast<int>(1.0/dy + 1);

    for (int j = startc; j < endc; j++)
    {
        for (int i = start; i < end; i++)
        {
            u[j][i] = 2.0;
            v[j][i] = 2.0;
        }
        
    }
    
    s = u;
    // Time step update
    for (int t = 0; t < nt; t++)
    {   
        // Grid update
        un = u;
        vn = v;
        for (int j = 1; j < ny-1; j++)
        {
            for (int i = 1; i < nx-1; i++)
            {
                u[j][i] = un[j][i] - (dt/(dx))*un[j][i]*(un[j][i] - un[j][i-1]) - (dt/dy)*vn[j][i]*(un[j][i] - un[j-1][i]) + ((nu*dt)/(dx*dx))*(un[j][i+1] - 2*un[j][i] + un[j][i-1]) + ((nu*dt)/(dy*dy))*(un[j+1][i] -2*un[j][i] + un[j-1][i]);

                v[j][i] = vn[j][i] -(dt/dx)*un[j][i]*(vn[j][i] - vn[j][i-1]) - (dt/dy)*vn[j][i]*(vn[j][i] - vn[j-1][i]) + ((nu*dt)/(dx*dx))*(vn[j][i+1] -2*vn[j][i] + vn[j][i-1]) + ((nu*dt)/(dy*dy))*(vn[j+1][i] -2*vn[j][i] + vn[j-1][i]);
            }
            
        }
        
    }
    
    ofstream outfile("2D_burgers_equation.csv");

    outfile<<scientific << setprecision(15);
    
    outfile<< "x,y,u,v,s \n";

    // For writing output file

    for (int j = 0; j < ny; j++)
    {
        double y = j*dy;
        for (int i = 0; i < nx; i++)
        {
            double x = i*dx;
            outfile << x << ","
                    << y << ","
                    << u[j][i] << ","
                    << v[j][i] << ","
                    << s[j][i] << "\n";
        }
        
    }
    
    outfile.close();

    return 0;
}