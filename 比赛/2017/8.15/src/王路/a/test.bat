@echo off
:loop
gen.exe
bf.exe
del bf.out
ren a.out bf.out
a.exe
fc bf.out a.out
if errorlevel == 1 pause
goto loop