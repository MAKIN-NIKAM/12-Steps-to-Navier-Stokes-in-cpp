#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include<cmath>

using namespace std;
int main(){
    // Simulation Parameters
    int const nx = 101;
    int const ny = 101;
    int const nt = 80;
    double dx = 2.0/(nx-1);
    double dy = 2.0/(ny-1);
    int const c = 1;
    double const sigma = 0.2;
    double dt = sigma*dx;

    // Initialization

    vector<vector<double>> u(ny, vector<double>(nx,1.0));
    vector<vector<double>> un(ny, vector<double>(nx,1.0));
    vector<vector<double>> vn(ny, vector<double>(nx,1.0));
    vector<vector<double>> v(ny, vector<double>(nx,1.0));
    vector<vector<double>> s(ny, vector<double>(nx,1.0));

    int start = static_cast<int>(0.5/dx);
    int end = static_cast<int>(1.0/dx + 1);
    int startc = static_cast<int>(0.5/dy);
    int endc = static_cast<int>(1.0/dy + 1);

    for (int j = startc; j < endc; j++)
    {
       
        for (int i = start; i < end; i++)
        {
            u[i][j] = 2.0;
            v[i][j] = 2.0;
        }
    
    }    

    s = u;  // s = u or s = v 

    // Time Update
    
    for (int t = 0; t < nt; t++)
    {   
        un = u;
        vn = v;
        for (int j = 1; j < ny-1; j++)
        {
            for (int i = 1; i < nx-1; i++)
            {
               u[i][j] = un[i][j] - un[i][j]*(dt/dx)*(un[i][j] - un[i-1][j]) - vn[i][j]*(dt/dy)*(un[i][j] - un[i][j-1]);

               v[i][j] = vn[i][j]- un[i][j]*(dt/dx)*(vn[i][j] - vn[i-1][j]) - vn[i][j]*(dt/dy)*(vn[i][j] - vn[i][j-1]);
            }
            
        }
        
    }

    ofstream outfile("2D_non_linear_convection.csv");

    outfile<<scientific << setprecision(15);

    outfile<< "x,y,u,v,s \n";

    // Loop for writing the data

    for (int j = 0; j <ny; j++)
    {
        double y = j*dy;

        for (int i = 0; i < nx; i++)
         {
            double x = i*dx;
            outfile << x << ","<<y <<","
                    << u[i][j] <<","
                    << v[i][j]<<","
                    << s[i][j]<<"\n";

        }
        
    }

    outfile.close();

    return 0;
}