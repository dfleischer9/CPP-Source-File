CXX = g++
CXXFLAGS =
TARGET = parseXML
SRCS = parseXML.cpp pugixml.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) -o $(TARGET) $(SRCS) $(CXXFLAGS)

clean:
	if exist $(TARGET) del $(TARGET)

.PHONY: all clean
