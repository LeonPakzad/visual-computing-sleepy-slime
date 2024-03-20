#include "logic.command.h"

#include "../data/data.commandAction.h"

namespace Logic 
{
    CCommand::CCommand() 
        : type(Data::SCommandAction::EActions::Undefined) {}

    CCommand::~CCommand() {}

    Data::SCommandAction::EActions CCommand::GetType() const 
    {
        return type;
    }

    void CCommand::SetType(Data::SCommandAction::EActions _Type)
    {
        this->type = _Type;
    }
}