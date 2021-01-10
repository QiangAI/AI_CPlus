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

$(OUTFILE):$(SOURCE)
# 编译
	@cl /c $(CL_ARGS) /Fo:$(OBJS)  $(SOURCE)  /nologo
# 动态库
	@link $(LINK_ARGS) /OUT:$(OUTFILE) /EXPORT:yq_add $(OBJS)
clean:
	@del *.obj *.dll *.pdb *.ilk *.exe *.lib  *.exp 2>/Nul

