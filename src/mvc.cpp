#ifdef _WIN32
    #define SLASH "\\"
#else
    #define SLASH "/"
#endif // _WIN32

#define DEBUG 1


#include "model/model.h"
#include "view/view.h"
#include "controller/controller.h"

#include "model/model.cpp"
#include "view/view.cpp"
#include "controller/controller.cpp"
