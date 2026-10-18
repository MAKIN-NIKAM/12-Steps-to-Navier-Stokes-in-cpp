#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<fstream>

#define M_PI 3.14159265358979323846

using namespace std;
int main(){
    
    // Simulation Parameters
    const int nx = 101;
    const int nt = 100;
    const double x_max = 2.0*M_PI; 
    const double x_min = 0;
    const double dx = ( x_max - x_min ) / (nx - 1);
    const double sigma = 0.2;
    const double nu = 0.3;
    const double dt = sigma*((dx*dx)/nu);

// Defining x-coordinate

    vector<double> x(nx);
    for (int i = 0; i < nx; i++)
    {
        /* code */
        x[i] = i*dx;   
    }

// Initialization    
    vector<double> u(nx);
    vector<double> un(nx);
    vector<double> s(nx);
    double t = 0.0;
    for (int i = 0; i < nx; i++)
    {
        /* code */

        double xi = x[i];
        double phi = exp(-((xi-4*t)*(xi-4*t))/(4*nu*(t+1))) + exp(-((xi-4*t-2*M_PI)*(xi-4*t-2*M_PI))/(4*nu*(t+1)));

        double dphi = (-(xi-4*t)/(2*nu*(t+1)))*exp(-((xi-4*t)*(xi-4*t))/(4*nu*(t+1))) + (-(xi-4*t-2*M_PI)/(2*nu*(t+1)))*exp(-((xi-4*t-2*M_PI)*(xi-4*t-2*M_PI))/(4*nu*(t+1)));

        u[i] = -2*nu*(dphi/phi) + 4;
    }
    
    s = u;
   
//Time Stepping

    for (int n = 0; n < nt ; n++)
    {
        /* code */
        // For updating the grid
        un = u;
        for (int i = 1; i < nx - 1; i++)
        {
            /* code */
            u[i] = un[i] - un[i]*(dt/dx)*(un[i] - un[i-1]) + (nu*dt/(dx*dx)) * (un[i+1] -2*un[i] + un[i-1]);
        }
    
    // Boundary Condition
        u[0] = un[0] -un[0]*(dt/dx)*(un[0] - un[nx-2]) + nu*(dt/(dx*dx))*(un[1] -2*un[0] + un[nx -2]);

        u[nx-1] = u[0];
        
    }
    
    // cout<<"Final u(x,t) distribution: "<<endl;
    // for (int i = 0; i < nx; i++)
    // {
    //     double x = i * dx;
    //     cout << left 
    //          << setw(15) << x 
    //          << setw(15) << u[i] << endl;
    // }

    // cout<<"Final u(x,t) distribution: "<<endl;
    // for (int i = 0; i < nx; i++)
    // {
    //     double x = i * dx;
    //     cout << left 
    //          << setw(15) << x 
    //          << setw(15) << s[i] << endl;
    // }

    ofstream outfile("Burgers.csv");

    outfile<< scientific << setprecision(15);  // This sets the values to scientific notations and upto a 15 point precision after the decimal
    outfile << "x,u,s \n";
    for (int i = 0; i < nx; i++) {
        outfile << x[i] << ","
                << u[i] << ","
                << s[i] << "\n";
    }
    outfile.close();




    
    return 0;
}