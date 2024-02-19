#include "abstractcommand.h"

AbstractCommand::AbstractCommand()
{
    _userId = 0;
    _commandType = C_Undefined;
    _commandDestination = DESTINATION_UNKNOWN;
    _infoFlag = 0;
    _priority = 0.0f;
    qRegisterMetaType< CmdPtr >( "CmdPtr" );
    qRegisterMetaType< QSharedPointer<AbstractCommand> >("QSharedPointer<AbstractCommand>");
}

AbstractCommand::AbstractCommand( const QString &userId )
{
    _userId = userId;
    _commandType = C_Undefined;
    _commandDestination = DESTINATION_UNKNOWN;
    _infoFlag = 0;
    _priority = 0.0f;
    qRegisterMetaType< CmdPtr >( "CmdPtr" );
    qRegisterMetaType< QSharedPointer<AbstractCommand> >("QSharedPointer<AbstractCommand>");

}

AbstractCommand::~AbstractCommand()
{
    clearObjectList();
}

void AbstractCommand::clearObjectList()
{
    qDeleteAll( _objects );
    _objects.clear();
}

// QDataStream & operator >>(QDataStream &stream, AbstractCommand *&command)
// {
    // if ( command )
    //     delete command;

    // int type, size, destination;
    // float priority;
    // quint64 infoFlag;
    // QString userId;

    // stream >> type >> destination >> size >> userId >> infoFlag >> priority;

    // // IFactory * factory = IFactory::factory( CommandFactoryId );

    // // Factory<AbstractCommand> * fC = dynamic_cast<Factory<AbstractCommand>*>( factory );

    // // if ( !fC )
    // //     return stream;

    // // command = fC->create( type );

    // if ( !command )
    //     return stream;

    // // command->setUserId( userId );
    // // command->setDestination( static_cast<AbstractCommand::CommandDestination>( destination ) );
    // // command->_infoFlag = infoFlag;
    // // command->_priority = priority;

    // // command->fromDataStream( stream );

    // // for ( int i(0); i < size; ++i )
    // // {
    // //     AbstractObject * obj = NULL;
    // //     stream >> obj;
    // //     command->_objects.push_back( obj );
    // // }

//     return stream;
// }

// QDataStream & operator << ( QDataStream &stream, AbstractCommand *& command )
// {
    // stream << static_cast<int>( command->_commandType );
    // stream << static_cast<int>( command->_commandDestination );
    // stream << static_cast<int>( command->_objects.size() );
    // stream << static_cast<QString>( command->userId() );
    // stream << command->_infoFlag;
    // stream << command->_priority;

    // command->toDataStream( stream );

    // ObjectList::const_iterator it = command->_objects.constBegin();

    // int i = 1;

    // for ( ; it != command->_objects.constEnd(); ++it )
    // {
    //     stream << (*it);
    //     ++i;
    // }

//     return stream;
// }

