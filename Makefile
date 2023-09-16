CC = g++
CFLAGS += -DNDEBUG
SFMLFLAGS += -lsfml-graphics -lsfml-window -lsfml-system
OBJDIR = obj/
SRCDIR = src/

all: raycast

raycast: obj/raycast.o obj/vec.o obj/coordsys.o obj/shapes.o obj/raytracing.o
	$(CC) -o raycast obj/raycast.o obj/vec.o obj/coordsys.o obj/shapes.o obj/raytracing.o $(SFMLFLAGS)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm obj/*.o -f
	clear
	
.PHONY: clean