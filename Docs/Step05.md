### Step 05: 2D Linear Convection

2D Linear Convection consists of 2 coupled partial differential equations: 

$$\frac{\partial u}{\partial t} + c\frac{\partial u}{\partial x} + c\frac{\partial u}{\partial y} = 0$$


We discretize the above equation using forward difference for time and backward difference for space. Therefor the discretized equation looks like:
$$\frac {u_{i,j}^{n+1} -u_{i,j}^{n}}{\Delta t} + c\frac{u_{i,j}^n - u_{i-1,j}^n}{\Delta x} +c\frac{u_{i,j}^n -u_{i,j-1}^n}{\Delta y} = 0$$

Therefore, solving for the unknown we get:
$$u_{i,j}^{n+1} = u_{i,j}^n -c\frac{\Delta t}{\Delta x}(u_{i,j}^{n}-u_{i-1,j}^{n}) -c\frac{\Delta t}{\Delta y}(u_{i,j}^{n}-u_{i,j-1}^{n})$$

The initial condition at t = 0 is u = 2 for $0.5\le x,y \le 1$ and u = 1 everywhere else, and boundary condition u = 1 for x = 0, 2 and y = 0, 2.

The CFL condition for this case is:

 $\sigma= c_x\frac{\Delta t}{\Delta x} + c_y\frac{\Delta t}{\Delta y}$

Since, in our case $c_x = c_y =c$ and $\Delta x = \Delta y$ (mentioned in C++ code) we get:

$\sigma = 2c\frac{\Delta t}{\Delta x} \le 1$.
 So, $\Delta t = 0.5\frac{\Delta x}{c}$, in our case we specify ${\Delta t} = 0.2*\Delta x$, since c = 1.

 The C++ code for solving above discretized equation is:
 https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/blob/main/cpp/Step05_2D_Linear_Convection.cpp

 The initial and final plots are depicted here: https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/tree/main/Plots/2D%20linear

From the plots it could be seen that the wave gets convected and its shape changes due to numerical diffusion and truncation errors in the discretization schemes. 