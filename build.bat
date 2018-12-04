@echo off
cls

set CommonCompilerFlags=-MTd -nologo -fp:fast -fp:except- -Gm- -GR- -EHa- -Zo -Oi -WX -W4 -wd4201 -wd4100 -wd4189 -wd4505 -wd4127 -FC -Z7
set CommonCompilerFlags= -DDEVEMBER_DEV=1 -DDEVEMBER_WIN32=1 %CommonCompilerFlags% 
set CommonLinkerFlags= -incremental:no -opt:ref user32.lib gdi32.lib winmm.lib
set DLLLLinkerFlags= -incremental:no -opt:ref -PDB:devember_%random%.pdb -EXPORT:GameGetSoundSamples -EXPORT:GameUpdateAndRender -EXPORT:DEBUGGameFrameEnd

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build

REM Optimization switches /wO2
echo WAITING FOR PDB > lock.tmp
REM cl %CommonCompilerFlags% -O2 -c ..\code\devember_optimized.cpp -Fodevember_optimized.obj -LD
REM cl %CommonCompilerFlags% -Od ..\code\devember.cpp devember_optimized.obj -Fmdevember.map -LD /link %DLLLLinkerFlags%
del lock.tmp
cl %CommonCompilerFlags% -Od ..\code\win32_devember.cpp -Fmwin32_devember.map /link %CommonLinkerFlags%

popd
