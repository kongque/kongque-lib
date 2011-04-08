# author : kongque

CC := g++
LD := ld 
CFLAGS :=
LDFLAGS := -L/usr/lib/mesa -lglut
OBJS := framebase.o

framebase: $(OBJS) 
	$(LD) $(LDFLAGS) -o framebase $(OBJS)

$(OBJS): framebase.cpp
	$(CC) -c framebase.cpp

.PHONY: clean
clean:
	rm framebase *.o

