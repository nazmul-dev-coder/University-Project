#pragma once
#include <Eigen/Dense>
using namespace Eigen;

/*
 * center.hpp
 *
 * Provides a function to center a dataset by subtracting the mean of each column.
 *
 * Function:
 *  - centerData(const MatrixXd &data):
 *      Takes a matrix 'data' where each row is a sample and each column is a feature.
 *      Returns a new matrix where each column has zero mean (centered data).
 *
 * Purpose:
 *  - Centering is a preprocessing step for PCA, ensuring that the covariance
 *    matrix reflects only the variation in the data, not the mean.
 */

inline MatrixXd centerData(const MatrixXd &data) {
    return data.rowwise() - data.colwise().mean();
}
