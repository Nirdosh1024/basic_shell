# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -pedantic -std=c11 -Iheaders/

# Source files (explicitly include main.c)
SRCDIR = src
HEADERSDIR = headers
OBJDIR = obj
BINDIR = bin

# Include main.c (outside src) explicitly
SRCS = $(wildcard $(SRCDIR)/*.c) main.c
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Output binary name
TARGET = $(BINDIR)/shell

# Default rule: Compile everything
all: $(TARGET)

# Compile the executable
$(TARGET): $(OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create necessary directories if they don’t exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# Clean the build
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Run the program
run: all
	./$(TARGET)
