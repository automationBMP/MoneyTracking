
RM = rm -f

COMPILER = g++

CPPFLAGS = -Wall

INCLUDES = -Imain\inc

CPP = $(COMPILER) $(CPPFLAGS)

HEADERS = \
	main\inc\DoCreateWallet.h \
	main\inc\ValidateCreate.h \
	main\inc\MainFunctions.h \
	main\inc\Types.h \
	main\inc\ReadConfig.h 


#first target, reached when calling make without a target
moneytracker:
# call make in 'main\src' subdir
	$(MAKE) -C main\src
	
#	$(MAKE) -C main\tst
# call make with target 'moneytracker.exe'
	$(MAKE) moneytracker.exe
	
# this should be called only by 'moneytracker',
# to make sure that libraries are up to date
moneytracker.exe: mymain main\src\src.a
	g++ -o moneytracker.exe main\main.o main\src\src.a

mymain: main\main.cpp $(HEADERS)
	$(CPP) -o main\main.o -c main\main.cpp $(INCLUDES)

#test.exe:
#	$(MAKE) -C main\tst test.exe

#test:main\tst\test.exe
#	main\tst\test.exe
test:
	$(MAKE) -C main\src
	$(MAKE) moneytracker.exe
	$(MAKE) -C main\tst test.exe
	$(MAKE) test.exe
	
test.exe: main\tst\test.exe
	main\tst\test.exe
	
clean:
	$(MAKE) -C main\src clean
	$(MAKE) -C main\tst clean
	$(RM) moneytracker.exe
	$(RM) main\main.o
	$(RM) my.wallet
	$(RM) my.wallet1
	$(RM) mywallet
	$(RM) newWallet
	$(RM) WalletBalanceCategory
	$(RM) WalletTest
	$(RM) yetother