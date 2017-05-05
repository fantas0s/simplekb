#ifndef REPLACEMENTSOLUTIONKEYBOARDPLUGIN_H
#define REPLACEMENTSOLUTIONKEYBOARDPLUGIN_H

#include <QObject>
#include <qpa/qplatforminputcontextplugin_p.h>
#include <qpa/qplatforminputcontext.h>
#include <QStringList>
#include "simplekbinputcontext.h"

class SimpleKBPlugin : public QPlatformInputContextPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QPlatformInputContextFactoryInterface_iid FILE "SimpleKB.json")

public:
    explicit SimpleKBPlugin(QObject *parent = 0);
    ~SimpleKBPlugin();

    QStringList keys() const;
    QPlatformInputContext *create(const QString &key, const QStringList &paramList);
signals:

public slots:
private:
    SimpleKBInputContext* ic;
};

#endif // REPLACEMENTSOLUTIONKEYBOARDPLUGIN_H
