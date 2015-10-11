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
	src\PrintError.o \
	src\MainFunctions.o

#app and test objects
TEST_OBJECTS=\
	tst\TestRemoveStartingZeroes.o \
	tst\TestIsValidNumber.o \
	tst\TestCheckArgcNumbers.o \
	tst\TestConvertPath.o \
	tst\TestConvertPathToOriginal.o
	
	
	
HEADERS=\
    inc\DoCreateWallet.h \
	inc\ValidateCreate.h \
	inc\PrintError.h \
	inc\Types.h \
	inc\MainFunctions.h

TESTOBJECTS=\
	inc\PrintError.o


# build all
all: moneytracker.exe test1.exe test2.exe test4.exe test5.exe test3.exe


moneytracker.exe: $(MAIN_OBJECTS) 
	g++ -o moneytracker.exe $(MAIN_OBJECTS)           

main.o: main.cpp inc\DoCreateWallet.h inc\ValidateCreate.h inc\Types.h inc\PrintError.h inc\MainFunctions.h
	g++ $(CPPFLAGS) -o main.o -c main.cpp
               
src\DoCreateWallet.o: src\DoCreateWallet.cpp inc\DoCreateWallet.h inc\Types.h
	g++ $(CPPFLAGS)  -o src\DoCreateWallet.o -c src\DoCreateWallet.cpp
 
src\ValidateCreate.o: src\ValidateCreate.cpp inc\ValidateCreate.h inc\Types.h
	g++ $(CPPFLAGS)  -o src\ValidateCreate.o -c src\ValidateCreate.cpp 

src\PrintError.o: src\PrintError.cpp inc\PrintError.h inc\Types.h
	g++ $(CPPFLAGS)  -o src\PrintError.o -c src\PrintError.cpp
	
src\MainFunctions.o: src\MainFunctions.cpp inc\MainFunctions.h inc\Types.h
	g++ $(CPPFLAGS)  -o src\MainFunctions.o -c src\MainFunctions.cpp	
	
#run: main.cpp src\DoCreateWallet.cpp inc\DoCreateWallet.h src\MainFunctions.cpp inc\MainFunctions.h 
#	g++ -Wall -c src\DoCreateWallet.cpp src\DoCreateWallet.o
#	g++ -Wall -c src\MainFunctions.cpp src\MainFunctions.o
#	g++ -Wall -c main.cpp main.o
#	g++ -o moneytracker.exe src\DoCreateWallet.o main.o
#	moneytracker.exe


#### test area


test1: $(TEST_OBJECTS) $(GTEST_LIB) src\DoCreateWallet.o src\PrintError.o
	g++ -o test1.exe $(TESTS_OBJECTS) \
	tst\TestRemoveStartingZeroes.o \
	src\DoCreateWallet.o src\PrintError.o $(GTEST_LIB)

#test1: tst\TestRemoveStartingZeroes.o src\DoCreateWallet.o src\PrintError.o $(GTEST_LIB)
#	g++ -o test1.exe tst\TestRemoveStartingZeroes.o src\DoCreateWallet.o src\PrintError.o $(GTEST_LIB)	
	
test2: $(TEST_OBJECTS) $(GTEST_LIB) src\ValidateCreate.o src\PrintError.o
	g++ -o test2.exe $(TESTS_OBJECTS) \
	tst\TestIsValidNumber.o \
	src\ValidateCreate.o src\PrintError.o $(GTEST_LIB)

#test3: $(TEST_OBJECTS) $(GTEST_LIB) src\MainFunctions.o 
#	g++ -o test3.exe $(TESTS_OBJECTS) \
#	tst\TestCheckArgcNumbers.o \
#	src\MainFunctions.o $(GTEST_LIB)
	
test3: tst\TestCheckArgcNumbers.o src\MainFunctions.o src\ValidateCreate.o src\PrintError.o $(GTEST_LIB)
	g++ -o test3.exe tst\TestCheckArgcNumbers.o src\MainFunctions.o src\ValidateCreate.o src\PrintError.o $(GTEST_LIB)	

test4: $(TEST_OBJECTS) $(GTEST_LIB) src\MainFunctions.o 
	g++ -o test4.exe $(TESTS_OBJECTS) \
	tst\TestConvertPath.o \
	src\MainFunctions.o $(GTEST_LIB)

test5: $(TEST_OBJECTS) $(GTEST_LIB) src\MainFunctions.o 
	g++ -o test5.exe $(TESTS_OBJECTS) \
	tst\TestConvertPathToOriginal.o \
	src\MainFunctions.o $(GTEST_LIB)

tst\TestRemoveStartingZeroes.o: tst\TestRemoveStartingZeroes.cpp
	g++ -Wall $(GTEST_INC) \
	-o \
	tst\TestRemoveStartingZeroes.o \
	-c \
	tst\TestRemoveStartingZeroes.cpp

tst\TestIsValidNumber.o: tst\TestIsValidNumber.cpp
	g++ -Wall $(GTEST_INC) \
	-o \
	tst\TestIsValidNumber.o \
	-c \
	tst\TestIsValidNumber.cpp

tst\TestCheckArgcNumbers.o: tst\TestCheckArgcNumbers.cpp
	g++ -Wall $(GTEST_INC) \
	-o \
	tst\TestCheckArgcNumbers.o \
	-c \
	tst\TestCheckArgcNumbers.cpp

tst\TestConvertPath.o: tst\TestConvertPath.cpp
	g++ -Wall $(GTEST_INC) \
	-o \
	tst\TestConvertPath.o \
	-c \
	tst\TestConvertPath.cpp

tst\TestConvertPathToOriginal.o: tst\TestConvertPathToOriginal.cpp
	g++ -Wall $(GTEST_INC) \
	-o \
	tst\TestConvertPathToOriginal.o \
	-c \
	tst\TestConvertPathToOriginal.cpp

       
# run tests
run: moneytracker.exe
	moneytracker.exe
	
test1.exe: test1 
	test1.exe 

test2.exe: test2
	test2.exe

test3.exe: test3
	test3.exe
	
test4.exe: test4
	test4.exe

test5.exe: test5
	test5.exe

# clean up
clean:
	del $(MAIN_OBJECTS) $(TEST_OBJECTS)
	del moneytracker.exe
	del test1.exe
	del test2.exe
	del test3.exe
	del test4.exe
	del test5.exe
