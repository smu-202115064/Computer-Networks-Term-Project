all: client server

init:
	if ! [ -d "bin" ]; then
		mkdir bin
	fi

client: src/client.c
	gcc src/client.c -o bin/client

server: src/server.c
	gcc src/server.c -o bin/server

run-server:
	bin/server

run-client:
	echo "Hello\nComputer\nNetworks\nc\nc\nGoodBye!!\nc\nq\n" | bin/client

clear:
