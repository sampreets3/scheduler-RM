CXX=g++
SRCS=src/
LIBS=lib/
ODIR=build/
CXXFLAGS=-I$(LIBS) /usr/include/python3.8 -lpython3.8

all:
	@$(CXX) -o $(ODIR)task $(SRCS)main.cpp $(SRCS)tasks.cpp $(CXXFLAGS)
	@echo "Build complete. Executable generated in build directory."

.PHONY: clean
clean:
	@rm -rf build/*
