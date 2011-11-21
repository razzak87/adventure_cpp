COMPILER = g++
SOURCES =  Node.cpp Player.cpp Parser.cpp main.cpp 
APP = output/advent
OBJECTS = $(SOURCES:.cpp=.o)


all: $(SOURCES) $(APP) 
	
$(APP): $(OBJECTS)
	$(COMPILER) $(OBJECTS) -o $@

clean:
	rm -rf *.o $(APP)

