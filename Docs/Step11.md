### Step 11: Cavity Flow with Navier Stokes

The vector form of the incompressible Navier Stokes equation is given by:
$$\frac{\partial \vec{v}}{\partial t} + (\vec{v} \cdot \nabla)\vec{v} = -\frac{1}{\rho}\nabla p + \nu \nabla^2\vec{v}$$

We solve the above equation in 2D which gives us $u$ and $v$ momentum equations along with the Poisson equation.

The sysmtem of differential equations to solved are:

$$\frac{\partial u}{\partial t} + u \frac{\partial u}{\partial x} + v\frac{\partial u}{\partial y}= -\frac{1}{\rho} \frac{\partial p}{\partial x} + \nu(\frac{\partial^2 u}{\partial x^2} + \frac{\partial^2 u}{\partial y^2})$$

$$\frac{\partial v}{\partial t} + u \frac{\partial v}{\partial x} + v \frac{\partial v}{\partial y}= -\frac{1}{\rho} \frac{\partial p}{\partial y} + \nu(\frac{\partial^2 v}{\partial x^2} + \frac{\partial^2 v}{\partial y^2})$$

$$\frac{\partial^2 p}{\partial x^2} + \frac{\partial^2 p}{\partial y^2} = -\rho(\frac{\partial u}{\partial x} \frac{\partial u}{\partial x} + 2 \frac{\partial u}{\partial y} \frac{\partial v}{\partial x} + \frac{\partial v}{\partial y} \frac{\partial v}{\partial y})$$


The above equations are discretized based on the schemes used in previous steps.

$$u_{i,j}^{n+1} = u_{i,j}^n - u_{i,j}^n \frac{\Delta t}{\Delta x} (u_{i,j}^n - u_{i-1,j}^n) - v_{i,j}^n \frac{\Delta t}{\Delta y} (u_{i,j}^n - u_{i,j-1}^n)- \frac{\Delta t}{\rho 2 \Delta x} (p_{i+1,j}^n - p_{i-1,j}^n)+ \nu( \frac{\Delta t}{\Delta x^2} (u_{i+1,j}^n - 2u_{i,j}^n + u_{i-1,j}^n) + \frac{\Delta t}{\Delta y^2} (u_{i,j+1}^n - 2u_{i,j}^n + u_{i,j-1}^n))$$

$$v_{i,j}^{n+1} = v_{i,j}^n - u_{i,j}^n \frac{\Delta t}{\Delta x} (v_{i,j}^n - v_{i-1,j}^n) - v_{i,j}^n \frac{\Delta t}{\Delta y} (v_{i,j}^n - v_{i,j-1}^n)- \frac{\Delta t}{\rho 2 \Delta y} (p_{i,j+1}^n - p_{i,j-1}^n)+ \nu( \frac{\Delta t}{\Delta x^2} (v_{i+1,j}^n - 2v_{i,j}^n + v_{i-1,j}^n) + \frac{\Delta t}{\Delta y^2} (v_{i,j+1}^n - 2v_{i,j}^n + v_{i,j-1}^n))$$

$$p_{i,j}^n = \frac{\left(p_{i+1,j}^n + p_{i-1,j}^n\right) \Delta y^2 + \left(p_{i,j+1}^n + p_{i,j-1}^n\right) \Delta x^2}{2 \left(\Delta x^2 + \Delta y^2\right)}- \frac{\rho \Delta x^2 \Delta y^2 }{2 \left(\Delta x^2 + \Delta y^2\right)} (b_{i,j})$$

$$b_{i,j}=\frac{\rho}{\Delta t} \left( \frac{u_{i+1,j} - u_{i-1,j}}{2\Delta x} + \frac{v_{i,j+1} - v_{i,j-1}}{2\Delta y} - \frac{u_{i+1,j} - u_{i-1,j}}{2\Delta x} \frac{u_{i+1,j} - u_{i-1,j}}{2\Delta x} - 2 \frac{u_{i,j+1} - u_{i,j-1}}{2\Delta y} \frac{v_{i+1,j} - v_{i-1,j}}{2\Delta x} - \frac{v_{i,j+1} - v_{i,j-1}}{2\Delta y} \frac{v_{i,j+1} - v_{i,j-1}}{2\Delta y}\right)$$

The initial condition is: $u, v$ and $p$ are 0 everywhere.

The Boundary conditions are:

$u = 1$ at $y = 2$;

$u, v = 0$ on the other boundaries;

$\frac {\partial p}{\partial y} = 0$ at $y = 0$;

$p = 0$ at $y = 2$

$\frac {\partial p}{\partial x} = 0$ at $x = 0, 2$

The different functions defined to solve the differential equations:

1. The discretized Poisson equation is broken into two functions build_up and ppe.

2. In build_up we define $b_{i,j}$ and the remaining part of Poisson equation is solved in ppe.

3. In cavity_flow we call build_up and ppe to solve the $x$ and $y$ momentum equations.

The C++ code is : https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-cpp/blob/main/cpp/Step11_Cavity_Flow_for_N-S_Equation.cpp

The Plots are given here: https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-cpp/tree/main/Plots/Cavity%20Flow

From the pressure contour plots we can see that there are two distinct pressure regions while in the streamline plots the recirculation regions can be seen which are a result of lid driven cavity flow.





