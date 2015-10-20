@echo off

SET test_name=test_03_add_spending

SET default_spend_cat=other

rem clean log file for actual results
del %test_name%.actual > nul 2>&1
rem clean log file for expected results
del %test_name%.expected > nul 2>&1

(
 echo default_wallet = my.wallet
) > moneytracker.config

(
 echo +200.00 RON 
 echo 1445314481;+;111.00;salary;RON
) > my.wallet

(
 echo +200.00 RON 
 echo 1445314481;+;111.00;salary;RON
) > my.wallet.expected

rem ============================ TEST 0 ========================================
(
echo Example #0
echo [TEST: output]
moneytracker spend 145.12
echo [TEST: file]
type my.wallet
echo ... end ...
echo.
) >> %test_name%.actual 2>>&1

test_time.exe ";-;145.12;%default_spend_cat%;RON" >> my.wallet.expected

(
echo Example #0
echo [TEST: output]
echo Spending '%default_spend_cat%' in an amount of 145.12 RON was registered.
test_time.exe --gmt
echo [TEST: file]
type my.wallet.expected
echo ... end ...
echo.
) >> %test_name%.expected 2>>&1

rem ============================ TEST 1 ========================================
timeout /T 2 /NOBREAK >nul 2>&1

(
echo Example #1
echo [TEST: output]
moneytracker spend +0.45
echo [TEST: file]
type my.wallet
echo ... end ...
echo.
) >> %test_name%.actual 2>>&1

test_time.exe ";-;0.45;%default_spend_cat%;RON" >> my.wallet.expected

(
echo Example #1
echo [TEST: output]
echo Spending '%default_spend_cat%' in an amount of 0.45 RON was registered.
test_time.exe --gmt
echo [TEST: file]
type my.wallet.expected
echo ... end ...
echo.
) >> %test_name%.expected 2>>&1

rem ============================ TEST 2 ========================================
(
echo Example #2
echo [TEST: output]
moneytracker spend 0
echo [TEST: output]
moneytracker spend -1
echo [TEST: file]
type my.wallet
echo ... end ...
echo.
) >> %test_name%.actual 2>>&1

(
echo Example #2
echo [TEST: output]
echo error: spending should be higher than 0.
echo [TEST: output]
echo error: spending should be higher than 0.
echo [TEST: file]
type my.wallet.expected
echo ... end ...
echo.
) >> %test_name%.expected 2>>&1

rem ============================ TEST 3 ========================================
(
echo Example #3
echo [TEST: output]
moneytracker spend somesum
echo [TEST: output]
moneytracker spend
echo [TEST: file]
type my.wallet
echo ... end ...
echo.
) >> %test_name%.actual 2>>&1

(
echo Example #3
echo [TEST: output]
echo error: parameter for 'spend' should be a positive number
echo [TEST: output]
echo error: no ammount specified for 'spend'.
echo [TEST: file]
type my.wallet.expected
echo ... end ...
echo.
) >> %test_name%.expected 2>>&1

rem ============================ TEST 4 ========================================
timeout /T 2 /NOBREAK >nul 2>&1

(
echo Example #4
echo [TEST: output]
moneytracker spend +1 la-la la-la
echo [TEST: file]
type my.wallet
echo ... end ...
echo.
) >> %test_name%.actual 2>>&1

test_time.exe ";-;1.00;%default_spend_cat%;RON" >> my.wallet.expected

(
echo Example #4
echo [TEST: output]
echo Spending '%default_spend_cat%' in an amount of 1.00 RON was registered.
test_time.exe --gmt
echo [TEST: file]
type my.wallet.expected
echo ... end ...
echo.
) >> %test_name%.expected 2>>&1

rem ============================ TEST 5 ========================================
echo default_wallet         =C:\path\some.wallet        > moneytracker.config

(
echo Example #5
echo [TEST: output]
moneytracker spend 1000
echo [TEST: file]
type C:\path\some.wallet
type my.wallet
echo ... end ...
echo.
) >> %test_name%.actual 2>>&1

(
echo Example #5
echo [TEST: output]
echo error: could not open 'C:\path\some.wallet' to register transaction
echo [TEST: file]
echo The system cannot find the path specified.
type my.wallet.expected
echo ... end ...
echo.
) >> %test_name%.expected 2>>&1

rem ============================ TEST 6 ========================================
del moneytracker.config >nul 2>&1

(
echo Example #6
echo [TEST: output]
moneytracker spend 1000
echo [TEST: file]
type my.wallet
echo ... end ...
echo.
) >> %test_name%.actual 2>>&1

(
echo Example #6
echo [TEST: output]
echo error: could not open configuration 'moneytracker.config'
echo [TEST: file]
type my.wallet.expected
echo ... end ...
echo.
) >> %test_name%.expected 2>>&1

rem ============================ TEST 7 ========================================
(
echo.
echo 
echo default_wallet     =                       
echo some_other=value
) > moneytracker.config

(
echo Example #7
echo [TEST: output]
moneytracker spend 11.11
echo [TEST: file]
type my.wallet
echo ... end ...
echo.
) >> %test_name%.actual 2>>&1

(
echo Example #7
echo [TEST: output]
echo error: no default wallet configured in 'moneytracker.config'
echo [TEST: file]
type my.wallet.expected
echo ... end ...
echo.
) >> %test_name%.expected 2>>&1

rem ============================ TEST 8 ========================================
(
echo.
echo 
echo defualt_wallet=my.wallet                       
echo some_other=value
) > moneytracker.config

(
echo Example #8
echo [TEST: output]
moneytracker spend 111
echo [TEST: file]
type my.wallet
echo ... end ...
echo.
) >> %test_name%.actual 2>>&1

(
echo Example #8
echo [TEST: output]
echo error: no default wallet configured in 'moneytracker.config'
echo [TEST: file]
type my.wallet.expected
echo ... end ...
echo.
) >> %test_name%.expected 2>>&1

rem ============================ TEST 9 ========================================
timeout /T 2 /NOBREAK >nul 2>&1
echo +200.00 RON > my2.wallet
echo +200.00 RON > my2.wallet.expected

(
echo.
echo 
echo default_wallet=my2.wallet                       
echo default_wallet = my.wallet                       
echo some_other=value
) > moneytracker.config

(
echo Example #9
echo [TEST: output]
moneytracker spend 111
echo [TEST: file1]
type my2.wallet
echo [TEST: file2]
type my.wallet
echo ... end ...
echo.
) >> %test_name%.actual 2>>&1

test_time ";-;111.00;%default_spend_cat%;RON" >> my2.wallet.expected

(
echo Example #9
echo [TEST: output]
echo Spending '%default_spend_cat%' in an amount of 111.00 RON was registered.
test_time.exe --gmt
echo [TEST: file1]
type my2.wallet.expected
echo [TEST: file2]
type my.wallet.expected
echo ... end ...
echo.
) >> %test_name%.expected 2>>&1

rem ============================ TEARDOWN ======================================
del my.wallet >> %test_name%.actual 2>>&1
del my.wallet.expected >> %test_name%.actual 2>>&1
del moneytracker.config >> %test_name%.actual 2>>&1

rem this should have no output if everything works as expected
rem use diff unified format, and redirect output for later use
diff -u %test_name%.expected %test_name%.actual > %test_name%.diff

if %errorlevel% EQU 1 (
  echo [  FAILED] see %test_name%.diff
) else (
  echo [  PASSED] see %test_name%.diff
)

@echo on
@exit /b

