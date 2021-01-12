SET (CMAKE_SYSTEM_VERSION 6.6.0)
SET (CMAKE_SYSTEM_PROCESSOR armv7) # or SET (CMAKE_SYSTEM_PROCESSOR x86)
SET (TOOLCHAIN ARM)

add_definitions(-DGNU_AARCH)
add_definitions(-DCYBER_RT)
SET (ARM TRUE)
#SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -V4.9.2,gcc_ntoarmv7le_cpp-ne -fexceptions" CACHE STRING "")

SET (CMAKE_C_COMPILER /home/jun/Desktop/GCC-Linaro-7.5.0-2019.12/bin/aarch64-linux-gnu-gcc)
SET (CMAKE_CXX_COMPILER /home/jun/Desktop/GCC-Linaro-7.5.0-2019.12/bin/aarch64-linux-gnu-g++)



