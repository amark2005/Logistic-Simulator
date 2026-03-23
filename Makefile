# Variables
CXX = g++
TARGET = logsim
SRC = main.cpp

# Default: just typing 'make' will compile AND run
all: $(TARGET)
	./$(TARGET)

# Specifically for 'make compile' - only performs the build
compile: $(TARGET)

# The actual build rule
$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET)

# Clean up
clean:
	rm -f $(TARGET)
