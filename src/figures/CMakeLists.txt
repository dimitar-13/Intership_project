set(INPUT_SOURCES
   triangle.cpp
   circle.cpp
   rectangle.cpp
   shape.cpp
   FigureFactory.cpp
)

set(INPUT_HEADERS
   shape.h
   triangle.h
   circle.h
   rectangle.h
   FigureFactory.h
   figures.h
)

target_sources(${PROJECT_NAME} PRIVATE ${INPUT_SOURCES} ${INPUT_HEADERS})