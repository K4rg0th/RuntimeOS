#ifndef WEB_UI_H
#define WEB_UI_H

class WebUI {
public:
    WebUI();
    virtual ~WebUI();
    
    void init();
    void init(const char* dir, const char** files);
    void loop();
    const char* getDashboardHtml();
};

#endif // WEB_UI_H
