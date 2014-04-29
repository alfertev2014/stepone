SOURCES := $(wildcard src/*.cpp)
HEADERS := $(wildcard src/*.h)

OBJECTS := $(SOURCES)
OBJECTS := $(OBJECTS:.cpp=.o)
OBJECTS := $(OBJECTS:.c=.o)

all: stepone.exe

stepone.exe : $(OBJECTS) $(HEADERS)
	g++ -o $@ $(OBJECTS)

$(OBJECTS) : %.o: %.cpp
	g++ -o $@ -c $<

.PHONY: clean

clean:
	rm -f *.o *.exe
