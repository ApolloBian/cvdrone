cmake_minimum_required(VERSION 3.6)
set(CMAKE_CXX_STANDARD 11)
set(PROJECT_SOURCE_DIR src)
set(PROJECT_BINARY_DIR bin)

project(cvdrone)
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
add_executable(cvdrone ${source_files})

# dependency opencv
find_package(OpenCV REQUIRED)
target_link_libraries(cvdrone ${OpenCV_LIBS} )


#dependency ffmpeg
include(src/3rdparty/FindFFMPEG.cmake)
target_link_libraries(cvdrone ${FFMPEG_LIBRARIES})


project(demo)
include_directories(src/)
add_executable(demo samples/sample_camera_calibration.cpp ${ardrone_executable})
target_link_libraries(demo ${OpenCV_LIBS} ${FFMPEG_LIBRARIES})





