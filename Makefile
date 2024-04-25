CC = g++
CFLAGS = -Wall -Wextra -std=c++11
EXECUTABLE = main
SOURCES = main.cpp greedy.cpp swap.cpp realoca.cpp# Adicione o novo arquivo cpp aqui

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(EXECUTABLE)