#ifndef POWER_MANAGER_H
#define POWER_MANAGER_H

class PowerManager {
public:
    PowerManager();
    virtual ~PowerManager();
    
    void init();
    void loop();
};

#endif // POWER_MANAGER_H