#pragma once
#include <Eigen/Dense>
#include "matplotlibcpp.h"
#include <vector>
namespace plt = matplotlibcpp;
using namespace Eigen;
using namespace std;

/*
 * plot.hpp
 *
 * Plots the original 2D dataset and the reconstructed 1D projection using matplotlib-cpp.
 *
 * Function:
 *  - plotData(const MatrixXd &data, const VectorXd &data_1d, const MatrixXd &eigenvectors):
 *      Takes the original data matrix 'data', the 1D projected data 'data_1d',
 *      and the eigenvectors of the covariance matrix.
 *      Reconstructs the 2D projection along the first principal component (PC1).
 *      Converts Eigen matrices to std::vector for plotting.
 *      Displays a scatter plot comparing original and projected data points.
 *
 * Purpose:
 *  - Visualize PCA dimensionality reduction (2D → 1D).
 *  - Helps verify correctness of PCA visually by comparing original and projected data.
 */

inline void plotData(const MatrixXd &data, const VectorXd &data_1d, const MatrixXd &eigenvectors){
    int n = data.rows();
    VectorXd pc1 = eigenvectors.col(0);
    MatrixXd reconstructed = data_1d * pc1.transpose();
    reconstructed.rowwise() += data.colwise().mean();

    vector<double> x_orig(data.col(0).data(), data.col(0).data()+n);
    vector<double> y_orig(data.col(1).data(), data.col(1).data()+n);
    vector<double> x_proj(reconstructed.col(0).data(), reconstructed.col(0).data()+n);
    vector<double> y_proj(reconstructed.col(1).data(), reconstructed.col(1).data()+n);

    plt::figure_size(600,600);
    plt::scatter(x_orig, y_orig, 50.0, {{"color", "blue"}, {"label", "Original Data"}});
    plt::scatter(x_proj, y_proj, 50.0, {{"color", "red"}, {"label", "Projected Data"}});
    plt::title("PCA: 2D to 1D Projection");
    plt::xlabel("X"); plt::ylabel("Y"); plt::legend(); plt::show();
}
