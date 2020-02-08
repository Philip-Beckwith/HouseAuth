# the build target executable:
TARGET = Testing

all: $(TARGET)

$(TARGET): Main.o Interpreter.o
	g++ -o $(TARGET) Main.o Interpreter.o

Main.o : Main.cpp
	g++ -c Main.cpp

Interpreter.o : Interpreter.cpp
	g++ -c Interpreter.cpp

clean:
	rm $(TARGET)
	rm *.o
