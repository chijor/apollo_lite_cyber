SET (CMAKE_SYSTEM_VERSION 6.6.0)
SET (CMAKE_SYSTEM_PROCESSOR x86) # or SET (CMAKE_SYSTEM_PROCESSOR x86)

add_definitions(-DGNU_AARCH)
add_definitions(-DCYBER_RT)
SET (ARM FALSE)
#SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -V4.9.2,gcc_ntoarmv7le_cpp-ne -fexceptions" CACHE STRING "")


SET (CMAKE_C_COMPILER gcc)
SET (CMAKE_CXX_COMPILER g++)