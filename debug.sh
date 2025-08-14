#!/bin/bash

# Keep an array of example executables
# EXAMPLES=("list_examples")

# Get project directory and name dynamically
PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_NAME="$(basename "$PROJECT_DIR")"

# Use relative paths and smart detection
cmake \
-DCMAKE_BUILD_TYPE=Debug \
-DCMAKE_MAKE_PROGRAM=ninja \
-DCMAKE_C_COMPILER=clang \
-DCMAKE_CXX_COMPILER=clang++ \
-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
-D CMAKE_CXX_FLAGS="-Wall -Wextra -Wshadow -Wpedantic -Wno-variadic-macros -isysroot $(xcrun --show-sdk-path)" \
-G Ninja \
-S . \
-B ./cmake-build-debug \
&& \
ninja -C ./cmake-build-debug \
&& \
ln -sf ./cmake-build-debug/compile_commands.json
# Loop through examples
# for example in "${EXAMPLES[@]}"; do
#     ./cmake-build-debug/examples/"$example"
# done
