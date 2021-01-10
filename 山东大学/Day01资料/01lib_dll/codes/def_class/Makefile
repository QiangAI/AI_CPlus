CL_ARGS    = /EHsc  \
             /MD \
             /source-charset:utf-8  \
		     /execution-charset:utf-8 \
			 /nologo

obj: model.cpp model.h
# 编译目标文件
	@cl /c $(CL_ARGS)  model.cpp
# 链接动态库
	@link /MACHINE:X64 /NOLOGO /DLL /DEF:model.def model.obj

main: main.cpp
	@cl $(CL_ARGS) main.cpp /link /OUT:main.exe  
clean:
	@del *.obj *.dll *.pdb *.ilk *.exe *.lib  *.exp 2>/Nul

