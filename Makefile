SOURCES_DIR = src
BUILD_DIR = build
TARGET = build/repl.exe
CXX = g++

DEBUG = 1

ifdef DEBUG
CXXFLAGS = -rdynamic -DDEBUG -O0 -ggdb
else
CXXFLAGS = -O3
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

OBJECTS := $(LIB_SOURCES:$(SOURCES_DIR)/%=$(BUILD_DIR)/%.o)

INCLUDE_DIRS = -Isrc/include/stepone -Isrc/include/parser


.PHONY: clean all

all: $(TARGET)


# See  http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/

DEPDIR := $(BUILD_DIR)/.deps
$(shell mkdir -p $(DEPDIR) >/dev/null)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td

COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
COMPILE.cc = $(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
POSTCOMPILE = @mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d && touch $@

DIRGUARD = @mkdir -p $(@D)

%.o: %.cpp
$(BUILD_DIR)/%.cpp.o: $(SOURCES_DIR)/%.cpp $(DEPDIR)/%.d
	${DIRGUARD}
	$(COMPILE.cc) $< -o $@ $(INCLUDE_DIRS)
	$(POSTCOMPILE)


$(DEPDIR)/%.d:
	${DIRGUARD}
.PRECIOUS: $(DEPDIR)/%.d



$(TARGET) : $(OBJECTS)
	$(CXX) -Wl,--start-group $(OBJECTS) -Wl,--end-group $(LD_FLAGS) -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

include $(wildcard $(OBJECTS:$(BUILD_DIR)/%.cpp.o=$(DEPDIR)/%.d))
