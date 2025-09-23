#pragma once
#include <Eigen/Dense>
#include <iostream>
using namespace Eigen;

/*
 * eigen.hpp
 *
 * Performs Eigen decomposition of a covariance matrix for PCA.
 *
 * Function:
 *  - eigenDecomposition(const MatrixXd &cov, VectorXd &eigenvalues, MatrixXd &eigenvectors):
 *      Takes a symmetric covariance matrix 'cov'.
 *      Outputs:
 *          - 'eigenvalues': Vector of eigenvalues corresponding to principal components.
 *          - 'eigenvectors': Matrix whose columns are eigenvectors.
 *      The eigenvalues and eigenvectors are sorted in descending order of eigenvalue.
 *
 * Purpose:
 *  - Eigenvalues represent variance along principal components.
 *  - Eigenvectors represent directions of principal components.
 *  - Used in PCA to project and reduce dimensionality of the dataset.
 */


inline void eigenDecomposition(const MatrixXd &cov, VectorXd &eigenvalues, MatrixXd &eigenvectors){
    SelfAdjointEigenSolver<MatrixXd> eig(cov);
    eigenvalues = eig.eigenvalues();
    eigenvectors = eig.eigenvectors();
    if(eigenvalues(1) > eigenvalues(0)){
        std::swap(eigenvalues(0), eigenvalues(1));
        eigenvectors.col(0).swap(eigenvectors.col(1));
    }
}
