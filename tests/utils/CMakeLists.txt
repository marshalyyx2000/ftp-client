add_executable(utils_tests
        utils_tests.cpp)

target_link_libraries(utils_tests
        PRIVATE
            utils
            gtest_main)

target_include_directories(utils_tests
        PRIVATE
            ../../src/utils)