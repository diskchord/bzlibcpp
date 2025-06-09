REM ============================================================================
REM  ____ _______      _ _
REM |  _ \___  / |    (_) |     _____
REM | |_) | / /| |     _| |__  / ____|     _
REM |  _ < / / | |    | | '_ \| |  _| |_ _| |_
REM | |_) / /__| |____| | |_) | | |_   _|_   _|
REM |____/_____|______|_|_.__/| |___|_|   |_|
REM                            \_____|
REM ============================================================================

@echo off

REM DJGPPINSTALL.BAT
REM BY ALEX PEPPE
REM FOR INSTALLATION OF BZLIBC++ ON A WINDOWS
REM OR DOS SYSTEM USING DJGPP 

REM Call 'make'
make

REM If this is not the path to the DJGPP 
REM directory, please change it to the correct one.
REM Remember to DOUBLE YOUR \'s!!!
set DJGPPPATH=C:\\DJGPP

REM Copying the lib file,
copy "lib\*.a" "%DJGPPPATH%\lib\"

REM Change path in bzlib.h
echo #define DIRECTORY "%DJGPPPATH%\\include\\" > .\bzlib.h.temp
echo #define INSTALL_DIRECTORY >> .\bzlib.h.temp
echo\ >> .\bzlib.h.temp
type src\bzlib.h >> .\bzlib.h.temp
move "src\bzlib.h" ".\bzlib.h.momentarybackup"
move ".\bzlib.h.temp" "src\bzlib.h"

REM Copyining header files
copy "src\*.h" "%DJGPPPATH%\include\"
move ".\bzlib.h.momentarybackup" "src\bzlib.h"
