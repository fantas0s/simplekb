#include "simplekbplugin.h"
#include "simplekbinputcontext.h"
#include <QDebug>

SimpleKBPlugin::SimpleKBPlugin(QObject *parent) : QPlatformInputContextPlugin(parent)
  ,ic(0)
{
    qDebug()<<Q_FUNC_INFO;
}

SimpleKBPlugin::~SimpleKBPlugin()
{
}

QStringList SimpleKBPlugin::keys() const
{
    qDebug()<<Q_FUNC_INFO;
    return QStringList(QStringLiteral("SimpleKB"));
}

QPlatformInputContext* SimpleKBPlugin::create(const QString &key, const QStringList &paramList)
{
    qDebug()<<Q_FUNC_INFO;
    Q_UNUSED(paramList)
    if(key.compare("SimpleKB", Qt::CaseInsensitive) == 0) {
        if(!ic)
            ic = new SimpleKBInputContext();
        return ic;
    }

    return 0;
}
