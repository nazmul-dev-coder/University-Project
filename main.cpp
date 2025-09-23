#include <iostream>
#include "dataset.hpp"
#include "center.hpp"
#include "covariance.hpp"
#include "eigen.hpp"
#include "pca_projection.hpp"
#include "plot.hpp"

using namespace Eigen;
using namespace std;

int main() {
    MatrixXd data = generateData();
    MatrixXd centered = centerData(data);
    MatrixXd cov = computeCovariance(centered);

    VectorXd eigenvalues;
    MatrixXd eigenvectors;
    eigenDecomposition(cov, eigenvalues, eigenvectors);

    cout << "Eigenvalues:\n" << eigenvalues << "\n";
    cout << "Eigenvectors:\n" << eigenvectors << "\n";
    cout << "Variance explained by PC1: " << eigenvalues(0)/eigenvalues.sum()*100 << "%\n";

    VectorXd data_1d = projectOntoPC(centered, eigenvectors);

    plotData(data, data_1d, eigenvectors);

    return 0;
}
