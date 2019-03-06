@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"
set NOT_FOUND="%text_not_found.txt%"

::При запуске без параметров ожидается ненулевой код возврата
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

::Переданы не все аргументы
%PROGRAM% matrix1.txt > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% incorrect_num_of_param.txt
if ERRORLEVEL 1 goto err

::Передается не существующий файл
%PROGRAM% not_existing_file.txt matrix1.txt > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% not_open_file.txt
if ERRORLEVEL 1 goto err

::Передается не все столбцы и не все строки
%PROGRAM% not_all_columns.txt not_all_rows.txt > %OUT% && goto err
fc %OUT% not_all_columns-out.txt
if ERRORLEVEL 1 goto err

::Передается не все столбцы
%PROGRAM% matrix1.txt not_all_columns.txt > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% not_all_columns-out.txt
if ERRORLEVEL 1 goto err

::Передается не все строки
%PROGRAM% matrix1.txt not_all_rows.txt > %OUT%
if NOT ERRORLEVEL 1 goto err
fc %OUT% not_all_rows-out.txt
if ERRORLEVEL 1 goto err

%PROGRAM% matrix1.txt matrix2.txt > %OUT% || goto err
fc %OUT% result_matrix.txt
if ERRORLEVEL 1 goto err


echo Program testing succeeded
exit /B 0

:err
echo Program testing failed
exit /B 1