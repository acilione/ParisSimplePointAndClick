TARGET = ciccio_parigi
SRC = $(TARGET).c
INCLUDE_DIR = raylib/src/.
LIB_DIR = raylib/src/.
LIBS = -lraylib -lm -lpthread -ldl

CC = gcc
CFLAGS = -I$(INCLUDE_DIR) -L$(LIB_DIR) $(LIBS)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o $(TARGET)

clean:
	rm -f $(TARGET)

