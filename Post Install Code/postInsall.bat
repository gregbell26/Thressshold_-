@echo off

ECHO Thresshold Post Install
ECHO Copyright 2017 TriHard Studios
ECHO.
ECHO.
ECHO Verfing Files....
SET errorLevel = "0"
cd "C:\Program Files (x86)\Thresshold"
IF EXIST "Thresshold  0.6.5.exe" (
ECHO INFORMATION: Thresshold  0.6.5.exe verified. 
) ELSE (
rem SET errorLevel = "1"
ECHO ERROR: Thressshold  0.6.5.exe does not exist.
)

IF EXIST "ExpandsionPack.dll" (
ECHO INFORMATION: ExpandsionPack.dll verified.
) ELSE (
SET %errorLevel% = "1"
ECHO ERROR: A needed dll, ExpandsionPack.dll was not found. Thresshold will NOT work without it.
)

IF %errorLevel% == "1" (
ECHO INFORMATION: Program verifcation failed. Please re run the installer.
pause
exit
) ELSE (
ECHO INFORMATION: Verifcation complete. Setting permissions...
)


cd "C:\Program Files (x86)\"
ECHO INFORMATION: Changed working directory

Icacls Thresshold /grant Users:(CI)(OI)F /T

ECHO INFORMATION: Set permissions.
ECHO INFORMATION: Done.
pause
exit
