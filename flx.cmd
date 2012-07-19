@echo off
set MYDIR=%~dp0%
@rem call "%VS100COMNTOOLS%vsvars32.bat"
set PATH=%PATH%;%MYDIR%felix-dist\bin
set FLX_INSTALL_DIR=%MYDIR%felix-dist
flx --test=%FLX_INSTALL_DIR% -I%MYDIR%\src -I%CD%\src --bundle_dir=%PWD%\gen --nocc %*

