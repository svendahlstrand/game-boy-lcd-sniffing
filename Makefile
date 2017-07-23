.PHONY: all clean

all: ./bin/ld2img

./bin/ld2img: ./src/ld2img.c
	mkdir -p ./bin
	gcc -Wall -o $@ $^

clean:
	rm -rf ./bin
