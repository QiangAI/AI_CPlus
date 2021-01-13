del main.exe >\Nul
mkdir build
cd build
cmake -DCMAKE_PREFIX_PATH=C:\\libtorch  ..
cmake --build . --config Debug
copy .\Debug\main.exe  ..\
cd ..

