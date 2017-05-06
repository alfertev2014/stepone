SOURCES_DIR = src
BUILD_DIR = build
TARGET = build/repl.exe
CXX = g++

DEBUG = 1

ifdef DEBUG
CXX_FLAGS = -rdynamic -DDEBUG -O0 -ggdb -D_GLIBCXX_DEBUG
else
CXX_FLAGS = -O3
endif

LD_FLAGS =

LIB_SOURCES := \
$(wildcard $(SOURCES_DIR)/impl/base/*.cpp) \
$(wildcard $(SOURCES_DIR)/impl/core/*.cpp) \
$(wildcard $(SOURCES_DIR)/impl/init/*.cpp) \
$(wildcard $(SOURCES_DIR)/impl/objects/*.cpp) \
$(wildcard $(SOURCES_DIR)/impl/symbols/*.cpp) \
$(wildcard $(SOURCES_DIR)/parser/*.cpp) \
$(wildcard $(SOURCES_DIR)/repl/*.cpp) \
$(wildcard $(SOURCES_DIR)/test/*.cpp)

INCLUDE_DIRS = -Isrc/include

OBJECTS := $(LIB_SOURCES:$(SOURCES_DIR)/%=$(BUILD_DIR)/%.o)

DIR_GUARD = mkdir -p $(@D) || true

.PHONY: clean all

all: $(TARGET)

$(TARGET) : $(OBJECTS) $(HEADERS)
	@${DIR_GUARD}
	$(CXX) -Wl,--start-group $(OBJECTS) -Wl,--end-group $(LD_FLAGS) -o $@

$(OBJECTS) : $(BUILD_DIR)/%.cpp.o: $(SOURCES_DIR)/%.cpp
	@${DIR_GUARD}
	$(CXX) -c $< $(CXX_FLAGS) $(INCLUDE_DIRS) -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
