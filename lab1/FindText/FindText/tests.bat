@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"
set NOT_FOUND="%text_not_found.txt%"

::��� ������� ��� ���������� ��������� ��������� ��� ��������
%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

::�������� �� ��� ���������
%PROGRAM% "computer are" > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% incorrect_number_of_parameters.txt
if ERRORLEVEL 1 goto ERR

%PROGRAM% computer.txt > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% incorrect_number_of_parameters.txt
if ERRORLEVEL 1 goto ERR

::���������� �� ������������ ����
%PROGRAM% not_existing_file.txt "can be found in thousands" > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% not_open_file.txt
if ERRORLEVEL 1 goto ERR

::���������� ������ ������
%PROGRAM% computer.txt "" > %OUT%
if NOT ERRORLEVEL 1 goto ERR
fc %OUT% empty_string.txt
if ERRORLEVEL 1 goto ERR

::������� 1 ������������ ������
%PROGRAM% computer.txt "can be found in thousands" > %OUT% || goto err
fc %OUT% one_line-out.txt
if ERRORLEVEL 1 goto ERR

::������� ��������� ������������ �����
%PROGRAM% computer.txt "computers are" > %OUT% || goto err
fc %OUT% computer-out.txt
if ERRORLEVEL 1 goto ERR

::�� ������� �� ������������ ������ � �����
%PROGRAM% computer.txt "computers can specific" > %OUT% && goto err
fc %OUT% text_not_found.txt
if ERRORLEVEL 1 goto ERR


echo Program testing succeeded
exit /B 0

:err
echo Program testing failed
exit /B 1