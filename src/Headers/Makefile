CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = shapes

SRCS = main.cc Shape.cc Circle.cc Rectangle.cc ShapeFactory.cc GeometryUtils.cc
OBJS = $(SRCS:.cc=.o)
DEPS = Shape.h Circle.h Rectangle.h ShapeFactory.h GeometryUtils.h

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cc $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
