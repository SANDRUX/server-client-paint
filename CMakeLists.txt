cmake_minimum_required(VERSION 3.5)

project(GL_STUFF LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(GL_STUFF Paint_client.cpp  Paint_dot.cpp  Paint_dot.h  Paint_network.cpp  Paint_network.h  Paint_server.cpp)
target_link_libraries(${PROJECT_NAME} -lGLU -lGL -lglut -lpthread -lm)
