#ifndef REPLACEMENTSOLUTIONINPUTCONTEXT_H
#define REPLACEMENTSOLUTIONINPUTCONTEXT_H

#include <qpa/qplatforminputcontext.h>
#include <QQuickItem>

class SimpleKBInputContext : public QPlatformInputContext
{
    Q_OBJECT

public:
    SimpleKBInputContext();
    ~SimpleKBInputContext();

    virtual bool isValid() const;
    virtual bool hasCapability(Capability capability) const;

    virtual void showInputPanel();
    virtual void hideInputPanel();
    virtual bool isInputPanelVisible() const;

public slots:
    void keyboardKeypress(QString keyString);
    void keyboardKeyrelease(QString keyString);
    void keyboardFunctionkeypress(int keyCode, QString keyString);
    void keyboardFunctionkeyrelease(int keyCode, QString keyString);

private:
    void createKeyboard();
    void sendKeyEvent(QKeyEvent* event);
    QQuickItem* keyboard;
};

#endif // REPLACEMENTSOLUTIONINPUTCONTEXT_H
