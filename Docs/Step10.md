### Step 10: 2D Poisson Equation

The motivation behind solving the Poisson is that it allows deriving a pressure field which satisfies the continuity equation and the process involves taking divergence of the mometum equation which gives rise to the Poisson Equaiton for pressure.

Poisson's Equation is obtained by adding the source term to ther right side of Laplace's Equation:

$$\frac{\partial^2 p}{\partial x^2}+\frac{\partial^2 p}{\partial x^2} = b$$

After discretization we get:

$$\frac{p_{i+1,j}^n - 2p_{i,j}^n + p_{i-1,j}^n}{\Delta x^2} + \frac{p_{i,j+1}^n - 2p_{i,j}^n + p_{i,j-1}^n}{\Delta y^2} = b_{i,j}^n$$

$$p_{i,j}^n = \frac{\Delta y^2(p_{i+1,j}^n + p_{i-1,j}^n) + \Delta x^2(p_{i,j+1}^n + p_{i,j-1}^n)-b_{i,j}^n\Delta x^2 \Delta y^2}{2(\Delta x^2 + \Delta y^2)}$$

We take the initial state of 
$p = 0$ at $x = 0, 2$ and $y = 0, 1$ 

The source term consists of two initial spikes in the domain:

$b_{i,j} = 100$ at $i = \frac {1}{4}nx, j = \frac{1}{4}ny$

$b_{i,j} = -100$ at $i = \frac{3}{4}nx, j = \frac{3}{4}ny$

Similar to the 2D Laplace solution we iterate the discretized equation until the relative L1 error is smaller than the target.(In CFD python course they used pseudo time stepping to iterate for the intial pressure field. )

The C++ code is: https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/blob/main/cpp/Step10_2D_Poisson.cpp

The plots are shown here: https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/tree/main/Plots/2D%20poisson

From the plots we obtain a pressure field which ensures the divergence of velocity field is zero i.e. the incompressiblity condition is satisfied by introducing the source term and defining it in such a way which enventually creates a peak and valley in the pressure plot.