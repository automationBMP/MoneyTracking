@echo off

rem check parameter
if [%1]==[] goto :no_path

rem check if parameter is a valid path
if not exist %1 goto :incorrect_path

rem save current directory
set TEST_DIR=%CD%

rem switch to directory
pushd %1

rem build application
mingw32-make moneytracker > %TEST_DIR%\moneytracker.build
rem exit if build failed
if %errorlevel% neq 0 goto :build_error

rem copy executable to test directory
copy moneytracker.exe %TEST_DIR%\moneytracker.exe >nul 2>&1
if %errorlevel% neq 0 goto :copy_error

rem go back to test directory
popd

if not exist test_time.exe goto :no_timer

rem call tests
echo ===========================================================================
echo [RUN     ] 01_create_wallet
call test_01_create_wallet.bat
@echo off

echo [RUN     ] 02_add_income
call test_02_add_income.bat
@echo off

echo [RUN     ] 03_add_spending
call test_03_add_spending.bat
@echo off

rem make sure echo is off
@echo off
echo ===========================================================================
goto :end


:no_path
echo Path to application repo is missing.
goto :end

:incorrect_path
echo Path %1 is not a valid directory.
goto :end

:build_error
popd
echo.
echo [   FAILED] Building moneytracker failed.
goto :end

:copy_error
popd
echo.
echo [   FAILED] Failed to copy moneytracker.exe
goto :end

:no_timer
echo test_time.exe not found
goto :end

:end
@echo on 
