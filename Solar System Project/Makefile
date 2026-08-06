 CXX = g++
CXXFLAGS = -std=c++14 -Wall -g
INCLUDES = -I./headers -I./headers/glad -I./headers/KHR -I./headers/stb
LDFLAGS = -lglfw -lGL -ldl -lpthread

SRCDIR = source
OBJDIR = build
BINDIR = .

SOURCES = $(SRCDIR)/main.cpp \
          $(SRCDIR)/Application.cpp \
          $(SRCDIR)/SphereObject.cpp \
          $(SRCDIR)/CubeObject.cpp \
          $(SRCDIR)/Sphere.cpp \
          $(SRCDIR)/glad.c

OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
OBJECTS := $(OBJECTS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

TARGET = $(BINDIR)/solar_system

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run