CL_ARGS    = /EHsc  \
             /MD \
             /source-charset:utf-8  \
		     /execution-charset:utf-8 \
			 /nologo

LINK_ARGS  = /MACHINE:X64 /NOLOGO /DLL 

OUTFILE    = add.dll
LIBFILE    = add.lib
SOURCE     = add.c
OBJS       = add.obj


main: $(OUTFILE) call_add.c
#编译
	@cl  /c $(CL_ARGS)  /Fo:call_add.obj   call_add.c
#链接
	@link /NOLOGO /OUT:main.exe /DYNAMICBASE add.lib call_add.obj  >/Nul

$(OUTFILE):$(SOURCE)
# 编译
	@cl /c $(CL_ARGS) /Fo:$(OBJS)  $(SOURCE)
# 动态库
	@link $(LINK_ARGS) /OUT:$(OUTFILE) /EXPORT:yq_add $(OBJS)

clean:
	@del *.obj *.dll *.pdb *.ilk *.exe *.lib  *.exp 2>/Nul

