set(INPUT_SOURCES
   triangle.cpp
   circle.cpp
   rectangle.cpp
   shape.cpp
)

set(INPUT_HEADERS

)

target_sources(${PROJECT_NAME} PRIVATE ${INPUT_SOURCES} ${INPUT_HEADERS})