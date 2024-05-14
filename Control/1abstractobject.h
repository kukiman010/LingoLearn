#ifndef ABSTRACTOBJECT_H
#define ABSTRACTOBJECT_H

#include <QSharedPointer>
#include <QDataStream>
#include <QByteArray>
#include <QList>
#include <QObject>
#include <QMetaObject>
#include <QMetaType>
#include <vector>
#include <map>

class AbstractObject : public QObject
{

public:
    enum ObjectType {
        O_Undefined = 0,
        O_UserInfo
    };

    explicit AbstractObject( QObject * parent = nullptr );
    virtual ~AbstractObject();

    inline const ObjectType &           type() const    { return _type; }

    friend QDataStream & operator<<( QDataStream &stream, AbstractObject * obj );
    friend QDataStream & operator>>( QDataStream &stream, AbstractObject *& obj );

    virtual AbstractObject *            copy() const = 0;

protected:
    virtual void                        fromDataStream( QDataStream &stream ) = 0;
    virtual void                        toDataStream( QDataStream &stream ) const = 0;

    ObjectType                          _type;


};

typedef QList<AbstractObject*>                  ObjectList;
typedef QSharedPointer<AbstractObject>          ObjPtr;
typedef QList< QSharedPointer<AbstractObject> > ObjectPtrList;

Q_DECLARE_METATYPE(QSharedPointer<AbstractObject>)
Q_DECLARE_METATYPE(ObjectList)
Q_DECLARE_METATYPE(AbstractObject::ObjectType)

#endif // ABSTRACTOBJECT_H
