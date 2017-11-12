TARGET = leet_test
CC = g++
CPPFLAGS = -std=c++0x -Wall
LINKFLAGS = -lcppunit

SRC = /Users/ovsoil/Coding/Repo/leetcode/src
OBJS = StringTest

$(OBJS).o : $(OBJS).h $(OBJS).cpp
	g++ -o $(OBJS).o -c -I$(SRC)/leet_string $(OBJS).cpp

$(TARGET) : $(OBJS).o main.cpp
	$(CC) $(LINKFLAGS) -o $(TARGET) $(OBJS).o main.cpp

all: $(TARGET)

clean:
	rm -rf *.o $(TARGET)
