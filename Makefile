
CFLAGS=-g -Wall -o

MYLS_RELY=init_fdata.o init_opert.o init_mdata.o Get_NPIFD.o Total.o Parsp.o Perfo.o files.o 

.PHONY: clean

my_ls: ${MYLS_RELY} 
	g++ ${CFLAGS} my_ls ${MYLS_RELY}

files.o: files.cpp files.h
	g++ -c ${CFLAGS} files.o files.cpp

init_opert.o: init_opert.cpp files.h
	g++ -c ${CFLAGS} init_opert.o init_opert.cpp

init_fdata.o: init_fdata.cpp files.h
	g++ -c ${CFLAGS} init_fdata.o init_fdata.cpp

init_mdata.o: init_mdata.cpp files.h
	g++ -c ${CFLAGS} init_mdata.o init_mdata.cpp

Parsp.o: Parsp.cpp files.h
	g++ -c ${CFLAGS} Parsp.o Parsp.cpp

Perfo.o: Perfo.cpp files.h
	g++ -c ${CFLAGS} Perfo.o Perfo.cpp

Get_NPIFD.o: Get_NPIFD.cpp files.h
	g++ -c ${CFLAGS} Get_NPIFD.o Get_NPIFD.cpp

Total.o: Total.cpp files.h
	g++ -c ${CFLAGS} Total.o Total.cpp

clean: 
	rm -rf my_ls ${MYLS_RELY}

