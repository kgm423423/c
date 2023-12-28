@echo off

set var=%date%-%time%

git pull origin main
git add update.bat
git add Workspace
git commit -m %var%
git push origin main

pause>nul