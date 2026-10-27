# 12-Steps-to-Navier-Stokes-in-C++

This repository includes the code for 12 steps to Navier Stokes in C++ which is based on the CFD Python (https://github.com/barbagroup/CFDPython) course by Prof. Lorena Barba. The aim of this project is to implement all 12 steps starting from 1D Linear Convection to Channel Flow for Navier Stokes in C++. CFD Python course is a good stepping stone in the field of scientific computing which teaches the basics of CFD in an algorithmic and interactive way, involving solution of partial differential equations which describe physics of fluid flow. 

Structure of the Repository:

1. Docs: It comprises of explanations for all the 12 steps which includes explanation of the underlying PDEs, their discretization, stability condition, initial and boundary conditions used, links to C++ code and plots, and discussion on the plots.

2. Plots: It stores the plots created after vizualising the data generated from solving the discretized equations through iterative codes for each of the 12 steps.
   
3. cpp: It contains the code for all the 12 steps.

## Overview of the 12 Steps:

1.  [Step 1](https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-cpp/blob/main/Docs/Step01.md) — 1D Linear Convection
2.  [Step 2](https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-cpp/blob/main/Docs/Step02.md) — 1D Non-linear Convection
3.  [Step 3](https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-cpp/blob/main/Docs/Step03.md) — 1D Diffusion 
4.  [Step 4](https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-cpp/blob/main/Docs/Step04.md) — 1D Burger's Equation
5.  [Step 5](https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-cpp/blob/main/Docs/Step05.md) — 2D Linear Convection
6.  [Step 6](https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-cpp/blob/main/Docs/Step06.md) — 2D Non-Linear Convection
7.  [Step 7](https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-cpp/blob/main/Docs/Step07.md) — 2D Diffusion Equation.
8.  [Step 8](https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-cpp/blob/main/Docs/Step08.md) — 2D Burger's Equation.
9.  [Step 9](https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-cpp/blob/main/Docs/Step09.md) — 2D Laplace Equation.
10. [Step 10](https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-cpp/blob/main/Docs/Step10.md) - 2D Poisson equation in 2D.
11. [Step 11](https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-cpp/blob/main/Docs/Step11.md)—Solving the Navier-Stokes equation for 2D cavity flow.
12. [Step 12](https://github.com/MAKIN-NIKAM/12-Steps-to-Navier-Stokes-in-cpp/blob/main/Docs/Step12.md) —Solves the Navier-Stokes equation for 2D channel flow.

## Build and run

Requires a C++ compiler such as g++.

g++ -O2 cpp/Step01_1D_Linear_Convection.cpp -o step01
./step01


The program writes its results to a CSV file, which was used to create the plots.



