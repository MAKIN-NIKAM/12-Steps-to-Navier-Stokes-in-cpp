### Step 10: 2D Laplace Equation

The Laplace equation in 2D is given as:

$$\frac{\partial^2 p}{\partial x^2} + \frac{\partial^2 p}{\partial y^2}=0$$

Since, Laplace equation had second order derivatives so we can discretize simlarly as the diffusion equation, which gives us the discretized equation as:

$$\frac{p_{i+1,j}^n - 2p_{i,j}^n + p_{i-1,j}^n}{\Delta x^2} + \frac{p_{i,j+1}^n - 2p_{i,j}^n + p_{i,j-1}^n}{\Delta y^2} = 0$$

After rearranging the terms to solve for the unknown we get:
$$p_{i,j}^n = \frac{\Delta y^2(p_{i+1,j}^n + p_{i-1,j}^n) + \Delta x^2(p_{i,j+1}^n + p_{i,j-1}^n)}{2(\Delta x^2 + \Delta y^2)}$$

The boundary condition are:

$p = 0$ at $x = 0$ 

$p = y$ at $x = 2$

$$\frac{\partial p}{\partial y} = 0 \quad \text{at} \quad y = 0, 1$$

To solve the above discretized equation we create a function (Laplace2D) in the C++ code which iterates to solve for p until the relative L1 error is smaller than a specified target value.

The C++ code is given here: https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/blob/main/cpp/Step09_2D_Laplace.cpp

The plots are given here: https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-Python-C-/tree/main/Plots/2D%20Laplace

From the plots we could see the state of perfect equilibrium which is depicted by Laplace's Equation which is generated from the initial conditions with no initial disturbances or peturbations.





