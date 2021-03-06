# Some notes:
#	In order to run correctly this Makefile, you have to set this variables:
SYSTEMC_DIR=$$SYSTEMC_HOME
SCAMS_DIR=$$SCAMS_HOME
SCAMS_INC   = $(SCAMS_DIR)/include
SCAMS_LIB   = $(SCAMS_DIR)/lib-linux
SYSTEMC_INC = $(SYSTEMC_DIR)/include
SYSTEMC_LIB = $(SYSTEMC_DIR)/lib-linux64
#
#	So, you need to install both SystemC and SystemC-AMS.
#	Good Luck!

CXX        = g++
LD         = g++
RM         = rm -rf
CXXFLAGS   = -c -ansi

EXECUTABLE=./bin/platform.x

INCS =	-I $(SCAMS_INC) \
		-I $(SYSTEMC_INC)\
		-I./include/\
		-I.

LIBS =	-L $(SYSTEMC_LIB) \
		-L $(SCAMS_LIB) \
	 	-lsystemc-ams \
	 	-lsystemc \
	 	-lm \

OBJS = ./obj/controller.o \
	   ./obj/controller_err.o \
	   ./obj/fpm_RTL.o \
	   ./obj/fpm_TLM_LT_testbench.o \
	   ./obj/main.o \
	   ./obj/p_plant.o \
	   ./obj/support.o \
	   ./obj/transactor_RTL_TLM.o

all: $(EXECUTABLE)

install: all

$(EXECUTABLE): $(OBJS)
	@echo Linking $@
	@$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)
	
#------------------------------------------------------------
#---------------------------Main-----------------------------
obj/controller.o: src/controller.cc
	@echo Compiling $@
	@$(CXX) $(DEBUG) $(CXXFLAGS) $(INCS) -o $@ $<


obj/controller_err.o: src/controller_err.cc
	@echo Compiling $@
	@$(CXX) $(DEBUG) $(CXXFLAGS) $(INCS) -o $@ $<

obj/fpm_RTL.o: src/fpm_RTL.cc
	@echo Compiling $@
	@$(CXX) $(DEBUG) $(CXXFLAGS) $(INCS) -o $@ $<

obj/fpm_TLM_LT_testbench.o: src/fpm_TLM_LT_testbench.cc
	@echo Compiling $@
	@$(CXX) $(DEBUG) $(CXXFLAGS) $(INCS) -o $@ $<

obj/main.o: src/main.cc
	@echo Compiling $@
	@$(CXX) $(DEBUG) $(CXXFLAGS) $(INCS) -o $@ $<

obj/p_plant.o: src/p_plant.cc
	@echo Compiling $@
	@$(CXX) $(DEBUG) $(CXXFLAGS) $(INCS) -o $@ $<

obj/support.o: src/support.cc
	@echo Compiling $@
	@$(CXX) $(DEBUG) $(CXXFLAGS) $(INCS) -o $@ $<

obj/transactor_RTL_TLM.o: src/transactor_RTL_TLM.cc
	@echo Compiling $@
	@$(CXX) $(DEBUG) $(CXXFLAGS) $(INCS) -o $@ $<



clean:
	@echo "Cleaning..."
	@rm -rf obj/*.o
	@rm -rf *.x
	@rm -rf *.vcd
	@rm -rf $(EXECUTABLE)
	@echo "Done!"

.PHONY: all clean install
