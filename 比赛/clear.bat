@echo off
for /r %%s in (*.exe,*.o,*.in,*.out) do (
	erase %%s
)
