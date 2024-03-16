@echo off
setlocal
set "RELATIVE_PATH=%~1"
set "ABSOLUTE_PATH=%cd%/%RELATIVE_PATH%"
call Europa.exe "%ABSOLUTE_PATH%"
endlocal