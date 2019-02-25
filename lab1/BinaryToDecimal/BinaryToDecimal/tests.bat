@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

::ѕри запуске без параметров ожидаетс€ ненулевой код возврата
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err
::exit /B 0

::ѕереданы не все аргументы
%PROGRAM% > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% incorrect_number_of_parameters.txt
if ERRORLEVEL 1 goto err

%PROGRAM% "1001" > %OUT% || goto err
fc %OUT% number_1001.txt
if ERRORLEVEL 1 goto err

%PROGRAM% "0" > %OUT% || goto err
fc %OUT% zero.txt
if ERRORLEVEL 1 goto err

%PROGRAM% "10021" > %OUT% 
if NOT ERRORLEVEL 1 goto err
fc %OUT% invalid_digit.txt
if ERRORLEVEL 1 goto err

%PROGRAM% "11111111111111111111111111111111" > %OUT% 
if NOT ERRORLEVEL 1 goto err
fc %OUT% overflow.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit /B 0

:err
echo Program testing failed
exit /B 1