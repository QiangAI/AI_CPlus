del main.exe >\Nul
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=C:\\libtorch  ..
cmake --build . --config Debug
copy .\Debug\main.exe  ..\
cd ..


rem 使用mnist.py下载手写字符文件，使用格式是python mnist.py -d data 下载到当前目录的data目录中； 

