#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

// #include <QByteArray>
// #include <QList>
// #include <QVariantMap>
#include <QSharedPointer>
// #include <QDateTime>
// #include <set>

#include "abstractobject.h"

class AbstractCommand
{
public:

    enum CommandType
    {
        C_Undefined = 0,
        C_Users,
        C_Message,
        C_DataBase,
        C_Common,
        C_Error,
        C_Config
    };

    enum CommandDestination
    {
        DESTINATION_UNKNOWN = 0,
        CD_Runner,
        CD_Storage
    };

    AbstractCommand();
    explicit AbstractCommand( const QString &userId );
    virtual ~AbstractCommand();

    virtual void                        toDataStream( QDataStream & stream ) const = 0;
    virtual void                        fromDataStream( QDataStream & stream ) = 0;

    inline const CommandType &          commandType() const                                     { return _commandType; }

    inline void                         setDestination( const CommandDestination &dist )        { _commandDestination = dist; }
    inline const CommandDestination &   destination() const                                     { return _commandDestination; }

    inline void                         setPriority( const float &priority )                    { _priority = priority; }
    inline const float &                priority() const                                        { return _priority; }

    inline int                          objectsCount() const                                    { return _objects.size(); }

    inline quint64 &                    infoFlag()                                              { return _infoFlag; }

    inline void                         setUserId( const QString &userId )                      { _userId = userId; }
    inline const QString &               userId() const                                         { return _userId; }

    inline void                         addObject( const ObjectList &list )                     { _objects.append( list );   }
    inline void                         addObject( AbstractObject * const &obj )                { _objects.push_back( obj ); }

    void                                clearObjectList();
    inline const ObjectList &           objectList() const                                      { return _objects; }

    friend QDataStream & operator >> ( QDataStream &stream, AbstractCommand *& command )
    {
        if ( command )
            delete command;

        int type, size, destination;
        float priority;
        quint64 infoFlag;
        QString userId;

        stream >> type >> destination >> size >> userId >> infoFlag >> priority;

        // IFactory * factory = IFactory::factory( CommandFactoryId );

        // Factory<AbstractCommand> * fC = dynamic_cast<Factory<AbstractCommand>*>( factory );

        // if ( !fC )
        //     return stream;

        // command = fC->create( type );

        if ( !command )
            return stream;

        // command->setUserId( userId );
        // command->setDestination( static_cast<AbstractCommand::CommandDestination>( destination ) );
        // command->_infoFlag = infoFlag;
        // command->_priority = priority;

        // command->fromDataStream( stream );

        // for ( int i(0); i < size; ++i )
        // {
        //     AbstractObject * obj = NULL;
        //     stream >> obj;
        //     command->_objects.push_back( obj );
        // }
        return stream;
    }
    friend QDataStream & operator << ( QDataStream &stream, AbstractCommand *& command )
    {
        stream << static_cast<int>( command->_commandType );
        stream << static_cast<int>( command->_commandDestination );
        stream << static_cast<int>( command->_objects.size() );
        stream << static_cast<QString>( command->userId() );
        stream << command->_infoFlag;
        stream << command->_priority;

        command->toDataStream( stream );

        ObjectList::const_iterator it = command->_objects.constBegin();

        // int i = 1;
        for ( ; it != command->_objects.constEnd(); ++it )
        {
            stream << (*it);
            // ++i;
        }

        return stream;
    }

protected:

    CommandType                         _commandType;
    CommandDestination                  _commandDestination;

    ObjectList                          _objects;
    QString                             _userId;
    // QString                             _armSender;

    quint64                             _infoFlag;

    float                               _priority;
};




typedef QSharedPointer<AbstractCommand>                   CmdPtr;
typedef QList<QSharedPointer<AbstractCommand> >           CmdList;
typedef QList<QSharedPointer<AbstractCommand> >::iterator CmdIterator;
typedef std::vector<AbstractCommand*>                     CmdVec;

Q_DECLARE_METATYPE(QSharedPointer<AbstractCommand>)

#endif // ABSTRACTCOMMAND_H
