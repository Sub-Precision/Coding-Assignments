.SUFFIXES : .cpp

#Compile with g++
CC = g++

#use -g for gnu debugger and -std= for c++11 compiling
CXXFLAGS = -g -std=c++11

######Change to match all .cpp files.  Do not include .h files####
OBJS = hw1.o Rectangle.o

######Change from hw1 to whatever TARGET name you want for the executable.###
TARGET = nicholsCade_hW1

######Do NOT change the following 5 lines...Tabs Matter!#########
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

.cpp.o:
	$(CC) -c $(CXXFLAGS) $(INCDIR) $<

#In order to get rid of all .o files create, at the command prompt
#make clean

clean:
	rm -f $(OBJS) $(TARGET) core

#Create the zip file. Please change the name of the zip file
# and list the files you would like to add to it.
zipIt:
	zip -r nicholsCade_HW1.zip hw1.cpp Rectangle.cpp Rectangle.h Comparator.h README.txt makefile