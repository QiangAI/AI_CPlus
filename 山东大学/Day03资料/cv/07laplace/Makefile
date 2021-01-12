INCLUDES 	= -I/Users/yangqiang/Qt512/5.12.1/Src/qtbase/include \
		  	  -I/Users/yangqiang/Qt512/5.12.1/Src/qtbase/include/QtCore \
		      -I/Users/yangqiang/Qt512/5.12.1/Src/qtbase/include/GtGui \
		      -I/Users/yangqiang/Qt512/5.12.1/Src/qtbase/include/QtWidgets \
			  -I/usr/local/include/opencv4/
LIBS		= -lopencv_core \
			  -lopencv_highgui \
			  -lopencv_imgcodecs \
			  -lopencv_imgproc
FRAMEWORKS 	= -F/Users/yangqiang/Qt512/5.12.1/clang_64/lib \
			  -framework QtCore  \
		      -framework QtGui  \
		      -framework QtWidgets
LD_ARGS		= -Wl,-rpath,/Users/yangqiang/Qt512/5.12.1/clang_64/lib

UICTOOL		= /usr/local/Qt-5.12.1/bin/uic
MOCTOOL 	= /usr/local/Qt-5.12.1/bin/moc

HEADER		= dlglaplace.h
MOCS 		= moc_dlglaplace.cpp
SOURCES  	= $(MOCS) main.cpp dlglaplace.cpp
UICS		= laplace.ui


main: $(SOURCES) $(MOCS) uic
	g++ -omain $(SOURCES) -std=c++11 $(INCLUDES) $(LIBS)  $(FRAMEWORKS) $(LD_ARGS)

$(MOCS): dlglaplace.h
	$(MOCTOOL) -o $(MOCS)  $(HEADER)

uic: $(UICS)
	$(UICTOOL) -o $(basename $(UICS)).h    $(UICS)

clean:
	rm -f main $(MOCS)  $(basename $(UICS)).h