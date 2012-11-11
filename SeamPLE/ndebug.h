//@Riandy A0088392
//This is used to assert error message. Compared to the normal assert
//this will provide more details such as filename, line that causes this assert and message.
#ifndef NDEBUG
    # define ASSERT(condition, message) \
    do { \
        if (! (condition)) { \
        std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
        << " line " << __LINE__ << ": " << message << std::endl; \
        std::exit(EXIT_FAILURE); \
        } \
    } while (false)
    #else
    # define ASSERT(condition, message) do { } while (false)
#endif

