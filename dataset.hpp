#pragma once
#include <Eigen/Dense>
#include <random>
using namespace Eigen;

/*
 * dataset.hpp
 *
 * Generates a sample 2D dataset for PCA demonstration.
 *
 * Function:
 *  - generateData(int n=100):
 *      Generates 'n' samples with 2 features (2D points).
 *      Returns a MatrixXd where each row is a sample and each column is a feature.
 *      The data is drawn from correlated normal distributions to simulate PCA-relevant variance.
 *
 * Purpose:
 *  - Provides input data for PCA computation and visualization.
 *  - Can be replaced with any real 2D dataset with the same row=samples, col=features format.
 */

inline MatrixXd generateData(int n=100) {
    std::mt19937 gen(42);
    std::normal_distribution<> dist1(2.0, sqrt(3));
    std::normal_distribution<> dist2(3.0, sqrt(2));
    MatrixXd data(n,2);
    for(int i=0; i<n; i++){
        double x = dist1(gen);
        double y = dist2(gen) + 0.3*(x-2);
        data(i,0) = x;
        data(i,1) = y;
    }
    return data;
}
