
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
	$(INC_DIR)\ReadConfig.h \
	$(INC_DIR)\GetBalance.h \
	$(INC_DIR)\ConfigFile.h

TST_OBJECTS=\
	TestRemoveStartingZeroes.o \
	TestIsValidNumber.o \
	TestConvertPath.o \
	TestConvertPathToOriginal.o \
	TestValidateCreate.o \
	TestCreateWallet.o \
	TestAddDecimalsToDefaultAmount.o \
	TestWalletName.o \
	TestAddLineinWallet.o \
	TestReturnFileasString.o \
	TestGetBalance.o \
	TestSpecifyCategory.o\
	TestValidateIncomeSpendCommands.o\
	TestGetBalanceCategory.o\
	TestChangeDefWallet.o


SRC_OBJECTS=\
	$(SRC_DIR)\DoCreateWallet.o\
	$(SRC_DIR)\ValidateCreate.o\
	$(SRC_DIR)\PrintError.o\
	$(SRC_DIR)\MainFunctions.o\
	$(SRC_DIR)\ReadConfig.o\
	$(SRC_DIR)\GetBalance.o\
	$(SRC_DIR)\ConfigFile.o

all: test.a test.exe
	
test.a: $(TST_OBJECTS)
	$(AR) test.a $(TST_OBJECTS)
	
test.exe: $(TST_OBJECTS) $(SRC_OBJECTS) $(GTEST_LIB)
	g++ -o test.exe $(TST_OBJECTS) $(SRC_OBJECTS) $(GTEST_LIB)

#test: test.exe
#	test.exe --gtest_filter=ChangeDefWallet.CorectDefaultWallet

# run tests
test: test.exe
	test.exe
	
#Test.exe	
TestRemoveStartingZeroes: TestRemoveStartingZeroes.o ..\src\DoCreateWallet.o 
	..\src\PrintError.o ..\inc\Types.h $(GTEST_LIB)
	$(CPP) -o TestRemoveStartingZeroes.exe TestRemoveStartingZeroes.o \
	..\src\DoCreateWallet.o ..\src\PrintError.o ..\inc\Types.h $(GTEST_LIB)

TestIsValidNumber: TestIsValidNumber.o ..\src\ValidateCreate.o 
	..\src\PrintError.o $(GTEST_LIB) 
	$(CPP) -o TestIsValidNumber.exe TestIsValidNumber.o \
	..\src\ValidateCreate.o ..\src\PrintError.o $(GTEST_LIB)

TestConvertPath: TestConvertPath.o ..\src\MainFunctions.o $(GTEST_LIB)
	$(CPP) -o TestConvertPath.exe TestConvertPath.o \
	..\src\MainFunctions.o $(GTEST_LIB)

TestConvertPathToOriginal: TestConvertPathToOriginal.o 
	..\src\MainFunctions.o $(GTEST_LIB) 
	$(CPP) -o TestConvertPathToOriginal.exe TestConvertPathToOriginal.o \
	..\src\MainFunctions.o $(GTEST_LIB)

TestValidateCreate:  TestValidateCreate.o ..\src\ValidateCreate.o 
	..\src\PrintError.o $(GTEST_LIB)
	$(CPP) -o TestValidateCreate.exe TestValidateCreate.o \
	..\src\ValidateCreate.o ..\src\PrintError.o $(GTEST_LIB)

TestCreateWallet: TestCreateWallet.o ..\src\DoCreateWallet.o 
	..\src\PrintError.o $(GTEST_LIB)
	$(CPP) -o TestCreateWallet.exe TestCreateWallet.o \
	..\src\DoCreateWallet.o ..\src\PrintError.o $(GTEST_LIB)
	
TestAddDecimalsToDefaultAmount: TestAddDecimalsToDefaultAmount.o 
	..\src\DoCreateWallet.o  ..\src\PrintError.o $(GTEST_LIB)
	$(CPP) -o TestAddDecimalsToDefaultAmount.exe TestAddDecimalsToDefaultAmount.o \
	..\src\DoCreateWallet.o ..\src\PrintError.o $(GTEST_LIB)
	
TestAddLineinWallet: TestAddLineinWallet.o ..\src\DoCreateWallet.o  
	..\src\PrintError.o $(GTEST_LIB)
	$(CPP) -o TestAddLineinWallet.exe TestAddLineinWallet.o \

TestWalletName: TestWalletName.o ..\src\DoCreateWallet.o ..\src\PrintError.o $(GTEST_LIB)
	$(CPP) -o TestWalletName.exe TestWalletName.o
	..\src\DoCreateWallet.o ..\src\PrintError.o $(GTEST_LIB)

TestReturnFileasString: TestReturnFileasString.o ..\src\MainFunctions.o $(GTEST_LIB)
	$(CPP) -o TestReturnFileasString.exe TestReturnFileasString.o \
	..\src\MainFunctions.o $(GTEST_LIB)

TestGetBalance: TestGetBalance.o ..\src\DoCreateWallet.o 
	..\src\PrintError.o $(GTEST_LIB)
	$(CPP) -o TestGetBalance.exe TestGetBalance.o ..\src\DoCreateWallet.o 
	..\src\PrintError.o $(GTEST_LIB)
	
TestSpecifyCategory: TestSpecifyCategory.o ..\src\MainFunctions.o 
	..\src\ReadConfig.o ..\src\PrintError.o $(GTEST_LIB)
	$(CPP) -o TestSpecifyCategory.exe TestSpecifyCategory.o 
	..\src\MainFunctions.o ..\src\ReadConfig.o ..\src\PrintError.o $(GTEST_LIB)

TestValidateIncomeSpendCommands: ValidateIncomeSpendCommands.o 
	..\src\MainFunctions.o ..\src\ReadConfig.o ..\src\PrintError.o $(GTEST_LIB)
	$(CPP) -o ValidateIncomeSpendCommands.exe ValidateIncomeSpendCommands.o 
	..\src\MainFunctions.o ..\src\ReadConfig.o ..\src\PrintError.o $(GTEST_LIB)

TestGetBalanceCategory: TestGetBalanceCategory.o ..\src\DoCreateWallet.o 
	..\src\PrintError.o $(GTEST_LIB)
	$(CPP) -o TestGetBalanceCategory.exe TestGetBalanceCategory.o 
	..\src\DoCreateWallet.o ..\src\PrintError.o $(GTEST_LIB)

TestChangeDefWallet: TestChangeDefWallet.o ..\src\MainFunctions.o 
	..\src\ReadConfig.o $(GTEST_LIB)
	$(CPP) -o TestChangeDefWallet.exe TestChangeDefWallet.o 
	..\src\MainFunctions.o ..\src\ReadConfig.o $(GTEST_LIB)
	
#Test.o 
TestRemoveStartingZeroes.o: TestRemoveStartingZeroes.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestRemoveStartingZeroes.o -c TestRemoveStartingZeroes.cpp
	
TestIsValidNumber.o: TestIsValidNumber.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestIsValidNumber.o -c TestIsValidNumber.cpp

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
	
TestWalletName.o: TestWalletName.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestWalletName.o -c TestWalletName.cpp
	
TestAddLineinWallet.o: TestAddLineinWallet.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestAddLineinWallet.o -c TestAddLineinWallet.cpp

TestReturnFileasString.o: TestReturnFileasString.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestReturnFileasString.o -c TestReturnFileasString.cpp
 	
TestGetBalance.o: TestGetBalance.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestGetBalance.o -c TestGetBalance.cpp
	
TestSpecifyCategory.o: TestSpecifyCategory.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestSpecifyCategory.o -c TestSpecifyCategory.cpp
	
TestValidateIncomeSpendCommands.o: TestValidateIncomeSpendCommands.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestValidateIncomeSpendCommands.o -c TestValidateIncomeSpendCommands.cpp
	
TestGetBalanceCategory.o: TestGetBalanceCategory.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestGetBalanceCategory.o -c TestGetBalanceCategory.cpp

TestChangeDefWallet.o: TestChangeDefWallet.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestChangeDefWallet.o -c TestChangeDefWallet.cpp
#..\main.o:
#	..\$(MAKE) -c ..\main.o	
	
..\src\DoCreateWallet.o:
	$(MAKE) -C ..\src\DoCreateWallet.o

..\src\ValidateCreate.o:
	$(MAKE) -c ..\src\ValidateCreate.o
	
..\src\PrintError.o:
	$(MAKE) -c ..\src\PrintError.o

..\src\MainFunctions.o:
	$(MAKE) -c ..\src\MainFunctions.o

..\src\ReadConfig.o:
	$(MAKE) -c ..\src\ReadConfig.o
	
..\src\GetBalance.o:
	$(MAKE) -c ..\src\GetBalance.o
	
..\src\ConfigFile.o:
	$(MAKE) -c ..\src\ConfigFile.o

	
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
	$(RM) TestWalletName.exe
	$(RM) TestAddLineinWallet.exe
	$(RM) test.exe
	$(RM) TestGetBalance.exe
	$(RM) TestValidateIncomeSpendCommands.exe
	$(RM) TestGetBalanceCategory.exe
	$(RM) WalletBalance
	$(RM) WalletTestt
	$(RM) WalletTesttt
	$(RM) WalletTest.txt