### Step02: 1D Non-Linear Convection

For 1D non-linear convection same methods are used as in Step01, the equation is represented as:

$$\frac{\partial u}{\partial t}+u\frac{\partial u}{\partial x} = 0$$
The solution u is multiplied by the spatial derivative in place of constant c as in Step01.

Solving for the unknown term $u_i^{n+1}$, gives:
$$u_i^{n+1} = u_i^{n}-u_i^{n}\frac{\Delta t}{\Delta x}(u_i^n - u_{i-1}^n)$$

The code to solve the above discretized equation is : https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/blob/main/cpp/Step02_1D_non_linear_convection.cpp

The initial condition is same as Step01 (i.e. the hat function)

The Plot for the initial and final wave can be seen here: https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/blob/main/Plots/1D%20Non_linear%20convection/1D%20Non%20Linear%20Convection.jpg

The plot shows that the initial wave is moved to the right and the shape of the wave changes because the wave speed is "u", which varies for different parts of the wave.