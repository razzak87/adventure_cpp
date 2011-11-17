COMPILER = g++
SOURCES = main.cpp
APP = a.out
OBJECTS = $(SOURCES:.cpp=.o)


all: $(SOURCES) $(APP) 
	
$(APP): $(OBJECTS)
	$(COMPILER) $(OBJECTS) -o $@

clean:
	rm -rf *.o $(APP)

