# Include the headers
INCLUDE_DIRECTORIES(${Prono_SOURCE_DIR}/includes/BE)

# Create the BE library
ADD_LIBRARY(BE_LIB
    ${BE_HEADERS}
    BE/Equipe.cpp
    BE/Ligue1.cpp
    BE/Match.cpp)

# Create the executable
ADD_EXECUTABLE(Prono main.cpp)

# Link the executable to the libraries
TARGET_LINK_LIBRARIES(Prono BE_LIB)
