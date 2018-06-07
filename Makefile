# Compiler variables
DEBUG = 1
CXX = g++

ifdef DEBUG
CXXFLAGS = -rdynamic -DDEBUG -O0 -ggdb
else
CXXFLAGS = -O3
endif

LD_FLAGS =

# Sources and targets
SOURCES_DIR := src
BUILD_DIR := build

REPL_TARGET := $(BUILD_DIR)/repl/repl.exe
TEST_TARGET := $(BUILD_DIR)/test/test.exe

INCLUDE_DIRS := -Isrc/include/stepone

LIB_SOURCES := \
$(wildcard $(SOURCES_DIR)/impl/base/*.cpp) \
$(wildcard $(SOURCES_DIR)/impl/core/*.cpp) \
$(wildcard $(SOURCES_DIR)/impl/init/*.cpp) \
$(wildcard $(SOURCES_DIR)/impl/objects/*.cpp) \
$(wildcard $(SOURCES_DIR)/impl/symbols/*.cpp)

PARSER_SOURSES := \
$(wildcard $(SOURCES_DIR)/init/*.cpp) \
$(wildcard $(SOURCES_DIR)/parser/*.cpp)

REPL_SOURCES := \
$(wildcard $(SOURCES_DIR)/repl/*.cpp)

TEST_SOURCES := \
$(wildcard $(SOURCES_DIR)/test/*.cpp)


LIB_OBJECTS    := $(LIB_SOURCES:$(SOURCES_DIR)/%=$(BUILD_DIR)/%.o)
PARSER_OBJECTS := $(PARSER_SOURSES:$(SOURCES_DIR)/%=$(BUILD_DIR)/%.o)
REPL_OBJECTS   := $(REPL_SOURCES:$(SOURCES_DIR)/%=$(BUILD_DIR)/%.o)
TEST_OBJECTS   := $(TEST_SOURCES:$(SOURCES_DIR)/%=$(BUILD_DIR)/%.o)


ALL_TARGETS = $(REPL_TARGET) $(TEST_TARGET)
ALL_OBJECTS = $(LIB_OBJECTS) $(PARSER_OBJECTS) $(REPL_OBJECTS) $(TEST_OBJECTS)

# default target
all: build_all

############################################

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

#############################################


$(REPL_TARGET) : $(REPL_OBJECTS) $(PARSER_OBJECTS) $(LIB_OBJECTS)
	$(CXX) -Wl,--start-group $^ -Wl,--end-group $(LD_FLAGS) -o $@

$(TEST_TARGET) : $(TEST_OBJECTS) $(PARSER_OBJECTS) $(LIB_OBJECTS)
	$(CXX) -Wl,--start-group $^ -Wl,--end-group $(LD_FLAGS) -o $@


.PHONY: clean all build_all build_tests build_repl

build_repl: $(REPL_TARGET)

build_tests: $(TEST_TARGET)

build_all: $(ALL_TARGETS)


clean:
	rm -f $(ALL_OBJECTS) $(ALL_TARGETS)



include $(wildcard $(ALL_OBJECTS:$(BUILD_DIR)/%.cpp.o=$(DEPDIR)/%.d))
