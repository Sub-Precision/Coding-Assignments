.SUFFIXES : .cpp

#Compile with g++
CC = g++

#use -g for gnu debugger and -std= for c++11 compiling
CXXFLAGS = -g -std=c++11

######Change to match all .cpp files.  Do not include .h files####
OBJS = ActorActress.o ActorActressDb.o Picture.o PictureDb.o main.o

######Change from hw1 to whatever TARGET name you want for the executable.###
TARGET = AHertzCNichols

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
	zip -r AHertzCNichols.zip ActorActress.cpp ActorActressDb.cpp Picture.cpp PictureDb.cpp main.cpp ActorActress.h ActorActress.h BST.h Exceptions.h Picture.h PictureDb.h main.h README.txt makefile actor_actress.csv pictures.csv