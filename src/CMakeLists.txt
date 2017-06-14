# Include the headers
INCLUDE_DIRECTORIES(${Prono_SOURCE_DIR}/includes/BE)

# Create the BE library
ADD_LIBRARY(BE_LIB
    ${BE_HEADERS}
    BE/Team.cpp
    BE/League.cpp
    BE/Match.cpp
    BE/Prono.cpp)

# Create the executable
ADD_EXECUTABLE(Prono main.cpp)

# Link the executable to the libraries
TARGET_LINK_LIBRARIES(Prono ${Qt5Widgets_LIBRARIES} BE_LIB)
