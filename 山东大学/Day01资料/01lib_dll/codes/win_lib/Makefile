CL_ARGS    = /EHsc  \
             /MD \
             /source-charset:utf-8  \
		     /execution-charset:utf-8 \
			 /nologo

LINK_ARGS  = /MACHINE:X64 /NOLOGO

OUTFILE    = add.dll
LIBFILE    = add.lib
SOURCE     = add.c
OBJS       = add.obj

$(OUTFILE):$(SOURCE)
# 编译
	@cl /c $(CL_ARGS) /Fo:$(OBJS)  $(SOURCE)  /nologo
# 静态库
	@lib $(LINK_ARGS) /OUT:$(LIBFILE) $(OBJS) 

clean:
	@del *.obj *.dll *.pdb *.ilk *.exe *.lib 2>/Nul

