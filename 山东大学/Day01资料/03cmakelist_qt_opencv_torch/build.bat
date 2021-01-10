@rem 创建工程构建工作目录
@mkdir build
@rem 进入构建目录
@cd build
@rem 生成本地工程
@cmake ..
@rem 直接编译visual studio工程
@cmake --build . --config Debug
@rem 拷贝执行文件到图像所在目录
@copy .\Debug\main.exe  ..\
@rem 回到代码目录
@cd  ..
