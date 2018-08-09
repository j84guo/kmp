all: bin/kmp

bin/kmp: 
	mkdir -p bin
	clang++ -o bin/kmp src/main.cpp src/filesystem.cpp src/kmp.cpp -I src

clean:
	rm -rf bin
