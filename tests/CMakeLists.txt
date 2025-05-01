set(INPUT_SOURCES
circle_tests.cpp
triangle_tests.cpp
rectangle_tests.cpp
string_helper_tests.cpp
figure_factory_tests.cpp
)

set(INPUT_HEADERS

)

target_sources(${PROJECT_NAME} PRIVATE ${INPUT_SOURCES} ${INPUT_HEADERS})