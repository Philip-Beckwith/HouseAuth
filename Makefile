# the build target executable:
TARGET = secure_house

all: $(TARGET)

$(TARGET): HouseAuth.o Interpreter.o House.o Lock.o 
	g++ -o $(TARGET) HouseAuth.o Interpreter.o

HouseAuth.o : HouseAuth.cpp
	g++ -c HouseAuth.cpp

Interpreter.o : Interpreter.cpp
	g++ -c Interpreter.cpp

House.o : House.cpp
	g++ -c House.cpp

Lock.o : Lock.cpp
	g++ -c Lock.cpp

clean:
	rm $(TARGET)
	rm *.o
