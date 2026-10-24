### Step06: 2D Non-Linear Convection

The 2D Non-Linear Convection is represented by parir of coupled partial differential equations given as:

$$\frac{\partial u}{\partial t} + u\frac{\partial u}{\partial x}+v\frac{\partial u}{\partial y} = 0 $$
$$\frac{\partial u}{\partial t} +u\frac{\partial v}{\partial x} +v\frac{\partial v}{\partial y}=0$$

The above equations are discretized using the methods described in previous steps as:

$$\frac{u_{i,j}^{n+1} - u_{i,j}^{n}}{\Delta t}
+ u_{i,j}^{n} \frac{u_{i,j}^{n} - u_{i-1,j}^{n}}{\Delta x}
+ v_{i,j}^{n} \frac{u_{i,j}^{n} - u_{i,j-1}^{n}}{\Delta y} = 0$$

$$\frac{v_{i,j}^{n+1} - v_{i,j}^{n}}{\Delta t}
+ u_{i,j}^{n} \frac{v_{i,j}^{n} - v_{i-1,j}^{n}}{\Delta x}
+ v_{i,j}^{n} \frac{v_{i,j}^{n} - v_{i,j-1}^{n}}{\Delta y}= 0$$

The initial condition used is u =2, v = 2 for $0.5 \le x,y\le 1$ and u, v = 1 everywhere else.

The boundary conditions used are:
u=1, v = 1 for x = 0, 2 ; y = 0, 2

The CFL condtion used is: $\sigma = 0.2*dt$ (Note on CFL Condition: In this step, dt is kept constant (0.2 * dx) to match the Python tutorial. While this remains stable for the provided initial conditions (resulting in a maximum local Courant number of 0.8), a true non-linear solver would require dynamically updating dt at each time step based on the changing velocity fields to guarantee absolute stability.)

The C++ code for solving above PDE is: https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/blob/main/cpp/Step06_2D_Non_Linear_Convection.cpp

The Plots are shown here: https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/tree/main/Plots/2D%20Non%20linear

The plots are similar to 1D non linear plot, the 2D wave is skewed in space as different parts of the wave move with different wave speed which also varies in space and time.