@echo off
set MYDIR=%~dp0%
call "%VS100COMNTOOLS%vsvars32.bat"
set PATH=%PATH%;%MYDIR%felix-dist\bin
set FLX_INSTALL_DIR=%MYDIR%felix-dist
flx --test=%FLX_INSTALL_DIR% -I%MYDIR%\src --bundle_dir=%PWD%\gen --nocc %*

