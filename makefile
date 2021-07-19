EXE := VisualSA

IDIR := include
LDIR := lib
SDIR := src
ODIR := obj

CXX := g++-10
CXXFLAGS := -g -Wall -W -pedantic -std=c++20

CPPFLAGS := -I$(IDIR)
CPPFLAGS += -MMD -MP

LDFLAGS := -L$(LDIR)

LINKSFML=-lsfml-graphics -lsfml-window -lsfml-system

INCSRC := $(wildcard $(LDIR)/*.cpp)
SRC := $(wildcard $(SDIR)/*.cpp)

IOBJ := $(patsubst $(LDIR)/%.cpp,$(ODIR)/%.o,$(INCSRC))
SOBJ := $(patsubst $(SDIR)/%.cpp,$(ODIR)/%.o,$(SRC))
DEP := $(IOBJ:.o=.d) $(SOBJ:.o=.d)

.PHONY: all clean

$(warning $(INCSRC))
$(warning $(SRC))
$(warning $(TOTALSRC))
$(warning $(OBJ))
$(warning $(DEP))




all: $(EXE)

$(EXE): $(IOBJ) $(SOBJ)
	$(CXX) $^ $(LINKSFML) -o $@

$(IOBJ): $(ODIR)/%.o: $(LDIR)/%.cpp $(INCSRC) | $(ODIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

$(SOBJ): $(ODIR)/%.o: $(SDIR)/%.cpp $(SRC) | $(ODIR)
	echo "ssss"
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

$(ODIR):
	mkdir $@

clean :
	$(RM) -r $(ODIR) $(EXE)

-include $(DEP)
