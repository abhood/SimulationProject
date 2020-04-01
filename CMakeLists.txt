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

add_executable(HW3 src/main.cpp)
add_custom_command(TARGET HW3 POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   "${CMAKE_CURRENT_SOURCE_DIR}/config" "$<TARGET_FILE_DIR:HW3>/config")