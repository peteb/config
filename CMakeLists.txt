cmake_minimum_required(VERSION 2.6)

project(config)

set(SOURCES
	source/propertynode.cpp
	source/propertytreeparser.cpp
	source/propertytreeprinter.cpp
	source/simpletokenizer.cpp
)

add_library(config
	${SOURCES}
)

add_executable(test source/test.cpp)
target_link_libraries(test config)

