# 12-Steps-to-Navier-Stokes-in-Python-C++
This repo includes the code for 12 steps to Navier Stokes in C++ which is based on the CFD Python course by Lorena Barbara. The aim of this project is to implement all 12 steps starting from 1D Linear Convection to Channel Flow in C++. CFD Python course is a good stepping stone in the field of scientific computing which teaches computational fluid dynamics in an algorithmic way involving solution of partial differential equations which describe physics of fluid flow. 

Step01: 1D Linear Convection

1D Linear Convection equation describes the motion of the wave moving with speed c in space and time.

$$\frac{\partial u}{\partial t} + c\,\frac{\partial u}{\partial x} = 0$$

The above equation is discretized in space and time, using the Forward Difference scheme for time derivative, and the Backward Difference scheme for the spatial derivative. We consider the discretization of 

