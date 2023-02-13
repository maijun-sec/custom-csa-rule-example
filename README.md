# custom-csa-rule-example

## Prerequisites
- gcc 9.x + cmake + make
- llvm + clang 15.0.7


## build with cmake

``` bash
mkdir build && cd build
cmake -DLLVM_DIR=${LLVM_INSTALL_PATH}/lib/cmake/llvm ..
make -j8
```

## use as plugin

``` bash
# view a list of native rules supported by clang
clang -cc1 -analyzer-checker-help

# view the list of native rules and user-defined rules supported by Clang.
# In the following command, -load is the path of the SO library of the user-defined rule.
clang -cc1 -analyzer-checker-help -load xx.so

# perform analysis. Pay attention to the values of the following parameters:
# The value of -fplugin is the path of the SO library of the generated user-defined rule. You can also use -load xx.so.
# -analyzer-checker is followed by a list of rules to be used.
clang -c --analyzer -fplugin=xx.so -Xanalyzer -analyzer-checker=checker-list
```

## licenses
The code for this project is released under an Apache 2.0 License (included in the LICENSE file in the root directory of the project).

This project may use some other clang static analyzer rules, for these rules, will use original license.
- MainCallChecker: copy from original llvm-project, Apache 2.0

## Reference
- install llvm and clang 15.0.7: https://bbs.huaweicloud.com/blogs/391095
- llvm-project: https://github.com/llvm/llvm-project
