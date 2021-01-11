INCLUDES   = /I "C:\Qt\Qt-5.14.0\include"	\
			 /I "C:\opencv_sdu\install\include"

LIBS       = /LIBPATH:"C:\Qt\Qt-5.14.0\lib"  \
			 /LIBPATH:"C:\opencv_sdu\install\x64\vc16\lib"  \
		     /DYNAMICBASE \
		       "Qt5Cored.lib" \
		       "Qt5Widgetsd.lib" \
			   "Qt5Guid.lib"  \
			   "opencv_core420d.lib" \
			   "opencv_imgcodecs420d.lib" \
			   "opencv_imgproc420d.lib" \
			   "opencv_videoio420d.lib " 

CL_ARGS    = /EHsc  \
             /MDd \
             /source-charset:utf-8  \
		     /execution-charset:utf-8 \
			 /nologo

LINK_ARGS  = /MACHINE:X64 /NOLOGO

TARGET     = main.exe

main: guis\frame.cpp guis\app.cpp main.cpp
	@moc -o out\moc_frame.cpp  guis\frame.h
	@moc -o out\moc_video.cpp  devs\video.h
	@cl /c $(CL_ARGS) $(INCLUDES) /Fo:out\moc_video.obj 	out\moc_video.cpp
	@cl /c $(CL_ARGS) $(INCLUDES) /Fo:out\moc_frame.obj 	out\moc_frame.cpp
	@cl /c $(CL_ARGS) $(INCLUDES) /Fo:out\video.obj 		devs\video.cpp
	@cl /c $(CL_ARGS) $(INCLUDES) /Fo:out\frame.obj 		guis\frame.cpp
	@cl /c $(CL_ARGS) $(INCLUDES) /Fo:out\app.obj  			guis\app.cpp
	@cl /c $(CL_ARGS) $(INCLUDES) /Fo:out\main.obj  		main.cpp 
	@link $(LINK_ARGS) $(LIBS) /OUT:$(TARGET) /SUBSYSTEM:WINDOWS\
			out\moc_video.obj \
			out\moc_frame.obj \
			out\video.obj \
			out\frame.obj \
			out\app.obj  \
			out\main.obj
clean:
	@del main.exe out\*.obj out\moc_*.cpp 2>/Nul

