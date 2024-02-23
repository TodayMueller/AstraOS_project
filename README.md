# baseAlt

## Description
This project consists of a shared library and a CLI utility that allows users to compare binary package lists of two branches obtained from a public REST API (https://rdb.altlinux.org/api/). The user inputs the names of the branches. The utility then performs a comparison of the obtained package lists and saves the results in three JSON files:
- All packages that exist in the first branch but not in the second.
- All packages that exist in the second branch but not in the first.
- All packages whose version-release is greater in the first branch than in the second.

## Installation

### Prerequisites
- CMake (version x.x.x)
- C++ Compiler
- [httplib](https://github.com/yhirose/cpp-httplib) library
- [nlohmann/json](https://github.com/nlohmann/json) library

### Build Instructions
1. Clone the repository:
   ```bash
   git clone git@github.com:TodayMueller/baseAlt.git
   ```
2. Navigate to the project directory:
   ```bash
   cd baseAlt
   ```
3. Create a build directory and navigate into it:
   ```bash
   mkdir build && cd build
   ```
4. Run CMake to configure the project:
   ```bash
   cmake ..
   ```
5. Build the project:
   ```bash
   make
   ```

## Usage
1. Run the CLI utility:
   ```bash
   ./baseAlt
   ```
2. Follow the prompts to enter the names of the two branches.
3. The utility will perform the package comparison and generate three JSON files:
   - `notInSecond.json`: Packages that exist only in the first branch.
   - `notInFirst.json`: Packages that exist only in the second branch.
   - `versionNew.json`: Packages with a version-release greater in the first branch than in the second.
