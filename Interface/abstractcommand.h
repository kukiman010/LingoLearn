#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

#include <QByteArray>
#include <QList>
#include <QVariantMap>
#include <QSharedPointer>
#include <QDateTime>
#include <set>

#include "abstractobject.h"
#include "scenarioid.h"

class AbstractCommand
{
public:

    enum CommandType {
            C_Undefined = 0,
            C_Users = 1,
            C_DataBase,
            C_Scenario
    };

    enum CommandDestination {
            DESTINATION_UNKNOWN = 0,
            CD_Storage
    };

    AbstractCommand();
    explicit AbstractCommand( QString userId );
    explicit AbstractCommand( const AbstractCommand &other );
    virtual ~AbstractCommand();

    virtual void                        toDataStream( QDataStream & stream ) const = 0;
    virtual void                        fromDataStream( QDataStream & stream ) = 0;

    virtual CommandType                 commandType() const = 0;
    virtual AbstractCommand*            copy() const = 0;
    inline quint64 &                    infoFlag()                                              { return _infoFlag; }

    inline void                         setDestination( const CommandDestination &dist )        { _commandDestination = dist; }
    inline const CommandDestination &   destination() const                                  { return _commandDestination; }

    inline void                         setPriority( const float &priority )                    { _priority = priority; }
    inline float                        priority() const                                        { return _priority; }

    inline void                         setUserId( const QString &userId )                      { _userId = userId; }
    inline const QString &              userId() const                                          { return _userId; }

    inline bool                         isFinished() const                                      { return _finished; }
    inline void                         setFinished(bool value)                                 { _finished = value; }

    const ScenarioID&                   scenarionID() const                                     { return  _scenarionID; }
    void                                setScenarioID( ScenarioID value )                       { _scenarionID = value; }

    inline void                         addObject( const ObjectList &list )                     { _objects.append( list );   }
    inline void                         addObject( AbstractObject * const &obj )                { _objects.push_back( obj ); }

    inline int                          objectsCount() const                                    { return _objects.size(); }
    void                                clearObjectList();
    inline const ObjectList &           objectList() const                                      { return _objects; }

    friend QDataStream & operator       <<( QDataStream &stream, AbstractCommand *& command );
    friend QDataStream &operator        >>( QDataStream &stream, AbstractCommand *& command );

protected:
    CommandDestination                  _commandDestination;
    ScenarioID                          _scenarionID;

    QString                             _userId;
    quint64                             _infoFlag;
    float                               _priority;
    ObjectList                          _objects;
    bool                                _finished;
};


typedef QSharedPointer<AbstractCommand>                   CmdPtr;
typedef QList<QSharedPointer<AbstractCommand> >           CmdList;

Q_DECLARE_METATYPE(QSharedPointer<AbstractCommand>)

#endif // ABSTRACTCOMMAND_H
