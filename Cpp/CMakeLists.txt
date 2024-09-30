aux_source_directory(source FILTER_DIR)
add_library(FilterCpp STATIC ${FILTER_DIR})
target_include_directories(FilterCpp PUBLIC include)
target_compile_options(FilterCpp PUBLIC -Wa,-mbig-obj -O2)