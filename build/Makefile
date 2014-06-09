SRCDIR := ../src

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
HEADERS := $(wildcard $(SRCDIR)/*.h)

OBJECTS := $(SOURCES)
OBJECTS := $(OBJECTS:.cpp=.o)
OBJECTS := $(OBJECTS:.c=.o)
OBJECTS := $(subst $(SRCDIR)/, , $(OBJECTS))

all: stepone.exe

stepone.exe : $(OBJECTS) $(HEADERS)
	g++ -o $@ $(OBJECTS)

$(OBJECTS) : %.o: $(SRCDIR)/%.cpp
	g++ -o $@ -c $<

.PHONY: clean all

clean:
	rm -f *.o *.exe
