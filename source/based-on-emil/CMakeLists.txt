
add_executable(based-on-emil)

target_link_libraries(based-on-emil PRIVATE
    infra.util
    infra.stream
)

target_sources(based-on-emil PRIVATE
    main.cpp
)
