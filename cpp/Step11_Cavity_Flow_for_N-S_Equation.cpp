#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<fstream>
using namespace std;


void build_up(vector<vector<double>>& u, vector<vector<double>>& v,vector<vector<double>>& b, double dx, double dy, double dt, int nx, int ny){

    for (int j = 1; j < ny-1; j++)
    {
        for (int i = 1; i < nx-1; i++)
        {
            b[j][i] = (1.0/dt)*((u[j][i+1] - u[j][i-1])/(2*dx) + (v[j+1][i] - v[j-1][i])/(2*dy)) - ((u[j][i+1] - u[j][i-1])/(2*dx))*((u[j][i+1] - u[j][i-1])/(2*dx)) - 2*(((u[j+1][i] - u[j-1][i])/(2*dy))*((v[j][i+1] - v[j][i-1])/(2*dx))) - ((v[j+1][i] - v[j-1][i])/(2*dy))*((v[j+1][i] - v[j-1][i])/(2*dy));
        }
        
    }

}

void ppe(vector<vector<double>>& p, vector<vector<double>>& pn,vector<vector<double>>& b, double dx2, double dy2, int nx, int ny){

    for (int t = 0; t < 50; t++)     // Pseudo time loop
    {   

        pn = p;

        for (int j = 1; j < ny-1; j++)
        {   
            
            for (int i = 1; i < nx-1; i++)
            {   

                // Discretized Pressure poisson equation
                p[j][i] = ((dy2)*(pn[j][i+1] + pn[j][i-1]) + (dx2)*(pn[j+1][i] + pn[j-1][i]))/(2*(dx2 + dy2)) - (b[j][i])*((dx2*dy2)/(2*(dx2 + dy2)));
                

                // Boundary Conditions for Pressure poisson equation
                p[0][i] =  p[1][i];
                p[ny-1][i] = 0.0;
                p[j][0] = p[j][1];
                p[j][nx-1] = p[j][nx-2];
            }
            
            
        }
    }
    
}

void cavity_flow(vector<vector<double>>& u, vector<vector<double>>& un, vector<vector<double>>& v, vector<vector<double>>& vn,vector<vector<double>>& p,vector<vector<double>>& pn,vector<vector<double>>& b, double dx, double dy,double dx2, double dy2, double dt, double rho, double nu, int nx, int ny,int nt){

    for (int t = 0; t < nt; t++)    // Time loop
    {   
        un = u;
        vn = v;
        
        build_up( u, v, b,dx,dy,dt,nx,ny);
        ppe(p,pn,b,dx2,dy2,nx,ny);

        for (int j = 1; j < ny-1; j++)
        {
            for (int i = 1; i < nx-1; i++)
            {
                

                u[j][i] = un[j][i] - un[j][i]*(dt/dx)*(un[j][i] - un[j][i-1]) - vn[j][i]*(dt/dy)*(un[j][i] - un[j-1][i]) - (dt/(rho*2*dx))*(p[j][i+1] - p[j][i-1]) + (nu)*((dt/dx2)*(un[j][i+1] -2*un[j][i] + un[j][i-1]) + (dt/dy2)*(un[j+1][i] - 2*un[j][i] + un[j-1][i]));
            
                v[j][i] = vn[j][i] -un[j][i]*(dt/dx)*(vn[j][i] - vn[j][i-1]) - vn[j][i]*(dt/dy)*(vn[j][i] - vn[j-1][i]) - (dt/(rho*2*dy))*(p[j+1][i] - p[j-1][i]) + (nu)*((dt/dx2)*(vn[j][i+1] -2*vn[j][i] + vn[j][i-1]) + (dt/dy2)*(vn[j+1][i] -2*vn[j][i] + vn[j-1][i]));

            
            }
        
        }
    
        // Boundary Conditions
        for (int i = 0; i < nx; i++) {
            u[0][i]    = 0.0;
            u[ny-1][i] = 1.0;  // lid!
            v[0][i]    = 0.0;
            v[ny-1][i] = 0.0;
        }
        for (int j = 0; j < ny; j++) {
            u[j][0]    = 0.0;
            u[j][nx-1] = 0.0;
            v[j][0]    = 0.0;
            v[j][nx-1] = 0.0;
        }
    }

}



int main(){

    // Defining Simulation Parameters

    int const nx = 41;
    int const ny = 41;
    double dx = 2.0/(nx-1);
    double dy = 2.0/(ny-1);
    double dx2 = dx*dx;
    double dy2 = dy*dy;
    int const nt = 500;
    double const pnt = 50;
    double const dt = 0.001;
    double const rho = 1.0;
    double const nu = 0.1;

    // Initialization

    vector<vector<double>> u(ny, vector<double> (nx,0.0));
    vector<vector<double>> v(ny, vector<double> (nx,0.0));
    vector<vector<double>> un(ny, vector<double> (nx,0.0));
    vector<vector<double>> vn(ny, vector<double> (nx,0.0));
    vector<vector<double>> p(ny, vector<double> (nx,0.0));
    vector<vector<double>> pn(ny, vector<double> (nx,0.0));
    vector<vector<double>> b(ny, vector<double> (nx,0.0));

    // Calling the cavity flow function

    cavity_flow(u,un,v,vn,p,pn,b,dx,dy,dx2,dy2,dt,rho,nu,nx,ny,nt);

    cout << "p[1][1]   = " << p[1][1]   << endl;
    cout << "u[ny-1][20] = " << u[ny-1][20] << endl;  // lid should be 1.0
    cout << "b[20][20] = " << b[20][20] << endl;

    // For writing data

    ofstream outfile("Cavity_Flow.csv");

    outfile<<scientific << setprecision(15);

    outfile<<"x,y,u,v,p \n";

    // Loop for writing outfile

    for (int j = 0; j < ny; j++)
    {
        double y = j*dy;
        for (int i = 0; i < nx; i++)
        {
            double x = i*dx;
            outfile << x << ","
                    << y << ","
                    << u[j][i]<< ","<<v[j][i]<<","
                    <<p[j][i]
                    <<"\n";
        }
        
    }

    outfile.close();

    return 0;
}