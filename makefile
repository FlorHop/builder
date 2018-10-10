builder: .\src\main.cpp .\obj\openfile.o .\obj\createsql.o  .\obj\createdir.o .\obj\log.o
	g++ -o .\bin\builder .\src\main.cpp .\obj\openfile.o .\obj\createsql.o .\obj\createdir.o .\obj\log.o
.\obj\openfile.o:.\src\openfile.cpp
	g++ -c -o .\obj\openfile.o .\src\openfile.cpp
.\obj\createsql.o:.\src\createsql.cpp
	g++ -c -o .\obj\createsql.o .\src\createsql.cpp
.\obj\createdir.o:.\src\createdir.cpp
	g++ -c -o .\obj\createdir.o .\src\createdir.cpp
.\obj\log.o:.\src\log.cpp
	g++ -c -o .\obj\log.o .\src\log.cpp

clean:
	rm  *.o