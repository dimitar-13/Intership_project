set(INPUT_SOURCES
   triangle.cpp
   circle.cpp
   rectangle.cpp
   shape.cpp
   stream_figure_factory.cpp
   random_figure_factory.cpp
   shape_input_factory.cpp
)

set(INPUT_HEADERS
   shape.h
   triangle.h
   circle.h
   rectangle.h
   stream_figure_factory.h
   random_figure_factory.h
   figures.h
   figure_factory.h
   abstract_factory.h
   shape_input_factory.h
)

target_sources(${PROJECT_NAME} PRIVATE ${INPUT_SOURCES} ${INPUT_HEADERS})