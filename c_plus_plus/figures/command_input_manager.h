#pragma once

//#include <iostream>
#define DIFFERENCE 6

enum Operations {
    EXIT = 0,

    ADD_FIGURE = 1,
    OUTPUT_PARAMS_FIGURE = 2,
    OUTPUT_PERIMETER_FIGURE = 3,
    OUTPUT_SUMMARY_PERIMETER = 4,
    SORT,
    DELETE_BY_NUMBER,
    DELETE_BY_PERIMETER,

    ADD_CIRCLE = 1,
    ADD_RECTANGLE,
    ADD_TRIANGLE,
    ADD_POLYGON
};

class commandInputManager {
public:
    unsigned int GetCommand();
    unsigned int GetCreatingCommand();
};
