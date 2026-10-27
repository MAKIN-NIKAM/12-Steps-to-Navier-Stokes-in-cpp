### Step 12: Channel Flow with Navier Stokes

The difference between Step 11 and Step 12 is that we introduce a source term $F$ to the $u$ momentum equation which gives rise to a pressure driven flow in channel or a pipe and leads to the following equations:

$$\frac{\partial u}{\partial t} + u \frac{\partial u}{\partial x} + v\frac{\partial u}{\partial y}= -\frac{1}{\rho} \frac{\partial p}{\partial x} + \nu(\frac{\partial^2 u}{\partial x^2} + \frac{\partial^2 u}{\partial y^2}) + F$$

$$\frac{\partial v}{\partial t} + u \frac{\partial v}{\partial x} + v \frac{\partial v}{\partial y}= -\frac{1}{\rho} \frac{\partial p}{\partial y} + \nu(\frac{\partial^2 v}{\partial x^2} + \frac{\partial^2 v}{\partial y^2})$$

$$\frac{\partial^2 p}{\partial x^2} + \frac{\partial^2 p}{\partial y^2} = -\rho(\frac{\partial u}{\partial x} \frac{\partial u}{\partial x} + 2 \frac{\partial u}{\partial y} \frac{\partial v}{\partial x} + \frac{\partial v}{\partial y} \frac{\partial v}{\partial y})$$

The above equations are discretized based on the schemes used in previous steps.

$$u_{i,j}^{n+1} = u_{i,j}^n - u_{i,j}^n \frac{\Delta t}{\Delta x} (u_{i,j}^n - u_{i-1,j}^n) - v_{i,j}^n \frac{\Delta t}{\Delta y} (u_{i,j}^n - u_{i,j-1}^n)- \frac{\Delta t}{\rho 2 \Delta x} (p_{i+1,j}^n - p_{i-1,j}^n)+ \nu( \frac{\Delta t}{\Delta x^2} (u_{i+1,j}^n - 2u_{i,j}^n + u_{i-1,j}^n) + \frac{\Delta t}{\Delta y^2} (u_{i,j+1}^n - 2u_{i,j}^n + u_{i,j-1}^n) +\Delta tF)$$

$$v_{i,j}^{n+1} = v_{i,j}^n - u_{i,j}^n \frac{\Delta t}{\Delta x} (v_{i,j}^n - v_{i-1,j}^n) - v_{i,j}^n \frac{\Delta t}{\Delta y} (v_{i,j}^n - v_{i,j-1}^n)- \frac{\Delta t}{\rho 2 \Delta y} (p_{i,j+1}^n - p_{i,j-1}^n)+ \nu( \frac{\Delta t}{\Delta x^2} (v_{i+1,j}^n - 2v_{i,j}^n + v_{i-1,j}^n) + \frac{\Delta t}{\Delta y^2} (v_{i,j+1}^n - 2v_{i,j}^n + v_{i,j-1}^n))$$

$$p_{i,j}^n = \frac{\left(p_{i+1,j}^n + p_{i-1,j}^n\right) \Delta y^2 + \left(p_{i,j+1}^n + p_{i,j-1}^n\right) \Delta x^2}{2 \left(\Delta x^2 + \Delta y^2\right)}- \frac{\rho \Delta x^2 \Delta y^2 }{2 \left(\Delta x^2 + \Delta y^2\right)} (b_{i,j})$$

$$b_{i,j}=\frac{\rho}{\Delta t} \left( \frac{u_{i+1,j} - u_{i-1,j}}{2\Delta x} + \frac{v_{i,j+1} - v_{i,j-1}}{2\Delta y} - \frac{u_{i+1,j} - u_{i-1,j}}{2\Delta x} \frac{u_{i+1,j} - u_{i-1,j}}{2\Delta x} - 2 \frac{u_{i,j+1} - u_{i,j-1}}{2\Delta y} \frac{v_{i+1,j} - v_{i-1,j}}{2\Delta x} - \frac{v_{i,j+1} - v_{i,j-1}}{2\Delta y} \frac{v_{i,j+1} - v_{i,j-1}}{2\Delta y}\right)$$

The initial condition is: $u, v$ and $p$ are 0 everywhere.

The Boundary conditions are:

$u, v$ and $p$ are periodic on $x = 0, 2$

$u, v = 0$ at $y = 0, 2$

$\frac {\partial p}{\partial y} = 0$ at $y = 0, 2$

$F = 1$ everywhere

The same functions as Step 11 are defined to solve the differential equations:

1. The discretized Poisson equation is broken into two functions build_up and ppe.

2. In build_up we define $b_{i,j}$ and the remaining part of Poisson equation is solved in ppe.

3. In cavity_flow we call build_up and ppe to solve the $x$ and $y$ momentum equations.

The C++ code is : https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-cpp/blob/main/cpp/Step12_Channel_Flow_for_N-S_Equation.cpp

The plots are given here : https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-cpp/blob/main/Plots/Channel%20Flow/Channel%20Flow.png

The plot depicts the flow from left to right which is a consequence of the source term which mimics a pressure driven flow in the channel.