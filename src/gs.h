//
// Created by CAI GAO on 2023/11/13.
//

#ifndef GRAY_SCOTT_SIM_G9_GS_H
#define GRAY_SCOTT_SIM_G9_GS_H
#include <vector>

// Declare the simulation parameters as external variables
extern const int width;
extern const int height;
extern double Du;
extern double Dv;
extern double F;
extern double k;
extern double threshold;
extern const double dt;
extern const int numIterations;
extern const int outputInterval;

// Declare the grid variables as external variables
extern std::vector<std::vector<double>> u;
extern std::vector<std::vector<double>> v;

void init();
void writeVTKFile(int iteration);
void simulateStep();
double countElementsAboveThreshold(double threshold);

#endif //GRAY_SCOTT_SIM_G9_GS_H
