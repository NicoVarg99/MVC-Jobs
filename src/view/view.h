#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

class view{
public:
    void view_controller_start();
    int view_mainMenu();
    void view_printError(const std::string topr);
    void view_printDebug(const std::string dastampare);
    void view_printMsg(char *topr);
    void wiew_printWaitMessage();

};

#endif // VIEW_H_INCLUDED
