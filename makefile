SHELL := powershell.exe
.SHELLFLAGS := -NoProfile -Command
# Force make to use powershell instead of executing commands directly

default:
	.\build.ps1

# cmake -G "MinGW Makefiles" -S .\src -B .\build
# @.\compile.bat; echo "Compiled shaders to build folder"
# @cd .\build; make; cd ..\