// #ifndef ABSTRACTCOMMAND_H
// #define ABSTRACTCOMMAND_H

// // #include <QByteArray>
// // #include <QList>
// // #include <QVariantMap>
// #include <QSharedPointer>
// // #include <QDateTime>
// // #include <set>

// #include "abstractobject.h"

// class AbstractCommand
// {
// public:

//     enum CommandType
//     {
//         C_Undefined = 0,
//         C_Users,
//         C_Message,
//         C_DataBase,
//         C_Common,
//         C_Error,
//         C_Config
//     };

//     enum CommandDestination
//     {
//         DESTINATION_UNKNOWN = 0,
//         CD_Runner,
//         CD_Storage
//     };

//     AbstractCommand();
//     explicit AbstractCommand( const QString &userId );
//     virtual ~AbstractCommand();

//     virtual void                        toDataStream( QDataStream & stream ) const = 0;
//     virtual void                        fromDataStream( QDataStream & stream ) = 0;

//     inline const CommandType &          commandType() const                                     { return _commandType; }

//     inline void                         setDestination( const CommandDestination &dist )        { _commandDestination = dist; }
//     inline const CommandDestination &   destination() const                                     { return _commandDestination; }

//     inline void                         setPriority( const float &priority )                    { _priority = priority; }
//     inline const float &                priority() const                                        { return _priority; }

//     inline int                          objectsCount() const                                    { return _objects.size(); }

//     inline quint64 &                    infoFlag()                                              { return _infoFlag; }

//     inline void                         setUserId( const QString &userId )                      { _userId = userId; }
//     inline const QString &               userId() const                                         { return _userId; }

//     inline void                         addObject( const ObjectList &list )                     { _objects.append( list );   }
//     inline void                         addObject( AbstractObject * const &obj )                { _objects.push_back( obj ); }

//     void                                clearObjectList();
//     inline const ObjectList &           objectList() const                                      { return _objects; }

//     friend QDataStream & operator << ( QDataStream &stream, AbstractCommand *& command );
//     friend QDataStream & operator >> ( QDataStream &stream, AbstractCommand *& command );
//     // friend QDataStream & operator << ( QDataStream &stream, AbstractCommand * command);
//     // friend QDataStream & operator << ( QDataStream &stream, AbstractCommand * command);

// protected:

//     CommandType                         _commandType;
//     CommandDestination                  _commandDestination;

//     ObjectList                          _objects;
//     QString                             _userId;
//     // QString                             _armSender;

//     quint64                             _infoFlag;

//     float                               _priority;
// };




// typedef QSharedPointer<AbstractCommand>                   CmdPtr;
// typedef QList<QSharedPointer<AbstractCommand> >           CmdList;
// typedef QList<QSharedPointer<AbstractCommand> >::iterator CmdIterator;
// typedef std::vector<AbstractCommand*>                     CmdVec;

// Q_DECLARE_METATYPE(QSharedPointer<AbstractCommand>)

// #endif // ABSTRACTCOMMAND_H
