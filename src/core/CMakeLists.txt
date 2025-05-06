set(INPUT_SOURCES
	Application.cpp
	FileHelper.cpp
	StringHelper.cpp
)

set(INPUT_HEADERS
	Application.h
	StringHelper.h
	Prototype.h
	FileHelper.h
)

target_sources(${PROJECT_NAME} PRIVATE ${INPUT_SOURCES} ${INPUT_HEADERS})