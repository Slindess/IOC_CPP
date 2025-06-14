cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME injecto_plus)
set(SRC_DIR src)

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Собираем исполняемый файл из всех cpp в src
set(SOURCES
        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/Tree/Tree.cpp ${SRC_DIR}/Tree/Tree.h
        ${SRC_DIR}/FilesParser/FilesParser.cpp ${SRC_DIR}/FilesParser/FilesParser.h
        )

add_executable(${PROJECT_NAME} ${SOURCES})

# (Опционально) include директории, если есть
target_include_directories(${PROJECT_NAME} PRIVATE ${SRC_DIR})

# (Опционально) предупреждения компилятора
# target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
