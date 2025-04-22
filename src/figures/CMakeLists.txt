set(INPUT_SOURCES
   triangle.cpp
   circle.cpp
   rectangle.cpp
   shape.cpp
)

set(INPUT_HEADERS
   shape.h
   triangle.h
   circle.h
   rectangle.h
)

target_sources(${PROJECT_NAME} PRIVATE ${INPUT_SOURCES} ${INPUT_HEADERS})