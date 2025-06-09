#!/bin/sh
################################################################################
#Alex Peppe
#makefile for BZLib
################################################################################

#-------------------------------------------------------------------------------
#Headers
#-------------------------------------------------------------------------------
CPARGUMENTS    = 
FILES          = src/*.h src/*.rsc examples/*.cpp
VARIABLEFILE   = varfile.dat
EXAMPLES       = examples/laser examples/mirrorcube examples/googlecube
SOURCE         = bzlibprefab.o bzlibshared.o bzlibarc.o bzlibbase.o bzlibworld.o bzlibpoint.o bzlibbox.o bzlibpyramid.o bzlibobjects.o bzlibmeshobject.o bzlibcone.o bzlibgroup.o bzlibmaterial.o bzliboldbox.o bzliboldpyramid.o bzlibsphere.o bzlibteleporter.o bzlibzones.o sharedstats.o
BUILDDIR       = ./lib
GCCCALL        = g++
GCCARGS        = -g -O -Wall -ansi -pedantic -c

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

noargs:   
	 cd src; make GCCCALL="$(GCCCALL)" GCCARGS="$(GCCARGS)"

install: $(FILES)
	 #======================================================================
	 # ____ _______      _ _
	 #|  _ \___  / |    (_) |     _____
	 #| |_) | / /| |     _| |__  / ____|     _
	 #|  _ < / / | |    | | '_ \| |  _| |_ _| |_
	 #| |_) / /__| |____| | |_) | | |_   _|_   _|
	 #|____/_____|______|_|_.__/| |___|_|   |_|
	 #                           \_____|
	 #======================================================================
	 #----------------------------------------------------------------------
	 #CHANGE DIRECTORY IN BZLIB IF NECESSARY
	 #----------------------------------------------------------------------
	 cat src/bzlib.h | sed -e s@`cat last.txt`@$(INCDIR)@ > src/bzlib.h
	 echo $(INCDIR) > ./last.txt
	 #----------------------------------------------------------------------
	 #INSTALLING HEADER FILES
	 #----------------------------------------------------------------------
	 cp src/*.h $(INCDIR) $(CPARGUMENTS)
	 #----------------------------------------------------------------------
	 #INSTALLING RESOURCE FILES
	 #----------------------------------------------------------------------
	 cp src/*.rsc $(INCDIR) $(CPARGUMENTS)
	 #----------------------------------------------------------------------
	 #COPY LIBRARY TO FINAL RESTING PLACE
	 #----------------------------------------------------------------------
	 cp $(BUILDDIR)/*.a $(LIBDIR)
	 #----------------------------------------------------------------------
	 #FIXING PERMISSIONS
	 #----------------------------------------------------------------------
	 chmod -R 755 $(INCDIR)/bzlib*
	 chmod -R 755 $(LIBDIR)/$(LIBNAME).a

clean:
	 rm -f -r $(BUILDDIR)/*.a
	 rm -f -r src/*.o

cleanobj:
	 rm -f src/*.o

#-------------------------------------------------------------------------------
#MAKE THE EXAMPLES
#-------------------------------------------------------------------------------

examples: $(EXAMPLES)
	  mv *.bzw maps/
	  mv *.txt maps/

examples/laser:
	  $(GCCCALL) examples/laser.cpp -o examples/laser -lbzl
	  examples/laser examples/

examples/mirrorcube:
	  $(GCCCALL) examples/mirrorcube.cpp -o examples/mirrorcube -lbzl
	  examples/mirrorcube

examples/googlecube:
	  $(GCCCALL) examples/googlecube.cpp -o examples/googlecube -lbzl
	  examples/googlecube
