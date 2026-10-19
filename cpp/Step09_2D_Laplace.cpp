#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<fstream>
using namespace std;


void Laplace2D(vector<vector<double>>& p,vector<vector<double>>& pn, int nx,int ny, double dx,double dy,double l1target){

    double l1error = 1.0;
    while (l1error > l1target){
        
        pn  = p;
        // Updating the grid for Discretized Laplace Equation
        for (int j = 1; j < ny-1; j++)
        {   

            for (int i = 1; i < nx-1; i++)
            {
                p[j][i] = ((dy*dy)*(pn[j][i+1] + pn[j][i-1]) + (dx*dx)*(pn[j+1][i] + pn[j-1][i]))/(2*((dx*dx) + (dy*dy)));
            }
            
        }

        // Defining Boundary Conditions
        for (int i = 0; i < nx; i++)
        {   
            p[ny-1][i]= p[ny-2][i];
            p[0][i] = p[1][i];
        }    
        
        for (int j = 0; j < ny; j++)
        {   
            double y = j*dy;
            p[j][0] = 0.0;
            p[j][nx-1] = y;
        }
        
        // Calculating the L1 error
        double l1norm = 0.0;
        l1error = 0.0;
        for (int j = 0; j < ny; j++)
        {
            for (int i = 0; i < nx; i++)
            {
                l1error += abs(p[j][i] - pn[j][i]);
                l1norm += abs(pn[j][i]);
            }
       
        }
        l1error = l1error/l1norm;

    }

}

int main(){
    
    // Defining Simulation Parameters

    int const nx = 31;
    int const ny = 31;
    double dx = 2.0/(nx-1);
    double dy = 1.0/(ny-1);
    double l1target = 1e-4;

    // Initialization

    vector<vector<double>> p(ny, vector<double>(nx,0.0));
    vector<vector<double>> pn(ny, vector<double>(nx,0.0));
    vector<vector<double>> po(ny, vector<double>(nx,0.0));

    // Defining Boundary Conditions
        for (int i = 0; i < nx; i++)
        {   
            p[ny-1][i]= p[ny-2][i];
            p[0][i] = p[1][i];
        }    
        
        for (int j = 0; j < ny; j++)
        {   
            double y = j*dy;
            p[j][0] = 0.0;
            p[j][nx-1] = y;
        }
    po = p;

    // Calling the Laplace function
    Laplace2D(p,pn,nx,ny,dx,dy,l1target);

    // For writing data

    ofstream outfile("2D_Laplace_1.csv");

    outfile<<scientific << setprecision(15);

    outfile<<"x,y,p,po \n";

    // Loop for writing outfile

    for (int j = 0; j < ny; j++)
    {
        double y = j*dy;
        for (int i = 0; i < nx; i++)
        {
            double x = i*dx;
            outfile << x << ","
                    << y << ","
                    << p[j][i]<< ","<<po[j][i]
                    <<"\n";
        }
        
    }

    outfile.close();
    
    return 0;
}