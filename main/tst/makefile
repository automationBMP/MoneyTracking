
CPP=g++
CPPFLAGS=-Wall -Iinc

GTEST_DIR=c:\gtest-1.7.0

GTEST_LIB=$(GTEST_DIR)\make\gtest_main.a

GTEST_INC=-isystem $(GTEST_DIR)\include

OBJECTS=\
	src\ValidateCreate.o

HEADERS=\
	inc\ValidateCreate.h

TESTS=\
	tst\testValidateCreate.o
	

# build all
all: testValidateCreate.exe

testValidateCreate.exe: $(LIBS) $(TESTS) $(GTEST_LIB)
	$(CPP) -o testValidateCreate.exe $(TESTS) $(GTEST_LIB)

tst\testValidateCreate.o: tst\testValidateCreate.cpp
	$(CPP) $(CPPFLAGS) $(GTEST_INC) -o tst\testValidateCreate.o -c tst\testValidateCreate.cpp

src\ValidateCreate.o: src\ValidateCreate.cpp
	$(CPP) $(CPPFLAGS) $(GTEST_INC) -o src\ValidateCreate.o -c src\ValidateCreate.cpp	

# play the game
play: game.exe
	game.exe

# run tests
testValidateCreate: testValidateCreate.exe
	testValidateCreate.exe

# clean up
clean:
	del $(OBJECTS)
	del $(TESTS)
	del game.exe
	del test.exe
