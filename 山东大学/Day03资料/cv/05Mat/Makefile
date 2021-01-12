INCLUDES 	= -I/Users/yangqiang/Qt512/5.12.1/Src/qtbase/include \
		  	  -I/Users/yangqiang/Qt512/5.12.1/Src/qtbase/include/QtCore \
		      -I/Users/yangqiang/Qt512/5.12.1/Src/qtbase/include/GtGui \
		      -I/Users/yangqiang/Qt512/5.12.1/Src/qtbase/include/QtWidgets \
			  -I/usr/local/include/opencv4/

LIBS		= -lopencv_core \
			  -lopencv_highgui \
			  -lopencv_imgcodecs \
			  -lopencv_imgproc

# SOURCES  	= main.cpp ./m01_constructor/m01_constructor.cpp
# SOURCES  	= main_access.cpp ./m02_access/m02_access.cpp
# SOURCES  	= main_operator.cpp
SOURCES  	= main_init.cpp

FRAMEWORKS 	= -F/Users/yangqiang/Qt512/5.12.1/clang_64/lib \
			  -framework QtCore  \
		      -framework QtGui  \
		      -framework QtWidgets
LD_ARGS		= -Wl,-rpath,/Users/yangqiang/Qt512/5.12.1/clang_64/lib

main: $(SOURCES)
	g++ -omain $(SOURCES) -std=c++11 $(INCLUDES) $(LIBS)  $(FRAMEWORKS) $(LD_ARGS)

clean:
	rm -f main
