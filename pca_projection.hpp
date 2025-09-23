#pragma once
#include <Eigen/Dense>
#include <iostream>
using namespace Eigen;

/*
 * pca_projection.hpp
 *
 * Projects centered data onto the first principal component (PC1)
 * and prints the first few projected values.
 *
 * Function:
 *  - projectOntoPC(const MatrixXd &centered, const MatrixXd &eigenvectors):
 *      Takes a centered data matrix 'centered' (samples x features) and
 *      a matrix of eigenvectors.
 *      Projects the data onto the first principal component (PC1).
 *      Prints the first 5 projected values for verification.
 *      Returns a VectorXd containing all projected 1D values.
 *
 * Purpose:
 *  - Reduces data dimensionality (2D → 1D in this project).
 *  - Demonstrates PCA projection and variance capture visually and numerically.
 */

inline Eigen::VectorXd projectOntoPC(const Eigen::MatrixXd &centered, const Eigen::MatrixXd &eigenvectors) {
    Eigen::VectorXd pc1 = eigenvectors.col(0);
    Eigen::VectorXd data_1d = centered * pc1;
    double var_explained = eigenvectors(0,0) * eigenvectors(0,0); // simple example
    std::cout << "First 5 projected values:\n" << data_1d.head(5) << "\n";
    return data_1d;
}
