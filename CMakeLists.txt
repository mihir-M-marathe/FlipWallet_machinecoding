cmake_minimum_required(VERSION 3.29)
project(FlipWallet_machinecoding)

set(CMAKE_CXX_STANDARD 20)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(FlipWallet_machinecoding
        src/Transaction.cpp
        src/User.cpp
        src/Wallet.cpp
        src/main.cpp)