@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"
set NOT_FOUND="%text_not_found.txt%"

::При запуске без параметров ожидается ненулевой код возврата
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

::Переданы не все аргументы
%PROGRAM% "computer are" > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% incorrect_number_of_parameters.txt
if ERRORLEVEL 1 goto ERR

%PROGRAM% computer.txt > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% incorrect_number_of_parameters.txt
if ERRORLEVEL 1 goto ERR

::Передается не существующий файл
%PROGRAM% not_existing_file.txt "can be found in thousands" > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% not_open_file.txt
if ERRORLEVEL 1 goto ERR

::Передается пустая строка
%PROGRAM% computer.txt "" > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% empty_string.txt
if ERRORLEVEL 1 goto ERR

::Находит 1 существующую строку
%PROGRAM% computer.txt "can be found in thousands" > %OUT% || goto err
fc %OUT% one_line-out.txt
if ERRORLEVEL 1 goto ERR

::Находит несколько существующих строк
%PROGRAM% computer.txt "computers are" > %OUT% || goto err
fc %OUT% computer-out.txt
if ERRORLEVEL 1 goto ERR

::Не находит не существующую строку в файле
%PROGRAM% computer.txt "computers can specific" > %OUT% && goto err
fc %OUT% text_not_found.txt
if ERRORLEVEL 1 goto ERR


echo Program testing succeeded
exit /B 0

:err
echo Program testing failed
exit /B 1