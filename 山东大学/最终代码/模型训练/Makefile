# 定义编译，链接的公共变量
INCLUDES    =   /I "C:\libtorch\include"    \
                /I "C:\libtorch\include\torch\csrc\api\include" \
				/I "C:\opencv_sdu\install\include"

LIBS        =   /LIBPATH:"C:\libtorch\lib" \
				/LIBPATH:"C:\opencv_sdu\install\x64\vc16\lib" \
                /DYNAMICBASE \
                    "c10.lib"   \
                    "torch_cpu.lib"	\
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
$(TARGET): main.cpp model\lenet5.cpp train\lenet5train.cpp
	@cl /c $(CL_ARGS) $(INCLUDES) 	/Fo:main.obj   			main.cpp
	@cl /c $(CL_ARGS) $(INCLUDES) 	/Fo:lenet5.obj   		model\lenet5.cpp
	@cl /c $(CL_ARGS) $(INCLUDES) 	/Fo:lenet5train.obj   	train\lenet5train.cpp
	@link $(LINK_ARGS)  $(LIBS) /OUT:$(TARGET)  main.obj lenet5.obj  lenet5train.obj
# @link $(LINK_ARGS)  $(LIBS) /OUT:$(TARGET)  /SUBSYSTEM:WINDOWS
# 定义文件管理的伪目标
clean:
	@del  *.obj  main.exe  *.exp  *.lib  2>/Nul
