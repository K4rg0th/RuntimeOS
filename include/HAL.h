#ifndef HAL_H
#define HAL_H

class HAL {
public:
    HAL();
    virtual ~HAL();
    
    void init();
    void loop();
};

#endif // HAL_H