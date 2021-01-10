INCLUDES   = /I "C:\Qt\Qt-5.14.0\include"  \
             /I "C:\opencv\install\include" \
			 /I "C:\libtorch\include\torch\csrc\api\include"  \
             /I "C:\libtorch\include"

LIBS       = /LIBPATH:"C:\Qt\Qt-5.14.0\lib"  \
             /LIBPATH:"C:\opencv\install\x64\vc16\lib"  \
			 /LIBPATH:"C:\libtorch\lib" \
		     /DYNAMICBASE \
		       "opencv_core420d.lib" \
			   "opencv_imgcodecs420d.lib" \
			   "opencv_highgui420d.lib" \
			   "opencv_imgproc420d.lib" \
		       "Qt5Cored.lib" \
		       "Qt5Widgetsd.lib" \
			   "Qt5Guid.lib" \
			   "torch.lib" \
               "c10.lib"  \
               "torch_cpu.lib"


CL_ARGS    = /EHsc  \
             /MDd \
             /source-charset:utf-8  \
		     /execution-charset:utf-8 \
			 /nologo

LINK_ARGS  = /DEBUG /MACHINE:X64 /NOLOGO

OUTFILE    = main.exe
SOURCE     = qt_opencv_torch.cpp
OBJS       = qt_opencv_torch.obj

$(OUTFILE):$(SOURCE)
	@cl /c $(CL_ARGS) /Fo:$(OBJS) $(INCLUDES)  $(SOURCE) 
	@link $(LINK_ARGS) $(LIBS) /OUT:$(OUTFILE) $(OBJS)
clean:
	@del *.obj *.exe *.pdb *.ilk 2>/Nul


# 记得把Qt与OpenCV的dll所在目录设置为PATH环境变量，否则运行的时候会产生错误。
