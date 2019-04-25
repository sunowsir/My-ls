CFLAGS 		= -g -Wall -I ../include/
VPATH 		= ../:../src/:../include/
MYLS_RELY 	= \
   			init_fdata.o \
			init_opert.o \
			init_mdata.o \
			Get_NPIFD.o \
			Total.o \
			Parsp.o \
			Perfo.o \
			files.o 


Myls: ${MYLS_RELY} 
	@echo "[CC] [LInk] Myls"
	@g++ ${CFLAGS} ${MYLS_RELY} -o  Myls

files.o: files.cpp files.h
	@echo "[CC] [Build] files.o"
	@g++ -c ${CFLAGS} $<

init_opert.o: init_opert.cpp files.h
	@echo "[CC] [Build] init_opert.o"
	@g++ -c ${CFLAGS} $<

init_fdata.o: init_fdata.cpp files.h
	@echo "[CC] [Build] init_fdata.o"
	@g++ -c ${CFLAGS} $<

init_mdata.o: init_mdata.cpp files.h
	@echo "[CC] [Build] init_mdata.o"
	@g++ -c ${CFLAGS} $<

Parsp.o: Parsp.cpp files.h
	@echo "[CC] [Build] Parsp.o"
	@g++ -c ${CFLAGS} $<

Perfo.o: Perfo.cpp files.h
	@echo "[CC] [Build] Perfo.o"
	@g++ -c ${CFLAGS} $<

Get_NPIFD.o: Get_NPIFD.cpp files.h
	@echo "[CC] [Build] Get_NPIFD.o"
	@g++ -c ${CFLAGS} $<

Total.o: Total.cpp files.h
	@echo "[CC] [Build] Total.o"
	@g++ -c ${CFLAGS} $<


.PHONY: clean

clean: 
	@echo "[Clean] clean compile file"
	@rm -rf my_ls ${MYLS_RELY}

