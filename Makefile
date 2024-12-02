CXX = g++
CXXFLAGS = -I/home/ec2-user/pugixml-1.13/src
TARGET = parseXML
SRCS = parseXML.cpp /home/ec2-user/pugixml-1.13/src/pugixml.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) -o $(TARGET) $(SRCS) $(CXXFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
