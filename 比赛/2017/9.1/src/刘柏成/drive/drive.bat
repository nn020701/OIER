@echo off
:loop
drive_gen > drive.in
drive_bf
drive
fc drive.out bf.out
if not errorlevel 1 goto loop
pause 
