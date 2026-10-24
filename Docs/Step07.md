### Step 07: 2D Diffusion

The 2D diffusion equation is given by:
$$\frac{\partial u}{\partial t} = \nu\frac{\partial^2 u}{\partial x^2}+\nu\frac{\partial^2 u}{\partial y^2}$$

The above equation is discretized similarly as the 1D diffusion equation as:

$$\frac{u_{i,j}^{n+1} - u_{i,j}^{n}}{\Delta t} = \nu \frac{u_{i+1,j}^{n} - 2u_{i,j}^{n} + u_{i-1,j}^{n}}{\Delta x^2} + \nu \frac{u_{i,j+1}^{n} - 2u_{i,j}^{n} + u_{i,j-1}^{n}}{\Delta y^2}$$

After reorganizing the equation for the unknown we get:
$$u_{i,j}^{n+1} = u_{i,j}^{n} + \frac{\nu \Delta t}{\Delta x^2} (u_{i+1,j}^{n} - 2u_{i,j}^{n} + u_{i-1,j}^{n})+ \frac{\nu \Delta t}{\Delta y^2} (u_{i,j+1}^{n} - 2u_{i,j}^{n} + u_{i,j-1}^{n})$$

The initial and boundary conditions are same as step06.

The CFL condition used iin this step is:
$\sigma=\nu \frac {\Delta t}{\Delta x^2}=0.25$, ($\Delta x = \Delta y$)

The C++ code to solve the pde is : https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/blob/main/cpp/Step07_2D_Diffusion.cpp

The plots are shown here for u(x,y): https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/tree/main/Plots/2D%20diffusion

From the plots its visible that the 2D wave diffuses similarly as the 1D wave in space.