@echo off

javac  -d ./classes singleton/*.java

cd ./classes 

java singleton.Test

cd ../

pause