# author : kongque

CXX := g++
LDFLAGS := -L/usr/lib/mesa -lglut

TARGETS := framebase polygon color texture freetype2

all: $(TARGETS)
	

framebase : framebase.cpp
	$(CXX) $(LDFLAGS) -o framebase framebase.cpp

polygon : polygon.cpp
	$(CXX) $(LDFLAGS) -o polygon polygon.cpp

color : color.cpp
	$(CXX) $(LDFLAGS) -o color color.cpp

texture : texture.cpp common/image.cpp common/image.h common/util.cpp common/util.h
	$(CXX) $(LDFLAGS) -o texture texture.cpp common/image.cpp common/util.cpp common/util.h

.PHONY: clean
clean:
	-rm -f *.o $(TARGETS) 

