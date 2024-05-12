#include "abstractobject.h"


AbstractObject::AbstractObject(QObject *parent) : QObject (parent)
{
    qRegisterMetaType< QSharedPointer<AbstractObject> >( "QSharedPointer<AbstractObject>" );
    qRegisterMetaType< ObjPtr >( "ObjPtr" );
    qRegisterMetaType< ObjectList >( "ObjectList" );
    qRegisterMetaType< AbstractObject::ObjectType >( "ObjectType" );
}

AbstractObject::~AbstractObject() {}

QDataStream &operator<<(QDataStream &stream, AbstractObject *obj)
{
    if ( !obj )
        return stream;

    int type = static_cast<int>( obj->_type );
    stream << type;

    obj->toDataStream( stream );
    return stream;
}

QDataStream &operator>>(QDataStream &stream, AbstractObject *&obj)
{
    if ( obj )
        delete obj;

    // Factory<AbstractObject> * fObj = dynamic_cast<Factory<AbstractObject>*>
    //     (
    //         IFactory::factory( ObjectFactoryId )
    //         );

    // if ( !fObj )
    //     return stream;

    int type;
    stream >> type;

    // obj = fObj->create( type );

    // if ( !obj )
    //     return stream;

    // obj->fromDataStream( stream );

    return stream;
}
