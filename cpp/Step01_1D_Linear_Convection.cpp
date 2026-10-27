#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;
int main(){
    
    // Defining Simulation Parameters

    const double x_max = 2.0;
    const double x_min = 0;
    const int nx = 41;
    const int nt = 25;                             // No of grid points
    const double c = 1.0;
    const double dx =  (x_max - x_min) / (nx - 1);  // Grid Spacing
    const double dt = 0.025;

    // cout<<(c * dt)/dx;


    // Initialization:

    vector<double> u(nx,1.0);
    vector<double> s(nx,1.0);
    
    int start = static_cast<int>(0.5/dx);
    int end = static_cast<int>(1/dx + 1);

    for (int i = start; i < end ; i++)
    {
        /* code */
        u[i] = 2.0;

    }

    s = u;   // whatever u is s takes that value

    // Time Stepping:

    vector<double> un(nx,1.0);
     
    cout<<u[start]<<endl;

    for (int t = 0; t < nt; t++)
    {
        /* code */
        un = u;
    
        
        for (int i = 1; i < nx; i++)
        {
            /* code */

            u[i] = un[i] - ((c*dt) / dx) * (un[i] - un[i-1]);

        }
    }
    // For writing the data for Post-processing

ofstream outfile("1D_LINEAR.csv");

// Set  precision for floating-point numbers
outfile << scientific << setprecision(15); 

// 2. Write header (using "\n" instead of endl)
outfile << "x,u, s\n";  

for (int i = 0; i < nx; i++) {
    double x = i * dx;
    outfile << x << "," 
            << u[i]
            << "," << s[i] << "\n"; 
}

outfile.close();

    return 0;
}