
RM = rm -f

COMPILER = g++

CPPFLAGS = -Wall

INCLUDES = -I..\inc

CPP = $(COMPILER) $(CPPFLAGS) $(INCLUDES)

AR = ar crf

HEADERS = \
	..\inc\DoCreateWallet.h\
	..\inc\ValidateCreate.h\
	..\inc\MainFunctions.h\
	..\inc\Types.h\
	..\inc\ReadConfig.h \
	..\inc\GetBalance.h

SRC_OBJECTS=\
	DoCreateWallet.o\
	ValidateCreate.o\
	PrintError.o\
	MainFunctions.o\
	ReadConfig.o\
	GetBalance.o
	
SRC_CPP=\
	DoCreateWallet.cpp\
	ValidateCreate.cpp\
	PrintError.cpp\
	MainFunctions.cpp\
	ReadConfig.cpp\
	GetBalance.cpp
	
src.a: $(SRC_OBJECTS)
	$(AR) src.a $(SRC_OBJECTS) 

#..\main.o: $(SRC_CPP) $(HEADERS)
#	$(CPP) -c $(SRC_CPP)
	
DoCreateWallet.o: DoCreateWallet.cpp $(HEADERS)
	$(CPP) -o DoCreateWallet.o -c DoCreateWallet.cpp

ValidateCreate.o: ValidateCreate.cpp $(HEADERS)
	$(CPP) -o ValidateCreate.o -c ValidateCreate.cpp
	
PrintError.o: PrintError.cpp $(HEADERS)
	$(CPP) -o PrintError.o -c PrintError.cpp

MainFunctions.o: MainFunctions.cpp $(HEADERS)
	$(CPP) -o MainFunctions.o -c MainFunctions.cpp
	
ReadConfig.o: ReadConfig.cpp $(HEADERS)
	$(CPP) -o ReadConfig.o -c ReadConfig.cpp

GetBalance.o: GetBalance.cpp $(HEADERS)
	$(CPP) -o GetBalance.o -c GetBalance.cpp

clean:
	$(RM) src.a
	$(RM) $(SRC_OBJECTS)
	#$(RM) main.o