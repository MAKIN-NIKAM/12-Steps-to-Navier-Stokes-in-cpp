### Step03: 1D Diffusion Equation

The 1D diffusion equation is represented as:
$$\frac{\partial u}{\partial t} = \nu \frac{\partial^2 u}{\partial x^2}$$

To discretize the above equation we use forward differnce for time derivative and central difference scheme for second order spatial derivative. Therefore, we get:

$$\frac{u_i^{n+1}-u_i^n}{\Delta t} = \nu\frac{u_{i+1}^n -2u_i^n +u_{i-1}^n}{\Delta x^2}$$

So, after re-arranging the terms to solve for our unknown we get:

$$u_i^{n+1} = u_i^n + \frac{\nu \Delta t}{\Delta x^2}(u_{i+1}^n -2u_i^n +u_{i-1}^n)$$

The same initial condition of hat function is used at t = 0, u = 2 for $0.5\le x \le 1$ and u = 1 everywhere else.

For this case the CFL No is given as:
$$\sigma = \frac{\nu\Delta t}{\Delta x^2} $$ 
We take $\sigma = 0.2$.

The C++ code which solves the equation is: https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/blob/main/cpp/Step03_1D_Diffusion.cpp 

The plot for the results: https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/blob/main/Plots/1D%20Diffusion/1D_Diffusion%20plot.jpg

The plots show the diffused wave at steady state.The maximum value of the diffused wave is less than 2, and is smooth as compared to the initial wave, due to spreading out of wave in space over time.
