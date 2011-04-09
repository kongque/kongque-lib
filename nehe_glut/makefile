# author : kongque

CXX := g++
LDFLAGS := -L/usr/lib/mesa -lglut

TARGETS := framebase polygon color 

all: $(TARGETS)
	

framebase : framebase.cpp
	$(CXX) $(LDFLAGS) -o framebase framebase.cpp

polygon : polygon.cpp
	$(CXX) $(LDFLAGS) -o polygon polygon.cpp

color : color.cpp
	$(CXX) $(LDFLAGS) -o color color.cpp

.PHONY: clean
clean:
	-rm -f *.o $(TARGETS) 

