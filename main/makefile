#miau 


$(CPP) = -c

CPPFLAGS=-Wall

OBJECTS=\
    main.o \
    src\DoCreateWallet.o \
	src\ValidateCreate.o \
	inc\PrintError.o
	

HEADERS=\
    inc\DoCreateWallet.h \
	inc\ValidateCreate.h \
	inc\PrintError.h \
	inc\Types.h

               


# build all
all: moneytracker.exe



moneytracker.exe: $(OBJECTS) 
	g++ -o moneytracker.exe $(OBJECTS)           

main.o: main.cpp inc\DoCreateWallet.h inc\ValidateCreate.h inc\Types.h inc\PrintError.h
	g++ $(CPPFLAGS) -o main.o -c main.cpp
               
src\DoCreateWallet.o: src\DoCreateWallet.cpp inc\DoCreateWallet.h inc\Types.h
	g++ $(CPPFLAGS)  -o src\DoCreateWallet.o -c src\DoCreateWallet.cpp
 
src\ValidateCreate.o: src\ValidateCreate.cpp inc\ValidateCreate.h inc\Types.h
	g++ $(CPPFLAGS)  -o src\ValidateCreate.o -c src\ValidateCreate.cpp 

src\PrintError.o: src\PrintError.cpp inc\PrintError.h inc\Types.h
	g++ $(CPPFLAGS)  -o src\PrintError.o -c src\PrintError.cpp
	
	
	
#run: main.cpp src\DoCreateWallet.cpp inc\DoCreateWallet.h
#             g++ -Wall -c src\DoCreateWallet.cpp src\DoCreateWallet.o
#             g++ -Wall -c main.cpp main.o
#             g++ -o moneytracker.exe src\DoCreateWallet.o main.o
#             moneytracker.exe
               
# run tests
run: moneytracker.exe
	moneytracker.exe

# clean up
clean:
	del $(OBJECTS)
	del moneytracker.exe
