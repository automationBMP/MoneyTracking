
RM= rm -f

COMPILER = g++

CPPFLAGS = -Wall

INCLUDES = -I..\inc

CPP = $(COMPILER) $(CPPFLAGS) $(INCLUDES)

AR = ar crf

GTEST_DIR=C:\gtest-1.7.0

GTEST_LIB=$(GTEST_DIR)\make\gtest_main.a

GTEST_INC=-isystem $(GTEST_DIR)\include

SRC_DIR= ..\src
INC_DIR= ..\inc

HEADERS = \
    $(INC_DIR)\DoCreateWallet.h \
	$(INC_DIR)\ValidateCreate.h \
	$(INC_DIR)\PrintError.h \
	$(INC_DIR)\Types.h \
	$(INC_DIR)\MainFunctions.h \
	$(INC_DIR)\ReadConfig.h

TST_OBJECTS=\
	TestRemoveStartingZeroes.o \
	TestIsValidNumber.o \
	TestCheckArgcNumbers.o \
	TestConvertPath.o \
	TestConvertPathToOriginal.o \
	TestValidateCreate.o \
	TestCreateWallet.o \
	TestAddDecimalsToDefaultAmount.o

SRC_OBJECTS=\
	$(SRC_DIR)\DoCreateWallet.o\
	$(SRC_DIR)\ValidateCreate.o\
	$(SRC_DIR)\PrintError.o\
	$(SRC_DIR)\MainFunctions.o\
	$(SRC_DIR)\ReadConfig.o

all: test.a test.exe
	
test.a: $(TST_OBJECTS)
	$(AR) test.a $(TST_OBJECTS)
	
test.exe: $(TST_OBJECTS) $(SRC_OBJECTS) $(GTEST_LIB)
	g++ -o test.exe $(TST_OBJECTS) $(SRC_OBJECTS) $(GTEST_LIB)
	
#Test.exe	
TestRemoveStartingZeroes: TestRemoveStartingZeroes.o ..\src\DoCreateWallet.o ..\src\PrintError.o ..\inc\Types.h $(GTEST_LIB)
	$(CPP) -o TestRemoveStartingZeroes.exe TestRemoveStartingZeroes.o \
	..\src\DoCreateWallet.o ..\src\PrintError.o ..\inc\Types.h $(GTEST_LIB)

TestIsValidNumber: TestIsValidNumber.o ..\src\ValidateCreate.o ..\src\PrintError.o $(GTEST_LIB) 
	$(CPP) -o TestIsValidNumber.exe TestIsValidNumber.o \
	..\src\ValidateCreate.o ..\src\PrintError.o $(GTEST_LIB)

TestCheckArgcNumbers: TestCheckArgcNumbers.o ..\src\MainFunctions.o $(GTEST_LIB) 
	$(CPP) -o TestCheckArgcNumbers.exe TestCheckArgcNumbers.o \
	..\src\MainFunctions.o $(GTEST_LIB)

TestConvertPath: TestConvertPath.o ..\src\MainFunctions.o $(GTEST_LIB)
	$(CPP) -o TestConvertPath.exe TestConvertPath.o \
	..\src\MainFunctions.o $(GTEST_LIB)

TestConvertPathToOriginal: TestConvertPathToOriginal.o ..\src\MainFunctions.o $(GTEST_LIB) 
	$(CPP) -o TestConvertPathToOriginal.exe TestConvertPathToOriginal.o \
	..\src\MainFunctions.o $(GTEST_LIB)

TestValidateCreate:  TestValidateCreate.o ..\src\ValidateCreate.o ..\src\PrintError.o $(GTEST_LIB)
	$(CPP) -o TestValidateCreate.exe TestValidateCreate.o \
	..\src\ValidateCreate.o ..\src\PrintError.o $(GTEST_LIB)

TestCreateWallet: TestCreateWallet.o ..\src\DoCreateWallet.o ..\src\PrintError.o $(GTEST_LIB)
	$(CPP) -o TestCreateWallet.exe TestCreateWallet.o \
	..\src\DoCreateWallet.o ..\src\PrintError.o $(GTEST_LIB)
	
TestAddDecimalsToDefaultAmount: TestAddDecimalsToDefaultAmount.o ..\src\DoCreateWallet.o  ..\src\PrintError.o $(GTEST_LIB)
	$(CPP) -o TestAddDecimalsToDefaultAmount.exe TestAddDecimalsToDefaultAmount.o \
	..\src\DoCreateWallet.o ..\src\PrintError.o $(GTEST_LIB)

#Test.o 
TestRemoveStartingZeroes.o: TestRemoveStartingZeroes.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestRemoveStartingZeroes.o -c TestRemoveStartingZeroes.cpp
	
TestIsValidNumber.o: TestIsValidNumber.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestIsValidNumber.o -c TestIsValidNumber.cpp

TestCheckArgcNumbers.o: TestCheckArgcNumbers.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestCheckArgcNumbers.o -c TestCheckArgcNumbers.cpp

TestConvertPath.o: TestConvertPath.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestConvertPath.o -c TestConvertPath.cpp

TestConvertPathToOriginal.o: TestConvertPathToOriginal.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestConvertPathToOriginal.o -c TestConvertPathToOriginal.cpp

TestValidateCreate.o: TestValidateCreate.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestValidateCreate.o -c TestValidateCreate.cpp

TestCreateWallet.o: TestCreateWallet.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestCreateWallet.o -c TestCreateWallet.cpp

TestAddDecimalsToDefaultAmount.o: TestAddDecimalsToDefaultAmount.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestAddDecimalsToDefaultAmount.o -c TestAddDecimalsToDefaultAmount.cpp

#..\main.o:
#	..\$(MAKE) -c ..\main.o	
	
..\src\DoCreateWallet.o:
	$(MAKE) -c ..\src\DoCreateWallet.o

..\src\ValidateCreate.o:
	$(MAKE) -c ..\src\ValidateCreate.o
	
..\src\PrintError.o:
	$(MAKE) -c ..\src\PrintError.o

..\src\MainFunctions.o:
	$(MAKE) -c ..\src\MainFunctions.o

..\src\ReadConfig.o:
	$(MAKE) -c ..\src\ReadConfig.o
	
#TestRemoveStartingZeroes.exe: TestRemoveStartingZeroes
	#TestRemoveStartingZeroes.exe

#TestIsValidNumber.exe: TestIsValidNumber
	#TestIsValidNumber.exe

#TestCheckArgcNumbers.exe: TestCheckArgcNumbers
	#TestCheckArgcNumbers.exe
	
#TestConvertPath.exe: TestConvertPath
	#TestConvertPath.exe

#TestConvertPathToOriginal.exe: TestConvertPathToOriginal
	#TestConvertPathToOriginal.exe

#TestValidateCreate.exe: TestValidateCreate
	#TestValidateCreate.exe

#TestCreateWallet.exe:TestCreateWallet
	#TestCreateWallet.exe

#TestAddDecimalsToDefaultAmount.exe:	TestAddDecimalsToDefaultAmount
	#TestAddDecimalsToDefaultAmount.exe
	
#test: test.exe
	#test.exe
	
clean:
	$(RM) test.a
	$(RM) $(TST_OBJECTS)
	$(RM) TestRemoveStartingZeroes.exe
	$(RM) TestIsValidNumber.exe
	$(RM) TestCheckArgcNumbers.exe
	$(RM) TestConvertPath.exe
	$(RM) TestConvertPathToOriginal.exe
	$(RM) TestValidateCreate.exe
	$(RM) TestCreateWallet.exe
	$(RM) TestAddDecimalsToDefaultAmount.exe
	$(RM) test.exe

