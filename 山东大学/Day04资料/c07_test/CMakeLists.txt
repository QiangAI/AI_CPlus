project(main)

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

include_directories(
    C:/opencv/install/include
)

link_directories(
    C:/opencv/install/x64/vc16/lib
)

# 获取数据集中某个图像，并保存为图像
add_executable(main  main.cpp)


target_link_libraries(main "${TORCH_LIBRARIES}" opencv_core420d.lib opencv_imgcodecs420d.lib opencv_highgui420d.lib opencv_imgproc420d.lib)
set_property(TARGET main PROPERTY CXX_STANDARD 11)
