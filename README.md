to build for client run:

g++ Paint_client.cpp Paint_dot.cpp Paint_network.cpp -o client.exe -lGLU -lGL -lglut -lpthread -lm

to build for server run:

g++ Paint_server.cpp Paint_dot.cpp Paint_network.cpp -o server.exe -lGLU -lGL -lglut -lpthread -lm

and execute both executible files client.exe and server.exe in different terminals.
