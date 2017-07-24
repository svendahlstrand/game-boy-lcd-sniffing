BIN_DIR=./bin
BINARY=$(BIN_DIR)/ld2img
SRC_FILE=./src/ld2img.c

.PHONY: all clean

all: $(BINARY)

$(BINARY): $(SRC_FILE)
	mkdir -p $(BIN_DIR)
	gcc -std=c99 -Wall -Wextra -Wpedantic -Werror -o $@ $^

clean:
	rm -rf $(BIN_DIR)
