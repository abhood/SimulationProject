cmake_minimum_required (VERSION 3.13) #CMake will fail if below this version

set(CMAKE_CXX_STANDARD 20) #CMake will include necessary compiler flags to enable c++20, if possible

#Defaults to placing all executables in the bin folder, and all libraries in the lib folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

#For integration with vcpkg. This line ensures any packages installed by vcpkg will be found by
#a CMake find_package call.
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

project(ELCT350)

set(SIMULATOR_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE SIMULATOR_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE SIMULATOR_HEADERS ${SIMULATOR_INCLUDE}/*.h)

add_executable(Simulator ${SIMULATOR_SOURCE} ${SIMULATOR_HEADERS})
target_include_directories(Simulator PRIVATE ${SIMULATOR_INCLUDE})

