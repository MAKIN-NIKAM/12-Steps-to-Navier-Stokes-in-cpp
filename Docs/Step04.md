### Step 04: 1D Burgers Equation

The 1D Burger's Equation is a combination of 1D non-linear convection and diffusion equation. It is represented as:

$$\frac{\partial u}{\partial t} + u\frac{\partial u}{\partial x} = \nu\frac{\partial^2 u}{\partial x^2}$$

We discretize the above equation using Forward difference for time, backward difference for space and 2nd order method for second derivatives. Therefore, we solve for our unknow as:

$$u_i^{n+1} = u_i^{n} - u_i^{n}\frac{\Delta t}{\Delta x}(u_i^n -u_{i-1}^n) +\nu\frac{\Delta t}{\Delta x^2}(u_{i+1}^n -2u_{i}^n +u_{i-1}^n)$$

The initial condition is a saw tooth function as explained in CFD Python course by Prof. Lorena Barbara.

For this case the CFL No is given as:
$$\sigma = \frac{\nu\Delta t}{\Delta x^2} $$ 
We take $\sigma = 0.2$.

The C++ code which solves the equation is: https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/blob/main/cpp/Step04_1D_Burgers_Equation.cpp

The plots are represented here (made in Veusz): https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/blob/main/Plots/1D%20Burgers%20Equation/1D_Burgers_Equation.jpg

From the plot it can be seen that the final wave convects to the right as well as diffuses in space.


