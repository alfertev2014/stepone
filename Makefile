SOURCES := $(wildcard src/*.cpp)
HEADERS := $(wildcard src/*.h)

OBJECTS := $(SOURCES)
OBJECTS := $(OBJECTS:.cpp=.o)
OBJECTS := $(OBJECTS:.c=.o)

stepone.exe : $(OBJECTS) $(HEADERS)
	g++ -o $@ $(OBJECTS)

$(OBJECTS) : %.o: %.cpp
	g++ -o $@ -c $<