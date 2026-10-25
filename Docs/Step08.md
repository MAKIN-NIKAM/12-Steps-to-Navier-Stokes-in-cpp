### Step 08: 2D Burger's Equation

The 2D Burger's equation is the combination of 2D Non-linear and 2D Diffusion equation and is given by:

$$\frac{\partial u}{\partial t} + u\frac{\partial u}{\partial x}+v\frac{\partial u}{\partial y} = \nu(\frac{\partial^2 u}{\partial x^2} + \frac{\partial^2 u}{\partial y^2})$$

$$\frac{\partial v}{\partial t} + u\frac{\partial v}{\partial x}+v\frac{\partial v}{\partial y} = \nu(\frac{\partial^2 v}{\partial x^2} + \frac{\partial^2 v}{\partial y^2})$$

The discretization of above equations invovle schemes implemented in previous steps. After discretization we get:

$$u_{i,j}^{n+1} = u_{i,j}^n - \frac{\Delta t}{\Delta x} u_{i,j}^n (u_{i,j}^n - u_{i-1,j}^n) - \frac{\Delta t}{\Delta y} v_{i,j}^n (u_{i,j}^n - u_{i,j-1}^n) + \frac{\nu \Delta t}{\Delta x^2}(u_{i+1,j}^n - 2u_{i,j}^n + u_{i-1,j}^n) + \frac{\nu \Delta t}{\Delta y^2}(u_{i,j+1}^n - 2u_{i,j}^n + u_{i,j-1}^n)$$

$$v_{i,j}^{n+1} =  v_{i,j}^n - \frac{\Delta t}{\Delta x} u_{i,j}^n (v_{i,j}^n - v_{i-1,j}^n) - \frac{\Delta t}{\Delta y} v_{i,j}^n (v_{i,j}^n - v_{i,j-1}^n)+ \frac{\nu \Delta t}{\Delta x^2} (v_{i+1,j}^n - 2v_{i,j}^n + v_{i-1,j}^n) + \frac{\nu \Delta t}{\Delta y^2} (v_{i,j+1}^n - 2v_{i,j}^n + v_{i,j-1}^n)$$

For this case we follow the CFL No value ($\sigma$):
$\sigma = 0.0009$

The initial and boundary conditions are same as previous steps.

C++ code which solves the discretized equation is: https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/blob/main/cpp/Step08_2D_Burgers_Equation.cpp

The Plots for initial and final wave are given here: https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/tree/main/Plots/2D%20burgers

The plot is similar as the 1D Burgers plot but is in two dimensions with the wave being skewed and diffused in space at steady state.

