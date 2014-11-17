SRCDIR := ../src

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
HEADERS := $(wildcard $(SRCDIR)/*.h)

OBJECTS := $(SOURCES)
OBJECTS := $(OBJECTS:.cpp=.o)
OBJECTS := $(OBJECTS:.c=.o)
OBJECTS := $(subst $(SRCDIR)/, , $(OBJECTS))

FLAGS := -rdynamic -DDEBUG -O0 -ggdb  -D_GLIBCXX_DEBUG

all: stepone.exe

stepone.exe : $(OBJECTS) $(HEADERS)
	g++ -o $@ $(OBJECTS) $(FLAGS)

$(OBJECTS) : %.o: $(SRCDIR)/%.cpp
	g++ -o $@ -c $< $(FLAGS)

.PHONY: clean all

clean:
	rm -f *.o *.exe
