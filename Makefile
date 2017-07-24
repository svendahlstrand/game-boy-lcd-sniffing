.PHONY: all clean

all: ./bin/ld2img

./bin/ld2img: ./src/ld2img.c
	mkdir -p ./bin
	gcc -std=c99 -Wall -Wextra -Wpedantic -Werror -o $@ $^

clean:
	rm -rf ./bin
