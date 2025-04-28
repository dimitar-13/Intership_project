set(INPUT_SOURCES
	Application.cpp
)

set(INPUT_HEADERS
	Application.h
	StringHelper.h
)

target_sources(${PROJECT_NAME} PRIVATE ${INPUT_SOURCES} ${INPUT_HEADERS})