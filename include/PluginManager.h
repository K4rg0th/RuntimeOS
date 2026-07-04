#ifndef PLUGIN_MANAGER_H
#define PLUGIN_MANAGER_H

class PluginManager {
public:
    PluginManager();
    virtual ~PluginManager();
    
    void init();
    void loop();
};

#endif // PLUGIN_MANAGER_H