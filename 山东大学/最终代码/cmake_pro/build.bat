@mkdir build
@cd build
@cmake  ..
@cmake --build . --config Debug
@copy .\Debug\main.exe ..\
@cd ..
