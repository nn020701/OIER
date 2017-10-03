:loop
3 > data.in
2 < data.in > 2.out
1 < data.in > 1.out
fc 1.out 2.out
if errorlevel==1 pause
goto loop
