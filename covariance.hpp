#pragma once
#include <Eigen/Dense>
using namespace Eigen;

/*
 * covariance.hpp
 *
 * Computes the covariance matrix of a dataset.
 *
 * Function:
 *  - computeCovariance(const MatrixXd &data):
 *      Takes a centered matrix 'data'.
 *      Returns the covariance matrix (features x features).
 *
 * Purpose:
 *  - The covariance matrix captures variance and correlation between features.
 *  - Used for Eigen decomposition in PCA.
 */

inline MatrixXd computeCovariance(const MatrixXd &centered) {
    int n = centered.rows();
    return (centered.adjoint() * centered) / double(n-1);
}
