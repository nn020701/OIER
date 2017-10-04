@echo off
for /l %%i in (1,1,100000) do (
echo No.%%i
gen.exe
a.exe
a_bl.exe
fc a.out a.ans
if errorlevel 1 pause
)