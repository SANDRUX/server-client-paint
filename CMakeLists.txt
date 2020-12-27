cmake_minimum_required(VERSION 3.5)

project(GL_STUFF LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(GL_STUFF main.cpp Dot.cpp Dot.h)
target_link_libraries(${PROJECT_NAME} -lGLU -lGL -lglut -lpthread -lm)
