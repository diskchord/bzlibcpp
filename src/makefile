#!/bin/sh
################################################################################
#Alex Peppe
#makefile for BZLib
################################################################################

#-------------------------------------------------------------------------------
#Headers
#-------------------------------------------------------------------------------
CPARGUMENTS    	=
FILES          	= *.h *.rsc ../examples/*.cpp
VARIABLEFILE   	= varfile.dat
EXAMPLES	= examples/laser examples/mirrorcube examples/googlecube
SOURCE		= bzlibprefab.o bzlibshared.o bzlibarc.o bzlibbase.o bzlibworld.o bzlibpoint.o bzlibbox.o bzlibpyramid.o bzlibobjects.o bzlibmeshobject.o bzlibcone.o bzlibgroup.o bzlibmaterial.o bzliboldbox.o bzliboldpyramid.o bzlibsphere.o bzlibteleporter.o bzlibzones.o sharedstats.o
BUILDDIR	= ../lib

#-------------------------------------------------------------------------------
#Default installation directory
#-------------------------------------------------------------------------------
ifndef INCDIR
	INCDIR = /usr/include
endif

ifndef LIBRARYDIR
	LIBDIR = /usr/lib
endif

ifndef LIBNAME
	LIBNAME = libbzl
endif

noargs:	 $(SOURCE)
	 ar r $(LIBNAME).a $(SOURCE)
	 mv *.a $(BUILDDIR)

#-------------------------------------------------------------------------------
#BUILD THE OBJECTS
#-------------------------------------------------------------------------------

bzlibworld.o:
	$(GCCCALL) $(GCCARGS) bzlibworld.cpp

bzlibarc.o:
	$(GCCCALL) $(GCCARGS) bzlibarc.cpp

bzlibbase.o:
	$(GCCCALL) $(GCCARGS) bzlibbase.cpp

bzlibpoint.o:
	$(GCCCALL) $(GCCARGS) bzlibpoint.cpp

bzlibbox.o:
	$(GCCCALL) $(GCCARGS) bzlibbox.cpp

bzlibpyramid.o:
	$(GCCCALL) $(GCCARGS) bzlibpyramid.cpp

bzlibobjects.o:
	$(GCCCALL) $(GCCARGS) bzlibobjects.cpp

bzlibmeshobject.o:
	$(GCCCALL) $(GCCARGS) bzlibmeshobject.cpp

bzlibcone.o:
	$(GCCCALL) $(GCCARGS) bzlibcone.cpp

bzlibgroup.o:
	$(GCCCALL) $(GCCARGS) bzlibgroup.cpp

bzlibmaterial.o:
	$(GCCCALL) $(GCCARGS) bzlibmaterial.cpp

bzliboldbox.o:
	$(GCCCALL) $(GCCARGS) bzliboldbox.cpp

bzliboldpyramid.o:
	$(GCCCALL) $(GCCARGS) bzliboldpyramid.cpp

bzlibzones.o:
	$(GCCCALL) $(GCCARGS) bzlibzones.cpp

bzlibteleporter.o:
	$(GCCCALL) $(GCCARGS) bzlibteleporter.cpp

bzlibsphere.o:
	$(GCCCALL) $(GCCARGS) bzlibsphere.cpp

bzlibprefab.o:
	$(GCCCALL) $(GCCARGS) bzlibprefab.cpp

bzlibshared.o:
	$(GCCCALL) $(GCCARGS) bzlibshared.cpp

sharedstats.o:
	$(GCCCALL) $(GCCARGS) sharedstats.cpp

