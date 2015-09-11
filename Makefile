SOURCES_DIR = src
BUILD_DIR = build
TARGET = stepone.exe
CXX = g++

SOURCES := $(wildcard $(SOURCES_DIR)/*.cpp)
HEADERS := $(wildcard $(SOURCES_DIR)/*.h)

OBJECTS := $(SOURCES:$(SOURCES_DIR)/%=$(BUILD_DIR)/%.o)

print:
	echo $(OBJECTS)

FLAGS := -rdynamic -DDEBUG -O0 -ggdb -D_GLIBCXX_DEBUG

.PHONY: clean all

all: $(TARGET)

$(TARGET) : $(OBJECTS) $(HEADERS)
	$(CXX) $(OBJECTS) $(FLAGS) -o $@

$(OBJECTS) : $(BUILD_DIR)/%.cpp.o: $(SOURCES_DIR)/%.cpp
	$(CXX) -c $< $(FLAGS) -o $@


clean:
	rm -f $(OBJECTS) $(TARGET)
