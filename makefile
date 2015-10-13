#miau 


CPPFLAGS=-Wall

GTEST_DIR=C:\gtest-1.7.0

GTEST_LIB=$(GTEST_DIR)\make\gtest_main.a

GTEST_INC=-isystem $(GTEST_DIR)\include


#app objects
MAIN_OBJECTS=\
	main\main.o \
	main\src\DoCreateWallet.o \
	main\src\ValidateCreate.o \
	main\src\PrintError.o \
	main\src\MainFunctions.o

#app and test objects
TEST_OBJECTS=\
	main\tst\TestRemoveStartingZeroes.o \
	main\tst\TestIsValidNumber.o \
	main\tst\TestCheckArgcNumbers.o \
	main\tst\TestConvertPath.o \
	main\tst\TestConvertPathToOriginal.o \
	main\tst\TestValidateCreate.o \
	main\tst\TestCreateWallet.o \
	main\tst\TestAddDecimalsToDefaultAmount.o
	
	
	
HEADERS=\
    main\inc\DoCreateWallet.h \
	main\inc\ValidateCreate.h \
	main\inc\PrintError.h \
	main\inc\Types.h \
	main\inc\MainFunctions.h \
	
	
	

TESTOBJECTS=\
	main\inc\PrintError.o


# build all
all: moneytracker.exe test1.exe test2.exe test4.exe test5.exe test6.exe test7.exe test8.exe test3.exe 

moneytracker: moneytracker.exe

moneytracker.exe: $(MAIN_OBJECTS) 
	g++ -o moneytracker.exe $(MAIN_OBJECTS)           

main.o: main\main.cpp main\inc\DoCreateWallet.h main\inc\ValidateCreate.h main\inc\Types.h main\inc\PrintError.h main\inc\MainFunctions.h main\tst\TestHelperCreateWallet.h
	g++ $(CPPFLAGS) -o main\main.o -c main\main.cpp
               
src\DoCreateWallet.o: main\src\DoCreateWallet.cpp main\inc\DoCreateWallet.h main\inc\Types.h
	g++ $(CPPFLAGS)  -o main\src\DoCreateWallet.o -c main\src\DoCreateWallet.cpp
 
src\ValidateCreate.o: main\src\ValidateCreate.cpp main\inc\ValidateCreate.h main\inc\Types.h
	g++ $(CPPFLAGS)  -o main\src\ValidateCreate.o -c main\src\ValidateCreate.cpp 

src\PrintError.o: main\src\PrintError.cpp main\inc\PrintError.h main\inc\Types.h
	g++ $(CPPFLAGS)  -o main\src\PrintError.o -c main\src\PrintError.cpp
	
src\MainFunctions.o: main\src\MainFunctions.cpp main\inc\MainFunctions.h main\inc\Types.h
	g++ $(CPPFLAGS)  -o main\src\MainFunctions.o -c main\src\MainFunctions.cpp	
	
#run: main.cpp src\DoCreateWallet.cpp inc\DoCreateWallet.h src\MainFunctions.cpp inc\MainFunctions.h 
#	g++ -Wall -c src\DoCreateWallet.cpp src\DoCreateWallet.o
#	g++ -Wall -c src\MainFunctions.cpp src\MainFunctions.o
#	g++ -Wall -c main.cpp main.o
#	g++ -o moneytracker.exe src\DoCreateWallet.o main.o
#	moneytracker.exe


#### test area


test1: $(TEST_OBJECTS) $(GTEST_LIB) main\src\DoCreateWallet.o main\src\PrintError.o
	g++ -o test1.exe $(TESTS_OBJECTS) \
	main\tst\TestRemoveStartingZeroes.o \
	main\src\DoCreateWallet.o main\src\PrintError.o $(GTEST_LIB)

#test1: tst\TestRemoveStartingZeroes.o src\DoCreateWallet.o src\PrintError.o $(GTEST_LIB)
#	g++ -o test1.exe tst\TestRemoveStartingZeroes.o src\DoCreateWallet.o src\PrintError.o $(GTEST_LIB)	
	
test2: $(TEST_OBJECTS) $(GTEST_LIB) main\src\ValidateCreate.o main\src\PrintError.o
	g++ -o test2.exe $(TESTS_OBJECTS) \
	main\tst\TestIsValidNumber.o \
	main\src\ValidateCreate.o main\src\PrintError.o $(GTEST_LIB)

#test3: $(TEST_OBJECTS) $(GTEST_LIB) src\MainFunctions.o 
#	g++ -o test3.exe $(TESTS_OBJECTS) \
#	tst\TestCheckArgcNumbers.o \
#	src\MainFunctions.o $(GTEST_LIB)
	
test3: main\tst\TestCheckArgcNumbers.o main\src\MainFunctions.o main\src\ValidateCreate.o main\src\PrintError.o $(GTEST_LIB)
	g++ -o test3.exe main\tst\TestCheckArgcNumbers.o main\src\MainFunctions.o main\src\ValidateCreate.o main\src\PrintError.o $(GTEST_LIB)	

test4: $(TEST_OBJECTS) $(GTEST_LIB) main\src\MainFunctions.o 
	g++ -o test4.exe $(TESTS_OBJECTS) \
	main\tst\TestConvertPath.o \
	main\src\MainFunctions.o $(GTEST_LIB)

test5: $(TEST_OBJECTS) $(GTEST_LIB) main\src\MainFunctions.o 
	g++ -o test5.exe $(TESTS_OBJECTS) \
	main\tst\TestConvertPathToOriginal.o \
	main\src\MainFunctions.o $(GTEST_LIB)

test6: $(TEST_OBJECTS) $(GTEST_LIB) main\src\ValidateCreate.o main\src\PrintError.o
	g++ -o test6.exe $(TESTS_OBJECTS) \
	main\tst\TestValidateCreate.o \
	main\src\ValidateCreate.o main\src\PrintError.o $(GTEST_LIB)

test7: main\tst\TestCreateWallet.o $(GTEST_LIB) main\src\DoCreateWallet.o main\src\PrintError.o main\inc\DoCreateWallet.h
	g++ -o test7.exe main\tst\TestCreateWallet.o main\src\DoCreateWallet.o main\src\PrintError.o $(GTEST_LIB)
	
test8: main\tst\TestAddDecimalsToDefaultAmount.o $(GTEST_LIB) main\src\DoCreateWallet.o main\src\PrintError.o main\inc\DoCreateWallet.h main\inc\Types.h
	g++ -o test8.exe main\tst\TestAddDecimalsToDefaultAmount.o main\src\DoCreateWallet.o main\src\PrintError.o $(GTEST_LIB)


tst\TestRemoveStartingZeroes.o: main\tst\TestRemoveStartingZeroes.cpp
	g++ -Wall $(GTEST_INC) \
	-o \
	main\tst\TestRemoveStartingZeroes.o \
	-c \
	main\tst\TestRemoveStartingZeroes.cpp

tst\TestIsValidNumber.o: main\tst\TestIsValidNumber.cpp
	g++ -Wall $(GTEST_INC) \
	-o \
	main\tst\TestIsValidNumber.o \
	-c \
	main\tst\TestIsValidNumber.cpp

tst\TestCheckArgcNumbers.o: main\tst\TestCheckArgcNumbers.cpp
	g++ -Wall $(GTEST_INC) \
	-o \
	main\tst\TestCheckArgcNumbers.o \
	-c \
	main\tst\TestCheckArgcNumbers.cpp

tst\TestConvertPath.o: main\tst\TestConvertPath.cpp
	g++ -Wall $(GTEST_INC) \
	-o \
	main\tst\TestConvertPath.o \
	-c \
	main\tst\TestConvertPath.cpp

tst\TestConvertPathToOriginal.o: main\tst\TestConvertPathToOriginal.cpp
	g++ -Wall $(GTEST_INC) \
	-o \
	main\tst\TestConvertPathToOriginal.o \
	-c \
	main\tst\TestConvertPathToOriginal.cpp

tst\TestValidateCreate.o: main\tst\TestValidateCreate.cpp
	g++ -Wall $(GTEST_INC) \
	-o \
	main\tst\TestValidateCreate.o \
	-c \
	main\tst\TestValidateCreate.cpp

tst\TestCreateWallet.o: main\tst\TestCreateWallet.cpp
	g++ -Wall $(GTEST_INC) \
	-o \
	main\tst\TestCreateWallet.o \
	-c \
	main\tst\TestCreateWallet.cpp

tst\TestAddDecimalsToDefaultAmount.o: main\tst\TestAddDecimalsToDefaultAmount.cpp
	g++ -Wall $(GTEST_INC) \
	-o \
	main\tst\TestAddDecimalsToDefaultAmount.o \
	-c \
	main\tst\TestAddDecimalsToDefaultAmount.cpp

	
#tst\TestCreateWallet.o: tst\TestCreateWallet.cpp inc\DoCreateWallet.h
#	g++ -Wall $(GTEST_INC) -o tst\TestCreateWallet.o -c tst\TestCreateWallet.cpp	
	
	
#tst\TestCreateWallet.o:src\TestCreateWallet.cpp  inc\DoCreateWallet.h 
#	g++ $(CPPFLAGS)  -o src\TestCreateWallet.o -c src\TestCreateWallet.cpp

       
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

test6.exe: test6
	test6.exe

test7.exe: test7
	test7.exe

test8.exe:	test8
	test8.exe

# clean up
clean:
	rm $(MAIN_OBJECTS) $(TEST_OBJECTS)
	rm moneytracker.exe
	rm test1.exe
	rm test2.exe
	rm test3.exe
	rm test4.exe
	rm test5.exe
	rm test6.exe
	rm test7.exe
	rm test8.exe
