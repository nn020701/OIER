@echo off
for /r %%s in (*.exe,*.o) do (
	erase %%s
)
