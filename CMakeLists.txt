cmake_minimum_required(VERSION 3.6)
project(cvdrone)
set(CMAKE_CXX_STANDARD 11)
set(PROJECT_SOURCE_DIR src)
set(PROJECT_BINARY_DIR bin)

set(main_executable src/main.cpp )
set(ardrone_dir src/ardrone)
set(ardrone_executable
        ${ardrone_dir}/ardrone.h
        ${ardrone_dir}/uvlc.h
        ${ardrone_dir}/ardrone.cpp
        ${ardrone_dir}/command.cpp
        ${ardrone_dir}/config.cpp
        ${ardrone_dir}/navdata.cpp
        ${ardrone_dir}/tcp.cpp
        ${ardrone_dir}/udp.cpp
        ${ardrone_dir}/version.cpp
        ${ardrone_dir}/video.cpp)


set(source_files ${main_executable} ${ardrone_executable})


# dependency opencv
find_package(OpenCV REQUIRED)



add_executable(cvdrone ${source_files})
target_link_libraries(cvdrone ${OpenCV_LIBS} )

