#miau 


CPPFLAGS=-Wall

GTEST_DIR=C:\gtest-1.7.0

GTEST_LIB=$(GTEST_DIR)\make\gtest_main.a

GTEST_INC=-isystem $(GTEST_DIR)\include



#app objects
MAIN_OBJECTS=\
	main.o \
	src\DoCreateWallet.o \
	src\ValidateCreate.o \
	src\PrintError.o

#app and test objects
TEST_OBJECTS=\
	tst\TestRemoveStartingZeroes.o
	
	
HEADERS=\
    inc\DoCreateWallet.h \
	inc\ValidateCreate.h \
	inc\PrintError.h \
	inc\Types.h

               


# build all
all: moneytracker.exe



moneytracker.exe: $(MAIN_OBJECTS) 
	g++ -o moneytracker.exe $(MAIN_OBJECTS)           

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


#### test area


test1: $(TEST_OBJECTS) $(GTEST_LIB) src\DoCreateWallet.o src\PrintError.o
	g++ -o test.exe $(TESTS_OBJECTS) \
	tst\TestRemoveStartingZeroes.o \
	src\DoCreateWallet.o src\PrintError.o $(GTEST_LIB)
	test.exe

tst\TestRemoveStartingZeroes.o: tst\TestRemoveStartingZeroes.cpp
	g++ -Wall $(GTEST_INC) \
	-o \
	tst\TestRemoveStartingZeroes.o \
	-c \
	tst\TestRemoveStartingZeroes.cpp



       
# run tests
run: moneytracker.exe
	moneytracker.exe

# clean up
clean:
	del $(MAIN_OBJECTS) $(TEST_OBJECTS)
	del moneytracker.exe
