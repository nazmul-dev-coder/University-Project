# PCA Assignment (2D → 1D) in C++

This project demonstrates **Principal Component Analysis (PCA)** using **Eigen Decomposition** in C++.  
It reduces a 2D dataset to 1D and visualizes the result using **matplotlib-cpp**.

---

## Project Structure

- `dataset.hpp` → Generate 2D dataset  
- `center.hpp` → Center data  
- `covariance.hpp` → Compute covariance matrix  
- `eigen.hpp` → Eigen decomposition  
- `pca_projection.hpp` → Project data & variance explained  
- `plot.hpp` → Reconstruct & plot data  
- `main.cpp` → Integrates all parts  
- `CMakeLists.txt` → Build configuration  

---

## Setup & Run

1. **Clone repository** and include `matplotlib-cpp` folder. Use ``` git clone https://github.com/lava/matplotlib-cpp ``` command.
2. **C++ Compiler** (g++ recommended, C++17 support)  
3. **Python 3.13** (or compatible version)  
4. **Python packages**: `numpy` and `matplotlib`  

Install Python packages:

```powershell/cmd
python -m pip install numpy matplotlib

```bash
mkdir build && cd build
cmake ..
make

## Run 

./PCA_Assignment
