#

CC = g++
CC_FLAGS = 
INCLUDE = 

all: cxbe.exe

.cpp.o:
	$(CC) -c $< $(CC_FLAGS) $(INCLUDE)

cxbe.exe: Error.o Exe.o Main.o Xbe.o OpenXDK.o
	$(CC) -o $@ Error.o Exe.o Main.o Xbe.o OpenXDK.o

clean: 
	rm -f *.a *.o *.exe *.dll *.xbe *.cxbe


