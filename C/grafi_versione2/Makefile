CC = gcc
CFLAGS = -Wall -Wextra

# Elenco dei file sorgente
SRCS = main.c graph.c

# Elenco dei file oggetto generati dalla compilazione
OBJS = $(SRCS:.c=.o)

# Nome dell'eseguibile
TARGET = myprogram

# Regola principale per la compilazione dell'eseguibile
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regole per la compilazione dei file oggetto
main.o: main.c graph.h
	$(CC) $(CFLAGS) -c main.c -o main.o

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) -c graph.c -o graph.o

# Pulisce i file oggetto e l'eseguibile
clean:
	rm -f $(OBJS) $(TARGET)
