# 定义编译，链接的公共变量
INCLUDES		=		/I "C:\Qt514\include" \
						/I "C:\opencv_sdu\install\include"
LIBS			=		/LIBPATH:"C:\Qt514\lib" \
						/LIBPATH:"C:\opencv_sdu\install\x64\vc16\lib"	\
						/DYNAMICBASE	\
							"Qt5Cored.lib"	\
							"Qt5Guid.lib"	\
							"Qt5Widgetsd.lib"	\
							"opencv_core420d.lib"	\
							"opencv_imgcodecs420d.lib"	\
							"opencv_videoio420d.lib"	\
							"opencv_imgproc420d.lib"
CL_ARGS			=		/EHsc	\
						/MDd	\
						/source-charset:utf-8	\
						/execution-charset:utf-8	\
						/nologo
LINK_ARGS		=		/MACHINE:X64	\
						/NOLOGO

TARGET			= 		main.exe

# 编译、链接与安装
$(TARGET):main.cpp guis\app.cpp  guis\frame.cpp devs\video.cpp
	@uic -o forms\camera.h forms\camera.ui
	@moc -o outs\moc_frame.cpp  guis\frame.h
	@moc -o outs\moc_video.cpp  devs\video.h
	@cl /c $(CL_ARGS) $(INCLUDES) 	/Fo:outs\moc_video.obj   	outs\moc_video.cpp
	@cl /c $(CL_ARGS) $(INCLUDES) 	/Fo:outs\moc_frame.obj   	outs\moc_frame.cpp
	@cl /c $(CL_ARGS) $(INCLUDES) 	/Fo:outs\main.obj   		main.cpp
	@cl /c $(CL_ARGS) $(INCLUDES) 	/Fo:outs\app.obj   			guis\app.cpp
	@cl /c $(CL_ARGS) $(INCLUDES) 	/Fo:outs\frame.obj   		guis\frame.cpp
	@cl /c $(CL_ARGS) $(INCLUDES) 	/Fo:outs\video.obj   		devs\video.cpp
	@link $(LINK_ARGS)  $(LIBS) /OUT:$(TARGET)  /SUBSYSTEM:CONSOLE \
		outs\main.obj 		\
		outs\app.obj 		\
		outs\frame.obj		\
		outs\moc_frame.obj	\
		outs\video.obj		\
		outs\moc_video.obj
		
# @link $(LINK_ARGS)  $(LIBS) /OUT:$(TARGET)  /SUBSYSTEM:WINDOWS
# 定义文件管理的伪目标
clean:
	@del  outs\*.obj main.exe  outs\moc_*.cpp forms\camera.h  2>/Nul
