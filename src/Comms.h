//
// Created by Michal on 10. 4. 2023.
//

#ifndef MODBOT_LIBRARY_COMMS_H
#define MODBOT_LIBRARY_COMMS_H

#include "arduino.h"
#include "Module.h"
#include <Wire.h>

struct command {
    String name = "";
    String desc = "";
    int type = 0;
    bool (*cmd1)();
    int (*cmd2)();
    bool (*cmd3)(int);
    int (*cmd4)(int);
    int (*cmd5)(float, float, float);
};

class Comms: public Module{
public:
    Comms(int sampleRate = 9600, int clocFreq = 100000, int maxCommands = 2);
    void beginSerial();
    void beginWire(int address);
    void serialListen();
    void serialWrite(String text);
    void setSampleRate(int sr);
    void setClockFreq(int cf);
    bool addCommand(command cmd);

protected:
    command* _commands;
    int _cmdNum;
    int _sampleRate;
    int _clockFreq;

private:
    void growArray();
    int findCmd(String cmd);
    void serialHelp();
    void receiveEvent();
    int _maxCommands;
};

#endif //MODBOT_LIBRARY_COMMS_H
