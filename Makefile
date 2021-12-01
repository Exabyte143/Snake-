debug:
	cl /Od /Zi /EHsc /DDEBUG /std:c++latest /I include src\*.cpp /link /OUT:bin\Debug\snake.exe /LIBPATH:lib\VC16-x64 sfml-graphics.lib sfml-window.lib sfml-system.lib
	del *.obj
	del *.pdb
release:
	cl /O2 /EHsc /DRELEASE /std:c++latest /I include src\*.cpp /link /OUT:bin\Release\snake.exe /LIBPATH:lib\VC16-x64 sfml-graphics.lib sfml-window.lib sfml-system.lib
	del *.obj
clean:
	del bin\Debug\*.exe
	del bin\Release\*.exe
	del bin\Debug\*.pdb
	del bin\Debug\*.lik