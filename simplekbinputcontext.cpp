#include "simplekbinputcontext.h"
#include <QDebug>
#include <QGuiApplication>
#include <QQuickView>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQuickItem>
#include <QLibraryInfo>
#include <QQmlEngine>
#include <QKeyEvent>

SimpleKBInputContext::SimpleKBInputContext() : QPlatformInputContext()
  , keyboard(0)
{
    qDebug()<<Q_FUNC_INFO;
}

SimpleKBInputContext::~SimpleKBInputContext()
{
}

bool SimpleKBInputContext::isValid() const
{
    qDebug()<<Q_FUNC_INFO;
    return true;
}

bool SimpleKBInputContext::hasCapability(QPlatformInputContext::Capability capability) const
{
    qDebug()<<Q_FUNC_INFO;
    if(capability == QPlatformInputContext::HiddenTextCapability)
        return true;

    return false;
}

void SimpleKBInputContext::showInputPanel()
{
    qDebug()<<Q_FUNC_INFO;
    if( !keyboard )
        createKeyboard();
    if(keyboard && !keyboard->isVisible()) {
        qDebug()<<"keyboard not visible!";
        keyboard->setVisible(true);
    }
}

void SimpleKBInputContext::hideInputPanel()
{
    qDebug()<<Q_FUNC_INFO;
    if(keyboard)
        keyboard->setVisible(false);
}

bool SimpleKBInputContext::isInputPanelVisible() const
{
    if(keyboard) {
        bool returnValue = keyboard->isVisible();
        qDebug()<< Q_FUNC_INFO << "Return" << returnValue << "from keyboard.";
        return returnValue;
    }
    qDebug() << Q_FUNC_INFO << "Return false";
    return false;
}

void SimpleKBInputContext::createKeyboard()
{
    qDebug()<<Q_FUNC_INFO;
    if(keyboard)
        return;

    QWindowList list = QGuiApplication::allWindows();
    QQuickView* view = 0;
    QQmlEngine *engine = 0;
    QQuickWindow *quickWindow = 0;

    foreach (QWindow *win, list) {
        view = qobject_cast<QQuickView*>(win);
        quickWindow = qobject_cast<QQuickWindow*>(win);
        if (!view)
            engine = qmlEngine(win);
        if(view || engine) break;
    }
    QQmlContext *root = engine ? engine->rootContext() : (view? view->rootContext() : 0);
    if (!root) {
      qWarning("No Root Context");
     return;
   }
   if (view && !engine)
       engine = view->engine();
    root->setContextProperty("Keyboard", this);

    QQmlComponent component(engine, QUrl(QStringLiteral("qrc:/qml/KeyboardContainer.qml")));
    if(component.isError()) {
        qDebug()<<"Error while creating Keyboard component:"<<component.errorString();
        return;
    }
    QObject *obj = component.create();
    QObject::connect(obj, SIGNAL(keyPressed(QString)),
                     this, SLOT(keyboardKeypress(QString)));
    QObject::connect(obj, SIGNAL(keyReleased(QString)),
                     this, SLOT(keyboardKeyrelease(QString)));
    QObject::connect(obj, SIGNAL(functionkeyPressed(int, QString)),
                     this, SLOT(keyboardFunctionkeypress(int, QString)));
    QObject::connect(obj, SIGNAL(functionkeyReleased(int, QString)),
                     this, SLOT(keyboardFunctionkeyrelease(int, QString)));
    QQuickItem* kbItem = qobject_cast<QQuickItem*>(obj);
    Q_ASSERT(kbItem);
    keyboard = kbItem;

    if (view)
        keyboard->setParentItem(view->rootObject());
    else if (quickWindow)
        keyboard->setParentItem(quickWindow->contentItem());
}

void SimpleKBInputContext::keyboardKeypress(QString keyString)
{
    QKeyEvent* eventToSend = new QKeyEvent(QEvent::KeyPress, Qt::Key_unknown, Qt::NoModifier, keyString);
    sendKeyEvent(eventToSend);
}

void SimpleKBInputContext::keyboardKeyrelease(QString keyString)
{
    QKeyEvent* eventToSend = new QKeyEvent(QEvent::KeyRelease, Qt::Key_unknown, Qt::NoModifier, keyString);
    sendKeyEvent(eventToSend);
}

void SimpleKBInputContext::keyboardFunctionkeypress(int keyCode, QString keyString)
{
    QKeyEvent* eventToSend = new QKeyEvent(QEvent::KeyPress, (Qt::Key)keyCode, Qt::NoModifier, keyString);
    sendKeyEvent(eventToSend);
}

void SimpleKBInputContext::keyboardFunctionkeyrelease(int keyCode, QString keyString)
{
    QKeyEvent* eventToSend = new QKeyEvent(QEvent::KeyRelease, (Qt::Key)keyCode, Qt::NoModifier, keyString);
    sendKeyEvent(eventToSend);
}

void SimpleKBInputContext::sendKeyEvent(QKeyEvent* event)
{
    qDebug() << Q_FUNC_INFO << "key:" << event->key() << "text:" << event->text();
    QGuiApplication* guiApp = qobject_cast<QGuiApplication*>(QCoreApplication::instance());
    QWindow *focusWindow = guiApp ? guiApp->focusWindow() : 0;
    if (focusWindow) {
        qDebug()<<Q_FUNC_INFO<<"Send window";
        QGuiApplication::sendEvent(focusWindow, event);
    }
    else
    {
        qDebug()<<Q_FUNC_INFO<<"Send obj";
        QCoreApplication::sendEvent(guiApp->focusObject(), event);
    }
}
