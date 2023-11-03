g++ -g -c main.cpp -o bin\main.o -I%cd%\lib\64\mingw64\include
@if %errorlevel% == 0 goto :nextone
@goto :nextpause

:nextone
g++ bin\main.o -o bin\app.exe -L%cd%\lib\64\mingw64\lib -lncursesw
@if %errorlevel% == 0 goto :nexttwo
@goto :nextpause

:nexttwo
.\bin\app.exe
@goto :nextpause

:nextpause
@pause
exit()