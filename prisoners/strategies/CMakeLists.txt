add_library(strategies GameStrategy.h AlwaysVoteCGameStrategy.h AlwaysVoteCGameStrategy.cpp)

target_link_libraries(strategies PUBLIC game_matrix)
target_include_directories(strategies PUBLIC ../game_matrix)
