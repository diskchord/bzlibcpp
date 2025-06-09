#!/bin/sh

#LASTGEN.SH
#BY ALEX PEPPE
#FOR THE REGENERATION OF A LOST LAST.TXT
#AND THE REGENERATION OF A BZLIB.H, WHICH
#IS USUALLY LOST IN MISSING LAST.TXT SITUTATIONS

echo /usr/include > last.txt

#------------------------------------------------------------------------------
#IN GENERAL, THE DISCOVERY OF A LAST.TXT MISSING IS MADE BY RUNNING MAKE
#INSTALL AND GETTING AN ERROR MESSAGE. BEFORE THAT ERROR MESSAGE IS SHOWN,
#THE COMMAND HAS ERASED BZLIB.H. THIS UNDOES ALL DAMAGE.
#------------------------------------------------------------------------------

if [ "$1" != norescue ]
then
	sh ./rescuebzlib.sh
fi
