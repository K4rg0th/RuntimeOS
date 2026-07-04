#ifndef STORAGE_MANAGER_H
#define STORAGE_MANAGER_H

class StorageManager {
public:
    StorageManager();
    virtual ~StorageManager();
    
    void init();
    void loop();
};

#endif // STORAGE_MANAGER_H