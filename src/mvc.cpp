#ifdef _WIN32
    #define SLASH "\\"
#else
    #define SLASH "/"
#endif // _WIN32

#define DEBUG 0

#define WAIT getchar()

#include "data.h"

#include "model/model.h"
#include "view/view.h"
#include "controller/controller.h"

#include "model/model.cpp"
#include "view/view.cpp"
#include "controller/controller.cpp"
