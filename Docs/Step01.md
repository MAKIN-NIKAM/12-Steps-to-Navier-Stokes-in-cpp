### Step01: 1D Linear Convection

1D Linear Convection equation describes the motion of the wave moving with speed c in space and time.

$$\frac{\partial u}{\partial t} + c\,\frac{\partial u}{\partial x} = 0$$

The above equation is discretized in space and time, using the Forward Difference scheme for time derivative, and the Backward Difference scheme for the spatial derivative. We consider the discretization of x-coordinate into points with index from i = 0 to N, and for the time domain we divide into discrete time intervals of size $\Delta$t.

So, using the difference schemes for space and time we get:

$$\frac{u_i^{n+1}-u_i^n}{\Delta t} + c\,\frac{u_i^n-u_{i-1}^n}{\Delta x} = 0$$

By isolating all the known and unknown terms we get:

$$u_i^{n+1} = u_i^n-c\,\frac{\Delta t}{\Delta x}(u_i^n-u_{i-1}^n)$$

The above discretized equation is solved in [Step01 code] https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/blob/main/cpp/Step01_1D_Linear_Convection.cpp

The initial conditions involve u = 2 in the interval $0.5 \le u \le 1$ and u = 1 everywhere else.

The Plot for the initial and the final wave can be seen here: https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/blob/main/Plots/1D%20Linear%20Convection/1D%20Linear%20Convection.jpg

From the plot it can be seen that the wave has moved to the right, however the shape of the initial hat function changes due to the numerical diffusion and truncation errors. Moreover, the CFL no ($c \frac{\Delta t}{\Delta x}$) is 0.5 which signifies that the wave travels distance less than $\Delta x$ in $\Delta t$ time with speed c.  